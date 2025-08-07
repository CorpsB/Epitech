/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** ShadowShading
*/

/**
 * @file   Shading.hpp
 * @brief  Free helpers for Monte-Carlo path-tracing: utilities, samplers and
 *         the main recursive @ref shade integrator. 
 * @author Cyrian Pittaluga
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * The header exposes a handful of inline/constexpr functions used by the
 * renderer:
 *  - *clamp01* : clamp a scalar to [0,1];
 *  - *rand01* : uniform RNG in [0,1) using `std::mt19937`;
 *  - *sampleHemisphere* : cosine-weighted normal-oriented hemisphere sampler;
 *  - *shade* : recursive path tracer with Russian-roulette termination.
 *
 * Implementation lives in the corresponding **Shading.cpp** (or inlined).
*/

#pragma once

#include "Scene.hpp"
#include "ILight.hpp"
#include "core/Ray.hpp"
#include "core/Vector3D.hpp"
#include "rendering/Material.hpp"
#include "primitives/Sphere.hpp"
#include "Skybox.hpp"

#include <limits>
#include <cmath>
#include <random>
#include <algorithm>
#include <initializer_list>

namespace RayTracer {
    double clamp01(double v);
    double rand01();
    Math::Vector3D sampleHemisphere(const Math::Vector3D &N_shading, double &pdf);

/**
 * @brief Recursive path-tracing integrator.
 *
 * Shoots a primary or secondary ray, finds the nearest intersection in
 * the @p scene, then:
 *  1. adds emitted radiance (area lights or emissive materials);  
 *  2. samples the BSDF to spawn a bounce ray;  
 *  3. accumulates reflected radiance scaled by the BRDF and cosine;  
 *  4. terminates at @p maxDepth or via Russian-roulette.
 *
 * @param ray      Current ray in world space.
 * @param scene    Scene containing geometry, lights, BVH and skybox.
 * @param depth    Current recursion depth (0 for primary bounce).
 * @param maxDepth Maximum recursion depth allowed.
 * @return         Linear-space RGB radiance for this ray.
 *
 * The function is **not** thread-safe if it relies on global RNG; wrap
 * per-thread RNGs when doing multi-threaded rendering.
*/
    Math::Vector3D shade(const Ray &ray, const Scene &scene, int depth, int maxDepth);
}