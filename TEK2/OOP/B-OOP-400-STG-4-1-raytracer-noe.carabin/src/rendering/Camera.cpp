/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Camera
*/

#include "../../include/rendering/Camera.hpp"
#include <cmath>
#include <random>

RayTracer::Camera::Camera(const Math::Point3D& lookfrom,
    const Math::Point3D& lookat,
    const Math::Vector3D& vup,
    double vfov,
    double aspect,
    double aperture,
    double focus_dist,
    int cam_height,
    int cam_width)
{
    height = cam_height;
    width = cam_width;
    lens_radius = aperture * 0.5;
    double theta = vfov * M_PI / 180.0;
    double half_h = std::tan(theta / 2);
    double half_w = aspect * half_h;
    origin = lookfrom;
    w = (lookfrom - lookat) / (lookfrom - lookat).length();
    u = vup.cross(w) / vup.cross(w).length();
    v = w.cross(u);
    lower_left = origin
                 - u * (half_w * focus_dist)
                 - v * (half_h * focus_dist)
                 - w * focus_dist;
    horizontal = u * (2 * half_w * focus_dist);
    vertical   = v * (2 * half_h * focus_dist);
}

/**
 * @brief  Generate a primary ray through screen coordinates *(s,t)*.
 *
 * @param s Horizontal coordinate in [0,1] (0 → left, 1 → right).
 * @param t Vertical   coordinate in [0,1] (0 → bottom, 1 → top).
 * @return  A Ray starting at the lens (or origin for pin-hole) and
 *          passing through the corresponding point on the view plane.
 *
 * The method applies lens jittering if `lens_radius > 0`.
*/
RayTracer::Ray RayTracer::Camera::ray(double s, double t) const {
    Math::Vector3D rd = random_in_unit_disk() * lens_radius;
    Math::Vector3D offset = u * rd.x + v * rd.y;
    Math::Point3D p = lower_left + horizontal * s + vertical * t;
    Math::Point3D ray_origin = origin + offset;
    Math::Vector3D ray_dir = p - origin - offset;
    return Ray(ray_origin, ray_dir);
}

/**
 * @brief Random point inside a unit disk in the xy-plane.
 * @return  2-D vector (z = 0) uniformly sampled within the disk.
*/
Math::Vector3D RayTracer::Camera::random_in_unit_disk() {
    static thread_local std::mt19937 gen{std::random_device{}()};
    static thread_local std::uniform_real_distribution<double> dist(-1.0, 1.0);
    Math::Vector3D p;
    do {
        p = Math::Vector3D(dist(gen), dist(gen), 0.0);
    } while (p.dot(p) >= 1.0);
    return p;
}