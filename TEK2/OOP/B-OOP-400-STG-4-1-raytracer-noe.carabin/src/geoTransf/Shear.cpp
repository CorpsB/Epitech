/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** shear.cpp
*/

/**
 * @file Shear.cpp
 * @brief Implements a geometric shear transformation applied to primitives.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * This file defines the `Shear` class, a geometric decorator that applies a shear transformation
 * to any wrapped primitive. A shear matrix modifies an object's shape by shifting points along 
 * axes based on their coordinates along other axes.
 *
 * Supported features:
 * - Construction of a 3×3 shear matrix from six parameters (sXY, sXZ, sYX, sYZ, sZX, sZY)
 * - Computation of its inverse (_mInv) and the matrix for transforming normals (_nMat)
 * - Transformation of rays before intersection tests and transformation of normals after intersection
 * - Recalculation of the AABB by applying the shear matrix to the eight corners of the original bounding box
 *
 * The shear matrix must be invertible. A runtime assertion is used to ensure this constraint.
 */


#include "../../include/geoTransf/Shear.hpp"
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

    RayTracer::Shear::Shear(std::shared_ptr<APrimitive> prim, double sXY, double sXZ, double sYX,
        double sYZ,double sZX,double sZY)
        : APrimitive(prim->getMaterial()), _prim(std::move(prim))
    {
        _m[0][0]=1;   _m[0][1]=sXY; _m[0][2]=sXZ;
        _m[1][0]=sYX; _m[1][1]=1;   _m[1][2]=sYZ;
        _m[2][0]=sZX; _m[2][1]=sZY; _m[2][2]=1;

        double d =
            _m[0][0]*(_m[1][1]*_m[2][2]-_m[1][2]*_m[2][1])
            - _m[0][1]*(_m[1][0]*_m[2][2]-_m[1][2]*_m[2][0])
            + _m[0][2]*(_m[1][0]*_m[2][1]-_m[1][1]*_m[2][0]);
        assert(std::fabs(d) > 1e-9 && "singular shear matrix");
        double invDet = 1.0/d;

        _mInv[0][0] =  (_m[1][1]*_m[2][2]-_m[1][2]*_m[2][1])*invDet;
        _mInv[0][1] = -(_m[0][1]*_m[2][2]-_m[0][2]*_m[2][1])*invDet;
        _mInv[0][2] =  (_m[0][1]*_m[1][2]-_m[0][2]*_m[1][1])*invDet;
        _mInv[1][0] = -(_m[1][0]*_m[2][2]-_m[1][2]*_m[2][0])*invDet;
        _mInv[1][1] =  (_m[0][0]*_m[2][2]-_m[0][2]*_m[2][0])*invDet;
        _mInv[1][2] = -(_m[0][0]*_m[1][2]-_m[0][2]*_m[1][0])*invDet;
        _mInv[2][0] =  (_m[1][0]*_m[2][1]-_m[1][1]*_m[2][0])*invDet;
        _mInv[2][1] = -(_m[0][0]*_m[2][1]-_m[0][1]*_m[2][0])*invDet;
        _mInv[2][2] =  (_m[0][0]*_m[1][1]-_m[0][1]*_m[1][0])*invDet;
        for(int i=0;i<3;++i)
            for(int j=0;j<3;++j)
                _nMat[i][j] = _mInv[j][i];
    }

    bool RayTracer::Shear::hits(const Ray& r, double& t, HitRecord& rec) const
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

    RayTracer::AABB RayTracer::Shear::bounds() const
    {
    const AABB b = _prim->bounds();

    Math::Point3D c[8] = { {b.min.x,b.min.y,b.min.z}, {b.max.x,b.min.y,b.min.z},
                     {b.min.x,b.max.y,b.min.z}, {b.max.x,b.max.y,b.min.z},
                     {b.min.x,b.min.y,b.max.z}, {b.max.x,b.min.y,b.max.z},
                     {b.min.x,b.max.y,b.max.z}, {b.max.x,b.max.y,b.max.z} };

    Math::Point3D mn = mul33(_m, c[0]), mx = mn;
    for (int i=1;i<8;++i) {
        Math::Point3D p = mul33(_m, c[i]);
        mn.x = std::min(mn.x, p.x);  mx.x = std::max(mx.x, p.x);
        mn.y = std::min(mn.y, p.y);  mx.y = std::max(mx.y, p.y);
        mn.z = std::min(mn.z, p.z);  mx.z = std::max(mx.z, p.z);
        }
        return {mn, mx};
    }
