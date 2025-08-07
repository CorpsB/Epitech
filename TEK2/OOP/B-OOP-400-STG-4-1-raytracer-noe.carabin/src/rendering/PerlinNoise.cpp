/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** PerlinNoise
*/

#include "../../include/rendering/PerlinNoise.hpp"
#include <cmath>

RayTracer::PerlinNoise::PerlinNoise() {
    p.resize(256);
    std::iota(p.begin(), p.end(), 0);
    std::default_random_engine engine;
    std::shuffle(p.begin(), p.end(), engine);
    p.insert(p.end(), p.begin(), p.end());
}

float RayTracer::PerlinNoise::fade(float t) const {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

float RayTracer::PerlinNoise::lerp(float t, float a, float b) const {
    return a + t * (b - a);
}

float RayTracer::PerlinNoise::grad(int hash, float x, float y) const {
    int h = hash & 15;
    float u = h < 8 ? x : y;
    float v = h < 4 ? y : (h == 12 || h == 14 ? x : 0);
    return ((h & 1) ? -u : u) + ((h & 2) ? -v : v);
}

float RayTracer::PerlinNoise::noise(float x, float y) const {
    int X = (int)std::floor(x) & 255;
    int Y = (int)std::floor(y) & 255;

    x -= std::floor(x);
    y -= std::floor(y);

    float u = fade(x);
    float v = fade(y);

    int A = p[X] + Y;
    int B = p[X + 1] + Y;

    return lerp(v,
                lerp(u, grad(p[A], x, y), grad(p[B], x - 1, y)),
                lerp(u, grad(p[A + 1], x, y - 1), grad(p[B + 1], x - 1, y - 1)));
}