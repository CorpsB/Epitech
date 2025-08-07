/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Point3D
*/

/**
 * @file Point3D.hpp
 * @brief Defines a 3D point structure used in geometric computations.
 * @author Cyrian PITTALUGA
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * The Point3D structure represents a point in 3D space. It provides common
 * arithmetic operations with vectors, such as translation or difference, and is
 * used throughout the raytracer for positioning objects, rays, and intersections.
 */

#pragma once
#include "Vector3D.hpp"
#include "cmath"

namespace Math {
    /**
     * @struct Point3D
     * @brief Represents a 3D point in Cartesian coordinates.
     *
     * Provides constructors and arithmetic operations involving Vector3D
     * for geometric transformations such as translation, scaling, and displacement.
     */
    struct Point3D {
        double x = 0; ///< X coordinate
        double y = 0; ///< Y coordinate
        double z = 0; ///< Z coordinate

        /**
         * @brief Default constructor. Initializes to (0, 0, 0).
         */
        Point3D() = default;

        /**
         * @brief Construct a point with custom coordinates.
         * @param _x X coordinate
         * @param _y Y coordinate
         * @param _z Z coordinate
         */
        Point3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

        /**
         * @brief Translate a point by a vector.
         * @param p Original point
         * @param v Vector to add
         * @return New point translated by the vector
         */
        friend Point3D operator+(const Point3D& p, const Vector3D& v) {
            return {p.x + v.x, p.y + v.y, p.z + v.z};
        }
        /**
         * @brief Translate a point in the opposite direction of a vector.
         * @param p Original point
         * @param v Vector to subtract
         * @return New point translated negatively by the vector
         */
        friend Point3D operator-(const Point3D& p, const Vector3D& v) {
            return {p.x - v.x, p.y - v.y, p.z - v.z};
        }
        /**
         * @brief Compute the vector between two points.
         * @param a First point
         * @param b Second point
         * @return Vector from b to a
         */
        friend Vector3D operator-(const Point3D& a, const Point3D& b) {
            return {a.x - b.x, a.y - b.y, a.z - b.z};
        }
        /**
         * @brief Multiply a point’s coordinates by a scalar.
         * @param p The point
         * @param s The scalar value
         * @return Scaled point
         */
        friend Point3D operator*(const Point3D& p, double s) {
            return {p.x * s, p.y * s, p.z * s};
        }
    };
} // namespace Math
