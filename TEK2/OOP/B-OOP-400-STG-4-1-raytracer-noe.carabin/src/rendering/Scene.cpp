/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Scene
*/

#include "../../include/rendering/Scene.hpp"

#include "../../include/rendering/Scene.hpp"

/**
 * @brief Add a geometry object to the scene.
 * @param obj Shared pointer to the primitive (stored by value).
*/
RayTracer::Scene::Scene(const RayTracer::Camera& cam)
    : camera(cam) {
}

/**
 * @brief Add a geometry object to the scene.
 * @param obj Shared pointer to the primitive (stored by value).
*/
void RayTracer::Scene::addObject(const std::shared_ptr<RayTracer::APrimitive>& obj) {
    objects.push_back(obj);
}

/**
 * @brief Add a light source to the scene.
 * @param light Light descriptor (copied).
*/
void RayTracer::Scene::addLight(std::shared_ptr<ILight> light) {
    lights.push_back(std::move(light));
}

/**
 * @brief Intersect a ray with all objects in the scene.
 *
 * If a BVH has been built, this method traverses the hierarchy;  
 * otherwise it performs a brute-force loop over @ref objects.
 *
 * @param ray   Incoming ray in world space.
 * @param tOut  [in/out] closest distance found so far.
 * @param rec   [out] hit information on success.
 * @return      *true* if the ray hits at least one primitive.
*/
bool RayTracer::Scene::hit(const RayTracer::Ray& ray, double& tOut, RayTracer::HitRecord& rec) const {
    return bvhRoot->hit(ray, tOut, rec);
}
