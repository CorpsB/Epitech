/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** BVH
*/

#include "../../include/rendering/BVH.hpp"

RayTracer::AABB::AABB() = default;

RayTracer::AABB::AABB(const Math::Point3D& a, const Math::Point3D& b)
    : min(a), max(b) {}


/**
 * Fast ray–box intersection.
 *
 * Uses the branch-less algorithm described in Williams et al. (2005).
 * The caller provides the inverse ray direction (`invDir`) and a sign
 * array (`dirNeg`) telling whether each component is negative.
 *
 * @param orig    Ray origin.
 * @param invDir  1 / direction components (size 3).
 * @param dirNeg  0 if dir >= 0, 1 if dir < 0 (size 3).
 * @param tmin    [in/out] lower bound of the valid t-interval.
 * @param tmax    [in/out] upper bound of the valid t-interval.
 * @return        *true* if the ray hits the box.
*/
bool RayTracer::AABB::hitFast(const Math::Point3D &orig, const Float invDir[3], const int dirNeg[3], Float &tmin, Float &tmax) const
{
    Float t0 = ((dirNeg[0] ? max.x : min.x) - orig.x) * invDir[0];
    Float t1 = ((dirNeg[0] ? min.x : max.x) - orig.x) * invDir[0];
    tmin = t0 > tmin ? t0 : tmin;
    tmax = t1 < tmax ? t1 : tmax;
    if (tmax <= tmin) return false;

    t0 = ((dirNeg[1] ? max.y : min.y) - orig.y) * invDir[1];
    t1 = ((dirNeg[1] ? min.y : max.y) - orig.y) * invDir[1];
    tmin = t0 > tmin ? t0 : tmin;
    tmax = t1 < tmax ? t1 : tmax;
    if (tmax <= tmin) return false;

    t0 = ((dirNeg[2] ? max.z : min.z) - orig.z) * invDir[2];
    t1 = ((dirNeg[2] ? min.z : max.z) - orig.z) * invDir[2];
    tmin = t0 > tmin ? t0 : tmin;
    tmax = t1 < tmax ? t1 : tmax;
    return tmax > tmin;
}

/**
 * Returns the minimal AABB that encloses two boxes.
 * @param a First box.
 * @param b Second box.
 * @return  Union box.
*/
RayTracer::AABB RayTracer::surrounding_box(const AABB &a, const AABB &b)
{
    Math::Point3D small{
        std::min(a.min.x, b.min.x),
        std::min(a.min.y, b.min.y),
        std::min(a.min.z, b.min.z)
    };
    Math::Point3D big{
        std::max(a.max.x, b.max.x),
        std::max(a.max.y, b.max.y),
        std::max(a.max.z, b.max.z)
    };
    return AABB(small, big);
}


/**
 * Builds a BVH subtree from a list of primitives.
 * Objects are sorted along a random axis and split in half until the
 * leaf size is small enough (see implementation for the threshold).
 * @param objs List of primitive pointers to insert.
*/
RayTracer::BVHNode::BVHNode(std::vector<const APrimitive*>& objs) {
    if (objs.empty()) return;
    constexpr Float kBoxEps = 1e-4;
    box = objs[0]->bounds();
    box.min.x -= kBoxEps; box.min.y -= kBoxEps; box.min.z -= kBoxEps;
    box.max.x += kBoxEps; box.max.y += kBoxEps; box.max.z += kBoxEps;
    for (size_t i = 1; i < objs.size(); ++i)
        box = surrounding_box(box, objs[i]->bounds());

    if (objs.size() <= 2) {
        objects = objs;
    } else {
        Math::Vector3D span = box.max - box.min;
        int axis = (span.x > span.y && span.x > span.z) ? 0
                 : (span.y > span.z ? 1 : 2);

        std::sort(objs.begin(), objs.end(), [&](const APrimitive* a, const APrimitive* b) {
            auto ba = a->bounds(), bb = b->bounds();
            Float va = (axis == 0 ? ba.min.x : axis == 1 ? ba.min.y : ba.min.z);
            Float vb = (axis == 0 ? bb.min.x : axis == 1 ? bb.min.y : bb.min.z);
            return va < vb;
        });

        auto mid = objs.begin() + objs.size() / 2;
        std::vector<const APrimitive*> left_objs(objs.begin(), mid);
        std::vector<const APrimitive*> right_objs(mid, objs.end());

        left  = std::make_unique<BVHNode>(left_objs);
        right = std::make_unique<BVHNode>(right_objs);
    }
}

/**
 * Ray–BVH intersection.
 * @param ray  Incoming ray in world space.
 * @param t    [in/out] closest distance found so far.
 * @param rec  [out] hit description if any primitive is hit.
 * @return     *true* if the ray hits at least one primitive below.
*/
bool RayTracer::BVHNode::hit(const Ray &ray, Float &t, HitRecord &rec) const {
    constexpr Float kEpsilon = 1e-6;
    bool hit_any = false;
    HitRecord bestRec;
    Float closest = t;

    Float invDir[3] = {
        1.0 / ray.direction.x,
        1.0 / ray.direction.y,
        1.0 / ray.direction.z
    };
    int dirNeg[3] = { invDir[0] < 0, invDir[1] < 0, invDir[2] < 0 };

    const BVHNode* stack[64];
    int sp = 0;
    stack[sp++] = this;

    while (sp) {
        const BVHNode* node = stack[--sp];
        Float tmin = kEpsilon, tmax = closest;
        if (!node->box.hitFast(ray.origin, invDir, dirNeg, tmin, tmax))
            continue;

        if (node->left || node->right) {
            if (node->left)  stack[sp++] = node->left.get();
            if (node->right) stack[sp++] = node->right.get();
        } else {
            for (const APrimitive* o : node->objects) {
                Float tObj;
                HitRecord tmp;
                if (o->hits(ray, tObj, tmp) && tObj < closest) {
                    hit_any = true;
                    closest = tObj;
                    bestRec = tmp;
                    bestRec.t = tObj;
                }
            }
        }
    }

    if (hit_any) {
        t = closest;
        rec = bestRec;
    }
    return hit_any;
}

/**
 * Builds a full BVH tree from the scene primitives.
 * @param objs Vector of primitive pointers.
 * @return     Unique pointer to the root node.
*/
std::unique_ptr<RayTracer::BVHNode> RayTracer::buildBVH(std::vector<const APrimitive*> objs) {
    return std::make_unique<BVHNode>(objs);
}
