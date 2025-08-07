/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Vector3D
*/

/**
 * @file Vector3D.hpp
 * @brief Defines a 3D vector structure with basic arithmetic and transformation operations.
 * @author Cyrian PUTTAGULA
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * The Vector3D structure is a core math component used throughout the raytracer.
 * It supports common vector operations including addition, normalization, dot/cross product,
 * scalar multiplication/division, and rotations around each axis.
 */

#pragma once

#include <cmath>

namespace Math {

    /**
     * @struct Vector3D
     * @brief Represents a 3D vector with real coordinates.
     */
    struct Vector3D {
        double x; ///< X component
        double y; ///< Y component
        double z; ///< Z component

        /**
         * @brief Default constructor. Initializes all components to 0.
         */
        Vector3D();
        /**
         * @brief Constructs a 3D vector with specified coordinates.
         * @param _x X component
         * @param _y Y component
         * @param _z Z component
         */
        Vector3D(double _x, double _y, double _z);

        /**
         * @brief Computes the Euclidean length (norm) of the vector.
         * @return Vector magnitude
         */
        double length() const;
        /**
         * @brief Returns a normalized (unit-length) copy of the vector.
         * @return A new normalized vector
         */
        Vector3D normalized() const;
        /**
         * @brief Normalizes the vector in-place.
         * @return Reference to self
         */
        Vector3D& normalize();
        /**
         * @brief Computes the dot product between this and another vector.
         * @param other The other vector
         * @return Scalar dot product
         */
        double dot(const Vector3D& other) const;
        /**
         * @brief Computes the cross product between this and another vector.
         * @param other The other vector
         * @return Resulting perpendicular vector
         */
        Vector3D cross(const Vector3D& other) const;

        /**
         * @brief Adds two vectors.
         */
        Vector3D operator+(const Vector3D& o) const;
        /**
         * @brief Adds a vector to this one in-place.
         */
        Vector3D& operator+=(const Vector3D& o);
        /**
         * @brief Subtracts two vectors.
         */
        Vector3D operator-(const Vector3D& o) const;
        /**
         * @brief Subtracts a vector from this one in-place.
         */
        Vector3D& operator-=(const Vector3D& o);
        /**
         * @brief Multiplies component-wise with another vector.
         */
        Vector3D operator*(const Vector3D& o) const;
        /**
         * @brief Multiplies component-wise with another vector in-place.
         */
        Vector3D& operator*=(const Vector3D& o);
        /**
         * @brief Divides component-wise by another vector.
         */
        Vector3D operator/(const Vector3D& o) const;
        /**
         * @brief Divides component-wise by another vector in-place.
         */
        Vector3D& operator/=(const Vector3D& o);

        /**
         * @brief Multiplies the vector by a scalar.
         */
        Vector3D operator*(double s) const;
        /**
         * @brief Multiplies the vector by a scalar in-place.
         */
        Vector3D& operator*=(double s);
        /**
         * @brief Divides the vector by a scalar.
         */
        Vector3D operator/(double s) const;
        /**
         * @brief Divides the vector by a scalar in-place.
         */
        Vector3D& operator/=(double s);
        /**
         * @brief Translates this vector by another one in-place.
         * @param t Translation vector
         * @return Reference to self
         */
        Vector3D& translate(const Vector3D& t);

        /**
         * @brief Rotates the vector around the X-axis by a given angle.
         * @param deg Angle in degrees
         * @return Rotated vector
         */
        Vector3D rotateX(double deg) const;
        /**
         * @brief Rotates the vector around the Y-axis by a given angle.
         * @param deg Angle in degrees
         * @return Rotated vector
         */
        Vector3D rotateY(double deg) const;
        /**
         * @brief Rotates the vector around the Z-axis by a given angle.
         * @param deg Angle in degrees
         * @return Rotated vector
         */
        Vector3D rotateZ(double deg) const;
    };

}// namespace Math
