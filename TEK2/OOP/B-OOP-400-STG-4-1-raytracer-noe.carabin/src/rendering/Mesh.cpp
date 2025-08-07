/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Mesh
*/

#include "../../include/rendering/Mesh.hpp"

RayTracer::Mesh::Mesh() = default;

/**
 * @brief Append a triangle to the mesh.
 * @param triangle Triangle to copy into the internal vector.
*/
void RayTracer::Mesh::addTriangle(const Triangle& triangle) {
    triangles.push_back(triangle);
}

/**
 * @brief Ray–mesh intersection (brute force).
 * @param ray   Incoming ray in world space.
 * @param tOut  [in/out] smallest positive distance found so far.
 * @param rec   [out] hit information if an intersection occurs.
 * @return      *true* if at least one triangle is hit.
 *
 * The function loops over all triangles and selects the nearest hit
 * whose distance lies in `(ε, tOut)`.  It updates `tOut` and `rec`
 * accordingly.
*/
bool RayTracer::Mesh::hits(const Ray& ray, double& tOut, HitRecord& rec) const {
    bool hitAnything = false;
    double closestSoFar = tOut;
    HitRecord tempRec;

    for (const auto& triangle : triangles) {
        double tTmp;
        HitRecord recTmp;
        if (triangle.hits(ray, tTmp, recTmp) && tTmp < closestSoFar) {
            hitAnything = true;
            closestSoFar = tTmp;
            tempRec = recTmp;
        }
    }

    if (hitAnything) {
        rec = tempRec;
        tOut = closestSoFar;
    }
    return hitAnything;
}

/**
 * @brief Apply a uniform scale and translation to all vertices.
 * @param translation  Offset added to each vertex position.
 * @param scale        Uniform scale factor (> 0).
 *
 * Normals are transformed by the inverse-transpose of the scale
 * (i.e. multiplied by `1/scale`) to keep them unit-length.
*/
void RayTracer::Mesh::transform(const Math::Vector3D& translation, double scale) {
    for (auto& tri : triangles) {
        tri.v0 = (tri.v0 * scale) + translation;
        tri.v1 = (tri.v1 * scale) + translation;
        tri.v2 = (tri.v2 * scale) + translation;
    }
}