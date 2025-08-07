/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Mesh
*/

/**
 * @file   Mesh.hpp
 * @brief  Declares a simple triangle mesh wrapper used by the ray tracer. 
 * @author Cyrian Pittaluga
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * The mesh is a thin convenience layer that stores a flat list of
 * **Triangle** primitives, provides aggregate ray–mesh intersection, and
 * offers basic transform utilities (uniform scaling + translation).
 * More advanced features such as BVH-per-mesh or normal smoothing are
 * implemented elsewhere.
*/

#pragma once

#include <vector>

#include "primitives/Triangle.hpp"
#include "core/Ray.hpp"

namespace RayTracer {

    /**
     * @class Mesh
     * @brief  A collection of `Triangle` primitives.
     *
     * The mesh does **not** own a BVH by itself: `Mesh::hits()` simply
     * iterates through the internal vector and returns the nearest hit.
     * Scene builders are expected to wrap the mesh in a higher-level BVH
     * node for acceleration.
    */
    class Mesh {
    public:
        std::vector<Triangle> triangles;    ///< Flat array of triangles.

        /** Default-constructs an empty mesh. */
        Mesh();

        void addTriangle(const Triangle& triangle);
        bool hits(const Ray& ray, double& tOut, HitRecord& rec) const;
        void transform(const Math::Vector3D& translation, double scale);
    };
}