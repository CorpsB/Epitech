/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Rotation
*/

/**
 * @file Rotation.hpp
 * @brief Declares a wrapper primitive that applies 3D Euler rotations to another primitive's space before ray intersection tests and shading computations.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * This primitive rotates an underlying APrimitive around the X, Y, and Z axes (in that order)
 * using Euler angles (in radians). It modifies both the incoming ray and the resulting normal
 * during intersection tests.
 */

#ifndef ROTATION_HPP_
    #define ROTATION_HPP_

#include "core/APrimitive.hpp"
#include "rendering/BVH.hpp"

namespace RayTracer {
    /**
     * @class Rotation
     * @brief Applies 3D Euler rotation to a primitive using a rotation matrix.
     *
     * The class wraps another primitive and applies a rotation around the X, Y, and Z axes
     * to all rays and normals. The matrix is built from three rotation angles provided at construction.
     */
    class Rotation : public APrimitive {
        public:
            /**
             * @brief Constructs a rotated version of the given primitive.
             * @param prim Shared pointer to the base primitive
             * @param rx Rotation angle around X axis (in radians)
             * @param ry Rotation angle around Y axis (in radians)
             * @param rz Rotation angle around Z axis (in radians)
             */
            Rotation(std::shared_ptr<APrimitive> prim, double rx, double ry, double rz);

            /**
             * @brief Tests for ray–rotated-primitive intersection.
             * @param r Incoming ray in world space
             * @param t [out] Distance to hit point along the ray
             * @param rec [out] Hit information (position, normal, material)
             * @return true if the ray hits the rotated primitive
             */
            bool hits(const Ray &r, double &t, HitRecord &rec) const override;
            /**
             * @brief Computes the AABB of the rotated primitive.
             * @return Axis-aligned bounding box in world space
             */
            AABB bounds() const override;
        protected:
        private:
        std::shared_ptr<APrimitive> _prim; ///< The wrapped base primitive
        double _m[3][3];    ///< Rotation matrix
        double _mInv[3][3]; ///< Inverse rotation matrix
        double _nMat[3][3]; ///< Normal transformation matrix (transpose of inverse)
    };
}

#endif /* !ROTATION_HPP_ */
