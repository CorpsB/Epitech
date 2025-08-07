/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Utils
*/

/**
 * @file Utils.hpp
 * @brief Utility functions and structures for raytracer configuration, rendering and post-processing.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * This file centralizes common helper functions used across the raytracer, including
 * argument parsing, progress display, framebuffer post-processing, BVH construction,
 * and simple color operations.
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <memory>
#include <omp.h>

#include "Raytracer.hpp"
#include "rendering/Camera.hpp"
#include "rendering/Scene.hpp"
#include "rendering/BVH.hpp"
#include "loaders/SceneParser.hpp"
#include "rendering/ShadowShading.hpp"
#include "core/APrimitive.hpp"

namespace Utils {

    /**
     * @struct RenderParams
     * @brief Stores render configuration parameters.
     */
    struct RenderParams {
        int W;          ///< Image width in pixels
        int H;          ///< Image height in pixels
        int spp;        ///< Samples per pixel
        int max_depth;  ///< Maximum recursion depth for rays
        bool fast;      ///< Enables fast rendering mode (if applicable)
    };

    /**
     * @brief Clamp a float to the [0, 1] range.
     * @param v Input value
     * @return Clamped value
     */
    float clamp01(float v);

    /**
     * @brief Computes a 3D point on an orbital camera arc.
     * @param center The center of the orbit
     * @param radius Radius of the orbit
     * @param yawDeg Horizontal rotation in degrees
     * @param pitchDeg Vertical rotation in degrees
     * @return Computed point in space
     */
    Math::Point3D orbit(const Math::Point3D& center, double radius,
                               double yawDeg, double pitchDeg);

    /**
     * @brief Validates the command-line argument count.
     * @param argc Argument count
     * @param argv Argument values
     * @return true if usage is valid
     */
    bool checkUsage(int argc, char* argv[]);

    /**
     * @brief Parses thread count from CLI arguments.
     * @param argc Argument count
     * @param argv Argument values
     * @return Number of threads to use
     */
    int parseThreads(int argc, char* argv[]);

    /**
     * @brief Determines whether to display a progress bar.
     * @param argc Argument count
     * @param argv Argument values
     * @return true if progress display is enabled
     */
    bool parseProgress(int argc, char* argv[]);

    /**
     * @brief Extracts render parameters from command-line arguments.
     * @param argc Argument count
     * @param argv Argument values
     * @return RenderParams struct
     */
    RenderParams getRenderParams(int argc, char* argv[]);

    /**
     * @brief Check if debug mode is enabled through CLI args.
     * @param argc Argument count
     * @param argv Argument values
     * @return true if debug mode is active
     */
    bool isDebugModeEnable(int argc, char* argv[]);

    /**
     * @brief Prints current rendering settings to standard output.
     * @param p The render parameters
     * @param debug Whether debug mode is enabled
     */
    void printSettings(const RenderParams& p, bool debug);

    /**
     * @brief Loads a scene from file, or exits on failure.
     * @param cfg Path to scene config file
     * @param scene Scene to populate
     * @param debug Whether to show debug info
     * @return true on success
     */
    bool loadSceneOrExit(const char* cfg, RayTracer::Scene& scene, bool debug);

    /**
     * @brief Prints a terminal progress bar for rendering.
     * @param percent Completion percentage (0–100)
     * @param totalRays Total number of rays traced
     * @param start Start time of rendering
     */
    void PrintProgressBar(int percent, long long totalRays, const std::chrono::steady_clock::time_point &start);

    /**
     * @brief Extracts raw pointers to primitives from shared_ptr objects.
     * @tparam Ptr Type of smart pointer (e.g., std::shared_ptr)
     * @param objs Vector of smart pointers to primitives
     * @return Vector of raw pointers
     */
    template<typename Ptr>
    inline std::vector<const RayTracer::APrimitive*>
    collectPrimitives(const std::vector<Ptr>& objs)
    {
        std::vector<const RayTracer::APrimitive*> ptrs;
        ptrs.reserve(objs.size());
        for (const auto& o : objs)
            ptrs.push_back(o.get());
        return ptrs;
    }

    /**
     * @brief Builds a BVH from a list of smart pointers to primitives.
     * @tparam Ptr Smart pointer type
     * @param objs List of primitives
     * @return Unique pointer to the constructed BVH root
     */
    template<typename Ptr>
    inline std::unique_ptr<RayTracer::BVHNode>
    buildBVH(const std::vector<Ptr>& objs)
    {
        auto ptrs = collectPrimitives(objs);
        return RayTracer::buildBVH(ptrs);
    }

    /**
     * @brief Creates a camera from render parameters.
     * @param p Rendering parameters
     * @return Camera instance
     */
    RayTracer::Camera createCamera(const RenderParams& p);

    /**
     * @brief Performs the raytracing process and produces the framebuffer.
     * @param scene The scene to render
     * @param p Rendering parameters
     * @param showProgress Whether to show a progress bar
     * @return A framebuffer of color values
     */
    std::vector<Math::Vector3D>
    renderImage(const RayTracer::Scene& scene,
                const RenderParams& p,
                bool showProgress);

    /**
     * @brief Adjusts the contrast of a color.
     * @param c Original color
     * @param contrast Contrast factor
     * @return Adjusted color
     */
    Math::Vector3D adjustContrast(const Math::Vector3D& c, float contrast);

    /**
     * @brief Adjusts the saturation of a color.
     * @param c Original color
     * @param satF Saturation factor
     * @return Adjusted color
     */
    Math::Vector3D adjustSaturation(const Math::Vector3D& c, float satF);

    /**
     * @brief Applies contrast and saturation post-processing to the framebuffer.
     * @param fb Framebuffer to modify
     * @param contrast Contrast factor
     * @param saturation Saturation factor
     */
    void postProcess(std::vector<Math::Vector3D>& fb, float contrast, float saturation);

    /**
     * @brief Writes the framebuffer to a .ppm image file.
     * @param fb Framebuffer
     * @param w Image width
     * @param h Image height
     */
    void writePPM(const std::vector<Math::Vector3D>& fb, int w, int h);

    /**
     * @brief Applies a basic denoising algorithm to the framebuffer.
     * @param in Input framebuffer
     * @param out Output (denoised) framebuffer
     * @param width Image width
     * @param height Image height
     */
    void denoise(const std::vector<Math::Vector3D>& in,
        std::vector<Math::Vector3D>& out,
        int width, int height);
} // namespace Utils
