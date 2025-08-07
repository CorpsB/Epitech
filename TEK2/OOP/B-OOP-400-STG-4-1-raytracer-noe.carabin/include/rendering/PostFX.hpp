/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** PostFX
*/

/**
 * @file   PostFX.hpp
 * @brief  Declares simple post-processing helpers (contrast, saturation,
 *         tone-mapping, vignette) for the ray-tracer frame-buffer. 
 * @author Cyrian Pittaluga
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * All functions operate on linear-space RGB values stored in a flat
 * frame-buffer (`std::vector<Math::Vector3D>`).  The default pipeline
 * executed by @ref PostFX::postProcess performs:
 *  1. Contrast adjustment,
 *  2. Saturation adjustment,
 *  3. Filmic tone-mapping,
 *  4. Radial vignette.
 * Each step can be enabled / disabled via its scaling parameter.
*/

#pragma once

#include <vector>
#include <cmath>
#include "core/Vector3D.hpp"

namespace PostFX {
    
    float clamp01(float v);
    Math::Vector3D adjustContrast(const Math::Vector3D& c, float contrast);
    Math::Vector3D adjustSaturation(const Math::Vector3D& c, float satF);
    Math::Vector3D toneMap(const Math::Vector3D& c);
    float vignetteFactor(int i, int j, int w, int h, float strength = 0.5f);

    void postProcess(std::vector<Math::Vector3D>& fb,
                     int w, int h,
                     float contrast = 1.0f,
                     float saturation = 1.0f,
                     float vignetteStrength = 0.5f);
}