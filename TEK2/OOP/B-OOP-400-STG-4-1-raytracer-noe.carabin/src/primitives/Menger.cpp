/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Menger.cpp
*/

#include "../../include/primitives/Menger.hpp"

RayTracer::Menger::Menger(const Math::Point3D& center, double size, int depth, const Material& mat)
    : APrimitive(mat)
    {
        generate(center, size, depth);
    }

    bool RayTracer::Menger::hits(const Ray& ray, double& tHit, HitRecord& rec) const
    {
        bool hit   = false;
        double best = std::numeric_limits<double>::infinity();

        for (auto& child : _children) {
            double t;
            HitRecord tempRec;
            if (child->hits(ray, t, tempRec) && t < best) {
                best = t;
                tHit = t;
                rec  = tempRec;
                hit  = true;
            }
        }
        return hit;
    }

    RayTracer::AABB RayTracer::Menger::bounds() const
    {
        if (_children.empty())
            return AABB{};
        AABB box = _children.front()->bounds();
        for (size_t i = 1; i < _children.size(); ++i)
            box = surrounding_box(box, _children[i]->bounds());
        return box;
    }

    bool RayTracer::Menger::isRemoved(int x, int y, int z) const
    {
        int mid = 1;
        int count = (x == mid) + (y == mid) + (z == mid);
        return count >= 2;
    }

    void RayTracer::Menger::generate(const Math::Point3D& center, double size, int depth)
    {
        if (depth == 0) {
            Math::Vector3D half(size/2, size/2, size/2);
            Math::Point3D mn = center - half;
            Math::Point3D mx = center + half;
            _children.push_back(std::make_shared<Box>(mn, mx, material));
            return;
        }

        double newSize = size / 3.0;
        for (int x = 0; x < 3; ++x)
        for (int y = 0; y < 3; ++y)
        for (int z = 0; z < 3; ++z) {
            if (isRemoved(x,y,z)) continue;
            Math::Vector3D offset(
                (x-1)*newSize,
                (y-1)*newSize,
                (z-1)*newSize
            );
            generate(center + offset, newSize, depth-1);
        }
    }
