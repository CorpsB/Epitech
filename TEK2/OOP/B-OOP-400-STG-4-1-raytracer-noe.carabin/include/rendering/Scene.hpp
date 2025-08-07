/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Scene
*/

/**
 * @file   Scene.hpp
 * @brief  Declares the scene container: camera, objects, lights, and top-level BVH. 
 * @author Cyrian Pittaluga
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * A scene owns:
 *  - a single active @ref Camera,
 *  - a list of @ref Primitive objects (spheres, meshes, etc.),
 *  - a top-level BVH built over those primitives for fast traversal,
 *  - an array of analytic @ref Light sources.
 *
 * Once objects are added, call `buildBVH()` (not shown here) or construct
 * `bvhRoot` externally before tracing rays with @ref Scene::hit.
 */

 #pragma once

 #include <vector>
 #include <memory>
 
 #include "core/APrimitive.hpp"
 #include "Camera.hpp"
#include <memory>
#include "ILight.hpp"
 #include "BVH.hpp"
 
 namespace RayTracer {
 
     /**
      * @class Scene
      * @brief  Complete renderable scene.
      *
      * Provides a convenience wrapper that stores the camera, the primitives,
      * the lights, and a pointer to the root node of the global BVH.  
      * The @ref hit method simply forwards to `bvhRoot->hit()` when the BVH
      * has been built; if `bvhRoot == nullptr` it falls back to a linear scan.
     */
     class Scene {
     public:
     Camera camera;                                      ///< Active camera.
     std::vector<std::shared_ptr<APrimitive>> objects;    ///< Owning list of geometry.
     std::unique_ptr<BVHNode> bvhRoot;                   ///< Top-level BVH (may be null).
     std::vector<std::shared_ptr<ILight>> lights;        ///< Analytic light sources.
 
         explicit Scene(const Camera& cam);
 
         void addObject(const std::shared_ptr<APrimitive>& obj);
         void addLight(std::shared_ptr<ILight> light);
         bool hit(const Ray& ray, double& tOut, HitRecord& rec) const;
     };
 }