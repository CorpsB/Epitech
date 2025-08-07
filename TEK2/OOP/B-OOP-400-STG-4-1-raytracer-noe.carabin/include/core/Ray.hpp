/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Ray
*/

/**
 * @file Ray.hpp
 * @brief Defines the Ray structure used for ray-object intersection tests in the raytracer.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * A ray is defined by an origin point and a direction vector.
 * It is used extensively in ray tracing for casting through the scene and
 * determining intersections with primitives. The direction is expected to be normalized.
 */

#pragma once
#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
    /**
     * @struct Ray
     * @brief Represents a 3D ray with origin and direction.
     *
     * Used in all ray-primitive intersection calculations.
     */
    struct Ray {
        Math::Point3D origin;
        Math::Vector3D direction;

        /**
         * @brief Default constructor. Leaves origin and direction uninitialized.
         */
        Ray() = default;
        /**
         * @brief Construct a ray from origin and direction.
         * @param o Origin point
         * @param d Direction vector (should be normalized)
         */
        Ray(const Math::Point3D& o, const Math::Vector3D& d)
            : origin(o), direction(d) {}
    };
} // namespace RayTracer
