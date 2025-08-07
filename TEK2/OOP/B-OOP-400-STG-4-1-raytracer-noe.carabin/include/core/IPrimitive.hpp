/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** IPrimitive.hpp
*/

/**
 * @file IPrimitive.hpp
 * @brief Interface for geometric primitives in the raytracer.
 * @author Thibaut Louis
 * @version 1.0
 * @date 2024-05
 *
 * @details
 * This file defines the IPrimitive interface, which all geometric objects
 * in the raytracer must implement. Each primitive must be able to:
 * - test intersection with a ray
 * - provide its axis-aligned bounding box (AABB).
 */

#pragma once
#include "core/Ray.hpp"

namespace RayTracer {

    struct AABB;
    struct HitRecord;

    /**
     * @interface IPrimitive
     * @brief Pure interface that every geometric primitive must implement.
     *
     * Provides the essential functions needed by the raytracing engine:
     * ray intersection test and bounding box query.
     */
    class IPrimitive {
    public:
        /**
         * @brief Virtual destructor for interface.
         */
        virtual ~IPrimitive() = default;

        /**
         * @brief Ray–primitive intersection test.
         *
         * Checks whether a given ray intersects the primitive, and if so,
         * fills the intersection record with details (point, normal, etc.).
         *
         * @param ray The incoming ray in world space.
         * @param t   [out] Ray parameter at the intersection point (smallest positive t).
         * @param rec [out] Intersection record (position, normal, material, etc.).
         * @return true if the ray intersects the primitive.
         */
        virtual bool hits(const Ray& ray,
                          double&    t,
                          HitRecord& rec) const = 0;

        /**
         * @brief Returns the axis-aligned bounding box of the primitive.
         *
         * This is used by the acceleration structures such as BVH to spatially
         * partition the scene.
         *
         * @return AABB structure that bounds the primitive in world coordinates.
         */
        virtual AABB bounds() const = 0;
    };

} // namespace RayTracer
