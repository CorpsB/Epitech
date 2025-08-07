/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Box.cpp
*/

#include "../../include/primitives/Box.hpp"

RayTracer::Box::Box(const Math::Point3D& mn, const Math::Point3D& mx, const Math::Vector3D& col)
    : APrimitive(Material{"legacy", col, 0.0f, 0.0f, {0,0,0}, 0.0f, 1.0f}), min(mn), max(mx) {}

    RayTracer::Box::Box(const Math::Point3D& mn, const Math::Point3D& mx, const Material& mat)
    : APrimitive(mat), min(mn), max(mx) {}

    RayTracer::AABB RayTracer::Box::bounds() const 
    {
        return AABB{ min, max };
    }

    bool RayTracer::Box::hits(const Ray& ray, double& tOut, HitRecord& rec) const
    {
        const double EPS = 1e-8;
        double tmin = (min.x - ray.origin.x) / ray.direction.x;
        double tmax = (max.x - ray.origin.x) / ray.direction.x;
        if (tmin > tmax) std::swap(tmin, tmax);

        double tymin = (min.y - ray.origin.y) / ray.direction.y;
        double tymax = (max.y - ray.origin.y) / ray.direction.y;
        if (tymin > tymax) std::swap(tymin, tymax);

        if (tmin > tymax || tymin > tmax) return false;
        tmin = std::max(tmin, tymin);
        tmax = std::min(tmax, tymax);

        double tzmin = (min.z - ray.origin.z) / ray.direction.z;
        double tzmax = (max.z - ray.origin.z) / ray.direction.z;
        if (tzmin > tzmax) std::swap(tzmin, tzmax);

        if (tmin > tzmax || tzmin > tmax) return false;
        tmin = std::max(tmin, tzmin);
        tmax = std::min(tmax, tzmax);

        double t = (tmin >= EPS ? tmin : (tmax >= EPS ? tmax : -1));
        if (t < 0) return false;

        tOut = t;
        rec.t = t;
        rec.point = ray.origin + ray.direction * t;

        const double e = 1e-6;
        auto &p = rec.point;
        if (std::abs(p.x - min.x) < e) rec.normal = { -1,  0,  0 };
        else if (std::abs(p.x - max.x) < e) rec.normal = {  1,  0,  0 };
        else if (std::abs(p.y - min.y) < e) rec.normal = {  0, -1,  0 };
        else if (std::abs(p.y - max.y) < e) rec.normal = {  0,  1,  0 };
        else if (std::abs(p.z - min.z) < e) rec.normal = {  0,  0, -1 };
        else  rec.normal = {  0,  0,  1 };

        float scale = 0.25f;
        float u, v;
        if (std::abs(rec.normal.x) > 0.5f) {
            u = p.z * scale;
            v = p.y * scale;
        } else if (std::abs(rec.normal.y) > 0.5f) {
            u = p.x * scale;
            v = p.z * scale;
        } else {
            u = p.x * scale;
            v = p.y * scale;
        }
        u = std::fmod(u, 1.0f); if (u < 0) u += 1.0f;
        v = std::fmod(v, 1.0f); if (v < 0) v += 1.0f;
        rec.uv = { u, v };

        rec.material = material;
        rec.color = material.albedo;
        return true;
    }
