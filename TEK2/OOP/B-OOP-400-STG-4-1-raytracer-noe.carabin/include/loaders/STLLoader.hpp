/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** STLLoader.hpp
*/

/**
 * @file STLLoader.hpp
 * @brief Declares a loader class for importing 3D models from STL files into Mesh objects.
 * @author Cyrian PITTALUGA
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * This utility class parses binary or ASCII STL files and converts their triangle data
 * into a Mesh representation compatible with the raytracer’s geometry pipeline.
 */

#pragma once
#include <string>
#include "rendering/Mesh.hpp"

namespace RayTracer {
    /**
     * @class STLLoader
     * @brief Utility class for importing STL geometry files.
     *
     * Provides a static function to read triangle meshes from STL format,
     * either in ASCII or binary, and return them as a `Mesh` object.
     */
    class STLLoader {
    public:
        /**
         * @brief Loads an STL file and returns its geometry as a Mesh.
         * @param filename Path to the STL file to load
         * @return Mesh object containing the parsed triangle data
         * @throws Raytracer::Error if the file is missing or malformed
         */
        static Mesh load(const std::string& filename);
    };
} // namespace RayTracer
