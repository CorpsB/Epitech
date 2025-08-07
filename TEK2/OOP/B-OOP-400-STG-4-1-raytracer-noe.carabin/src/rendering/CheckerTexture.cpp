/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** CheckerTexture
*/

#include "../../include/rendering/CheckerTexture.hpp"

#include <cmath>

RayTracer::CheckerTexture::CheckerTexture(const Math::Vector3D& c1,
    const Math::Vector3D& c2,
    float scale) : _c1(c1), _c2(c2), _scale(scale) {

    }

/**
 * @brief Sample the texture at UV coordinates.
 * @param u  Horizontal coordinate in [0,1] (wrapped outside).
 * @param v  Vertical   coordinate in [0,1] (wrapped outside).
 * @return   **c1** or **c2** depending on the checker parity.
 *
 * The function simply tests  
 * `((int)floor(u*scale) + (int)floor(v*scale)) & 1`  
 * to pick the colour.
*/
Math::Vector3D RayTracer::CheckerTexture::sample(float u, float v) const {
    float iu = std::floor(u * _scale);
    float iv = std::floor(v * _scale);
    if (std::fmod(iu + iv, 2.0f) < 1.0f)
        return _c1;
    else
        return _c2;
}