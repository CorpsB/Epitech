/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** SceneParser
*/

/**
 * @file SceneParser.hpp
 * @brief Declares functions to load scenes from configuration files (.cfg) into a Scene object.
 * @author Cyrian PITTALUGA
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * These functions parse LibConfig-based configuration files and populate a `Scene` object
 * with cameras, primitives, lights, and materials. The recursive loader supports `include`
 * or nested file references, while the base loader parses a single scene file.
 */

#pragma once

#include <string>
#include <set>

#include "rendering/Scene.hpp"

namespace RayTracer {

    /**
     * @brief Loads a single scene file (non-recursive).
     *
     * This function parses one configuration file and fills the output scene with its contents.
     *
     * @param filename Path to the scene configuration file
     * @param outScene Scene object to populate
     * @param debug Enables debug mode output
     * @return true on success, false on failure
     */
    bool loadScene(const std::string &filename, Scene &outScene, bool debug);
} // namespace RayTracer
