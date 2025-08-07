/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Shear.hpp
*/

/**
 * @file Shear.hpp
 * @brief Declares the geometric shear transformation primitive for raytracing scenes.
 * @author Thibaut Louis
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * The Shear class allows applying a linear shear transformation to any primitive.
 * It uses a 3×3 shear matrix defined by six coefficients to distort space along specific axes.
 * This transformation is applied during intersection and normal calculations.
 */
#pragma once

#include <memory>
#include "core/APrimitive.hpp"
#include "rendering/BVH.hpp"

namespace RayTracer {

    /**
     * @class Shear
     * @brief Applies a 3D shear transformation to a wrapped primitive.
     *
     * The shear matrix is built from six off-diagonal parameters, allowing transformations
     * like skewing along XY, XZ, YX, YZ, ZX, and ZY. This transformation affects ray traversal
     * and shading through matrix-based coordinate remapping.
     */
    class Shear final : public APrimitive {
        public :
            /**
             * @brief Constructs a shear transformation around the given primitive.
             * 
             * @param prim Pointer to the primitive to transform
             * @param sXY Shear along X as a function of Y
             * @param sXZ Shear along X as a function of Z
             * @param sYX Shear along Y as a function of X
             * @param sYZ Shear along Y as a function of Z
             * @param sZX Shear along Z as a function of X
             * @param sZY Shear along Z as a function of Y
             */
            Shear(std::shared_ptr<APrimitive> prim,
            double sXY = 0, double sXZ = 0,
            double sYX = 0, double sYZ = 0,
            double sZX = 0, double sZY = 0);

        /**
         * @brief Performs ray intersection test after applying the shear transformation.
         * @param r Incoming ray
         * @param t [out] Distance to intersection
         * @param rec [out] Hit record (position, normal, etc.)
         * @return true if the ray intersects the sheared object
         */
        bool hits(const Ray& r, double& t, HitRecord& rec)const override;

        /**
         * @brief Computes the axis-aligned bounding box of the sheared primitive.
         * @return AABB in world space
         */
        AABB bounds() const override;

        private:
            std::shared_ptr<APrimitive> _prim; ///< Wrapped primitive
            double _m[3][3];    ///< Shear transformation matrix
            double _mInv[3][3]; ///< Inverse shear matrix
            double _nMat[3][3]; ///< Normal transformation matrix (transpose of inverse)
    };
} // namespace RayTracer
