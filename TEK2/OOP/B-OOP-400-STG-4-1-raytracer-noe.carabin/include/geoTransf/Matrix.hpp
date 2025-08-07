/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Matrix
*/

/**
 * @file Matrix.hpp
 * @brief Declares the Matrix transformation wrapper primitive for raytracing.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * This primitive applies a 3×3 linear transformation to another APrimitive.
 * It modifies both the geometry and the normals using the forward matrix
 * and its inverse/transpose for proper shading and intersection testing.
 */

#include "core/APrimitive.hpp"
#include "rendering/BVH.hpp"

#ifndef MATRIX_HPP_
    #define MATRIX_HPP_


namespace RayTracer {
    /**
     * @class Matrix
     * @brief Applies a 3×3 linear transformation to a primitive.
     *
     * This wrapper primitive supports arbitrary linear transformations (including shearing,
     * rotation, reflection, and scaling) by applying a transformation matrix to rays and
     * normals at render time.
     */
    class Matrix : public APrimitive {
        public:
            /**
             * @brief Construct a transformed primitive using a matrix.
             * @param prim The original primitive to transform
             * @param matrix A 3×3 transformation matrix
             */
            Matrix(std::shared_ptr<APrimitive> prim, const double matrix[3][3]);

            /**
             * @brief Perform ray–transformed-primitive intersection test.
             * @param r Incoming ray in world space
             * @param t [out] Distance to hit
             * @param rec [out] Hit record data
             * @return true if the ray intersects the transformed object
             */
            bool hits(const Ray &r, double &t, HitRecord &rec) const override;
            /**
             * @brief Compute the axis-aligned bounding box of the transformed object.
             * @return AABB in world space
             */
            AABB bounds() const override;
        protected:
        private:
            std::shared_ptr<APrimitive> _prim; ///< Wrapped primitive
            double _m[3][3];   ///< Transformation matrix
            double _mInv[3][3];///< Inverse of the transformation matrix
            double _nMat[3][3];///< Normal transformation matrix (transpose of inverse)
    };
}

#endif /* !MATRIX_HPP_ */
