/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** NoiseTexture
*/

#include "../../include/rendering/NoiseTexture.hpp"

RayTracer::NoiseTexture::NoiseTexture(std::shared_ptr<RayTracer::Texture> base,
                           float scale,
                           float strength)
  : _base(std::move(base)), _scale(scale), _strength(strength) {}

Math::Vector3D RayTracer::NoiseTexture::sample(float u, float v) const {
    Math::Vector3D baseColor = _base->sample(u, v);
    float n = _noise.noise(u * _scale, v * _scale);
    float factor = 1.0f + (n - 0.5f) * 2.0f * _strength;
    return baseColor * factor;
}