/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Raytracer
*/

/**
 * @file Raytracer.cpp
 * @brief Implements the main execution flow of the Raytracer application, including argument parsing, scene loading, rendering, and post-processing.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * This file defines the logic for launching the raytracer: parsing CLI arguments, building the scene,
 * initializing the BVH, running the render loop (optionally with SFML preview), applying post-effects,
 * and exporting the final image as a PPM file. Errors encountered during execution throw a custom exception.
 */

#include "../../include/core/Raytracer.hpp"
#include "../../include/core/Visualizer.hpp"
#include "../../include/rendering/Skybox.hpp"

Raytracer::Raytracer(int ac, char **av)
{
    _ac = ac;
    _av = av;
}

void Raytracer::run() {
    if (!Utils::checkUsage(_ac, _av))
        exit(84);

    int threads = 1;

    try {
        threads = Utils::parseThreads(_ac, _av);
    } catch(const std::exception& e) {
        throw Raytracer::Error("Incorect thread argument. Negative or Null.");
    }

    bool showProgress = Utils::parseProgress(_ac, _av);
    auto params = Utils::getRenderParams(_ac, _av);
    bool debug = Utils::isDebugModeEnable(_ac, _av);
    #ifdef USE_SFML
        Viz::VizMode mode = Viz::parseVizMode(_ac, _av);
    #else
        [[maybe_unused]]Viz::VizMode mode = Viz::VizMode::DEFAULT;
    #endif

    omp_set_num_threads(threads);

    auto cam = Utils::createCamera(params);
    RayTracer::Scene scene(cam);
    if (!Utils::loadSceneOrExit(_av[1], scene, debug))
        throw Raytracer::Error("Failed to load scene.");

    cam = scene.camera;
    params.H = cam.height;
    params.W = cam.width;

    scene.bvhRoot = Utils::buildBVH(scene.objects);

    std::vector<Math::Vector3D> framebuffer;
    #ifdef USE_SFML
        if (mode != Viz::VizMode::DEFAULT) {
            framebuffer = Viz::renderImageSFML(scene, params, mode, showProgress);
        } else
    #endif
    {
        framebuffer = Utils::renderImage(scene, params, showProgress);
    }
    PostFX::postProcess(
            framebuffer,
            params.W, params.H,
            /*contrast=*/1.6f,
            /*saturation=*/8.0f,
            /*vignetteStrength=*/0.0f
    );
    std::vector<Math::Vector3D> denoised;
    Utils::denoise(framebuffer, denoised, params.W, params.H);
    Utils::writePPM(framebuffer, params.W, params.H);
}

Raytracer::~Raytracer()
{
}
