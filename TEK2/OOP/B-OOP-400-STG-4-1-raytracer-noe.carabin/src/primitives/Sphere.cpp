/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Sphere.cpp
*/

#include "../../include/primitives/Sphere.hpp"

RayTracer::AABB RayTracer::Sphere::bounds() const
    {
        Math::Vector3D r{radius, radius, radius};
        return AABB{center - r, center + r};
    }

    RayTracer::Sphere::Sphere(const Math::Point3D& c,
            double r,
            const Math::Vector3D& col)
            : APrimitive(Material{"legacy", col, 0.0f, 0.0f,
                                    Math::Vector3D{0.0, 0.0, 0.0}, 0.0f, 1.0f}),
                center(c), radius(r) {}
    
    RayTracer::Sphere::Sphere(const Math::Point3D& c,
            double r,
            const Material& mat)
            : APrimitive(mat),
                center(c), radius(r) {}

    bool RayTracer::Sphere::hits(const Ray& ray, double& tOut, HitRecord& rec) const
    {
        Math::Vector3D oc = ray.origin - center;
        double a = ray.direction.dot(ray.direction);
        double b = 2.0 * oc.dot(ray.direction);
        double c = oc.dot(oc) - radius * radius;
        double disc = b*b - 4*a*c;
        if (disc < 0) return false;
        double sq = std::sqrt(disc);
        double root = (-b - sq) / (2*a);
        if (root < 1e-8) {
            root = (-b + sq) / (2*a);
            if (root < 1e-8) return false;
        }
        tOut = root;
        rec.t = root;
        rec.point = ray.origin + ray.direction * root;
        rec.normal = (rec.point - center) / radius;
        rec.material = material;

        Math::Vector3D p = (rec.point - center) / radius;
        double theta = std::atan2(p.z, p.x);
        double phi   = std::acos(p.y);
        float u = static_cast<float>((theta + M_PI) / (2.0 * M_PI));
        float v = static_cast<float>(phi / M_PI);
        rec.uv = { u, v };

        return true;
    }
