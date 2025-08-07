/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Rotation.cpp
*/

/**
 * @file Rotation.cpp
 * @brief Implements a geometric rotation transformation applied to primitives.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * This file defines the `Rotation` decorator, which applies a rotation to a wrapped primitive.
 * The rotation is defined using three Euler angles (in radians) for the X, Y, and Z axes.
 *
 * Key operations:
 * - Construction of combined 3×3 rotation matrix (Z * Y * X).
 * - Computation of inverse matrix and normal transformation matrix.
 * - Transformation of rays before intersection and normals after hit detection.
 * - Transformed bounding box (AABB) recomputed by rotating the 8 corners.
 *
 * This class relies on matrix multiplication helpers to perform forward and inverse transformations.
 * It preserves material and encapsulates the original primitive.
 */


#include "../../include/geoTransf/Rotation.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>

    static inline Math::Vector3D mul33(const double m[3][3], const Math::Vector3D& v)
    {
        return {
            m[0][0]*v.x + m[0][1]*v.y + m[0][2]*v.z,
            m[1][0]*v.x + m[1][1]*v.y + m[1][2]*v.z,
            m[2][0]*v.x + m[2][1]*v.y + m[2][2]*v.z
        };
    }

    static inline Math::Point3D mul33(const double m[3][3], const Math::Point3D& p)
    {
        return {
            m[0][0]*p.x + m[0][1]*p.y + m[0][2]*p.z,
            m[1][0]*p.x + m[1][1]*p.y + m[1][2]*p.z,
            m[2][0]*p.x + m[2][1]*p.y + m[2][2]*p.z
        };
    }

    static inline void mul33(const double a[3][3], const double b[3][3], double result[3][3])
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                result[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j] + a[i][2]*b[2][j];
    }


    RayTracer::Rotation::Rotation(std::shared_ptr<APrimitive> prim, double rx, double ry, double rz)
        : APrimitive(prim->getMaterial()), _prim(std::move(prim))
    {
        const double cx = std::cos(rx), sx = std::sin(rx);
        const double cy = std::cos(ry), sy = std::sin(ry);
        const double cz = std::cos(rz), sz = std::sin(rz);

        double rotX[3][3] = {
            {1, 0, 0},
            {0, cx, -sx},
            {0, sx, cx}
        };

        double rotY[3][3] = {
            {cy, 0, sy},
            {0, 1, 0},
            {-sy, 0, cy}
        };

        double rotZ[3][3] = {
            {cz, -sz, 0},
            {sz, cz, 0},
            {0, 0, 1}
        };

        double tmp[3][3];
        mul33(rotZ, rotY, tmp);
        mul33(tmp, rotX, _m);

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                _mInv[i][j] = _m[j][i];

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                _nMat[i][j] = _mInv[j][i];
    }

    bool RayTracer::Rotation::hits(const Ray& r, double& t, HitRecord& rec) const
    {
    Ray rl;

    rl.origin    = mul33(_mInv, r.origin);
    rl.direction = mul33(_mInv, r.direction).normalized();
    if (!_prim->hits(rl, t, rec))
        return false;
    rec.point  = mul33(_m, rec.point);
    rec.normal = mul33(_nMat, rec.normal).normalized();
    return true;
    }

    RayTracer::AABB RayTracer::Rotation::bounds() const
    {
        const AABB b = _prim->bounds();
    
        Math::Point3D c[8] = {
            {b.min.x, b.min.y, b.min.z}, {b.max.x, b.min.y, b.min.z},
            {b.min.x, b.max.y, b.min.z}, {b.max.x, b.max.y, b.min.z},
            {b.min.x, b.min.y, b.max.z}, {b.max.x, b.min.y, b.max.z},
            {b.min.x, b.max.y, b.max.z}, {b.max.x, b.max.y, b.max.z}
        };
    
        Math::Point3D mn = mul33(_m, c[0]);
        Math::Point3D mx = mn;
    
        for (int i = 1; i < 8; ++i) {
            Math::Point3D p = mul33(_m, c[i]);
            mn.x = std::min(mn.x, p.x);  mx.x = std::max(mx.x, p.x);
            mn.y = std::min(mn.y, p.y);  mx.y = std::max(mx.y, p.y);
            mn.z = std::min(mn.z, p.z);  mx.z = std::max(mx.z, p.z);
        }
    
        return {mn, mx};
    }