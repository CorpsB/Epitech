/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** ShadowShading
*/

#include "../../include/rendering/ShadowShading.hpp"
#include "../../include/rendering/Skybox.hpp"
#include <cmath>
#include <limits>
#include <random>
#include <algorithm>

/**
 * @brief Clamp a scalar to the inclusive range [0,1].
 * @param v Input value.
 * @return  0 if *v < 0*; 1 if *v > 1*; otherwise *v*.
*/
double RayTracer::clamp01(double v) {
    return v < 0.0 ? 0.0 : (v > 1.0 ? 1.0 : v);
}

/**
 * @brief Generate a single uniform random number in [0,1).
 * @return Random double ∈ [0,1).
 *
 * Uses a static thread-local `std::mt19937` engine and
 * `std::uniform_real_distribution<double>(0.0, 1.0)`.
*/
double RayTracer::rand01() {
    thread_local static std::mt19937 gen(std::random_device{}());
    thread_local static std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(gen);
}

/**
 * @brief Cosine-weighted hemisphere sampling around a shading normal.
 *
 * @param N_shading Shading‐space normal (unit length).
 * @param pdf       [out] Probability density function value of the sample.
 * @return          Sampled outgoing direction (unit length, world space).
 *
 * The function draws two random numbers, maps them to polar coordinates
 * (θ, φ) with PDF = cos θ / π, rotates the vector into world space, and
 * sets `pdf = cos θ / π`.
*/
Math::Vector3D RayTracer::sampleHemisphere(const Math::Vector3D &N_shading, double &pdf) {
    double u = rand01();
    double v = rand01();
    double r_sample = std::sqrt(u);
    double theta_sample = 2.0 * M_PI * v;
    double x = r_sample * std::cos(theta_sample);
    double y = r_sample * std::sin(theta_sample);
    double z_local = std::sqrt(std::max(0.0, 1.0 - u));

    Math::Vector3D up = std::fabs(N_shading.z) < 0.999 ? Math::Vector3D{0,0,1} : Math::Vector3D{1,0,0};
    Math::Vector3D T = N_shading.cross(up);
    double t_len = T.length();
    if (t_len > 1e-8) {
        T *= (1.0 / t_len);
    } else {
        T = (std::fabs(N_shading.x) > 0.999 ? Math::Vector3D{0,1,0} : Math::Vector3D{1,0,0}).cross(N_shading);
        t_len = T.length();
        if (t_len > 1e-8) T *= (1.0 / t_len);
    }

    Math::Vector3D B = N_shading.cross(T);
    double b_len = B.length(); if (b_len > 1e-8) B *= (1.0 / b_len);

    Math::Vector3D sample = T*x + B*y + N_shading*z_local;
    double sample_len = sample.length();
    if (sample_len > 1e-8) sample *= (1.0 / sample_len);

    pdf = z_local / M_PI;
    if (N_shading.dot(sample) < 0.0 && pdf > 1e-7) pdf = 0.0;
    return sample;
}