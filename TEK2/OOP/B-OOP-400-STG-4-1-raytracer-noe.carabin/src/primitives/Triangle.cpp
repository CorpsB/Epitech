/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Triangle.cpp
*/

#include "../../include/primitives/Triangle.hpp"

RayTracer::AABB RayTracer::Triangle::bounds() const
    {
        double minX = std::min({ v0.x, v1.x, v2.x });
        double minY = std::min({ v0.y, v1.y, v2.y });
        double minZ = std::min({ v0.z, v1.z, v2.z });
        double maxX = std::max({ v0.x, v1.x, v2.x });
        double maxY = std::max({ v0.y, v1.y, v2.y });
        double maxZ = std::max({ v0.z, v1.z, v2.z });
        return AABB{ {minX, minY, minZ}, {maxX, maxY, maxZ} };
    }

    RayTracer::Triangle::Triangle(const Math::Point3D& _v0,
        const Math::Point3D& _v1,
        const Math::Point3D& _v2,
        const Math::Vector3D& col)
        : APrimitive(Material{"legacy", col, 0.0f, 0.0f, Math::Vector3D{0.0,0.0,0.0}, 0.0f, 1.0f}),
        v0(_v0), v1(_v1), v2(_v2)
        {}

        RayTracer::Triangle::Triangle(const Math::Point3D& _v0,
                const Math::Point3D& _v1,
                const Math::Point3D& _v2,
                const Material& mat)
        : APrimitive(mat),
        v0(_v0), v1(_v1), v2(_v2)
    {}

    bool RayTracer::Triangle::hits(const Ray& ray, double& tOut) const
    {
        HitRecord rec;
        return hits(ray, tOut, rec);
    }

    bool RayTracer::Triangle::hits(const Ray& ray, double& tOut, HitRecord& rec) const
    {
        const double EPS = 1e-8;
        auto edge1 = v1 - v0;
        auto edge2 = v2 - v0;
        auto faceN = edge1.cross(edge2);

        if (faceN.dot(ray.direction) >= 0) return false;

        auto h = ray.direction.cross(edge2);
        auto a = edge1.dot(h);
        if (std::abs(a) < EPS) return false;

        auto f = 1.0 / a;
        auto s = ray.origin - v0;
        auto u = f * s.dot(h);
        if (u < 0.0 || u > 1.0) return false;

        auto q = s.cross(edge1);
        auto v = f * ray.direction.dot(q);
        if (v < 0.0 || u + v > 1.0) return false;

        auto tmp = f * edge2.dot(q);
        if (tmp <= EPS) return false;

        tOut = tmp;
        rec.t = tmp;
        rec.point = ray.origin + ray.direction * tmp;
        rec.normal = faceN / faceN.length();
        rec.material = material;
        rec.color = material.albedo;
        return true;
    }

    bool RayTracer::Triangle::hitsNoCull(const Ray& ray, double& tOut, HitRecord& rec) const
    {
        const double EPS = 1e-8;
        auto edge1 = v1 - v0;
        auto edge2 = v2 - v0;
        auto faceN = edge1.cross(edge2);

        auto h = ray.direction.cross(edge2);
        auto a = edge1.dot(h);
        if (std::abs(a) < EPS) return false;

        auto f = 1.0 / a;
        auto s = ray.origin - v0;
        auto u = f * s.dot(h);
        if (u < 0.0 || u > 1.0) return false;

        auto q = s.cross(edge1);
        auto v = f * ray.direction.dot(q);
        if (v < 0.0 || u + v > 1.0) return false;

        auto tmp = f * edge2.dot(q);
        if (tmp <= EPS) return false;

        tOut = tmp;
        rec.t = tmp;
        rec.point = ray.origin + ray.direction * tmp;
        rec.normal = faceN / faceN.length();
        rec.material = material;
        rec.color = material.albedo;
        return true;
    }
    