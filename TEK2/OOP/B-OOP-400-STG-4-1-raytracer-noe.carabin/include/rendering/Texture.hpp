/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Texture
*/

/**
 * @file   Texture.hpp
 * @brief  Declares the abstract base class for all 2-D textures. 
 *         (Solid colour, checkerboard, image maps, procedural noise, etc.) 
 * @author Cyrian Pittaluga
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * A texture supplies a single function, @ref Texture::sample,
 * which converts UV coordinates *(u,v)* into a linear-space RGB colour.
 * Concrete subclasses implement the sampling logic as needed.
*/

#pragma once

#include "core/Vector3D.hpp"

namespace RayTracer {

    /**
     * @struct Texture
     * @brief  Abstract interface for UV-mapped colour sources.
     *
     * All textures are immutable and thread-safe; the renderer may call
     * @ref sample concurrently from multiple threads.
    */
    struct Texture {
        virtual ~Texture() = default;

        /**
         * @brief  Sample the texture at UV coordinates.
         * @param  u Horizontal coordinate (0 → left, 1 → right, may wrap).
         * @param  v Vertical   coordinate (0 → bottom, 1 → top,  may wrap).
         * @return  Linear-space RGB colour in **[0,1]³**.
        */
        virtual Math::Vector3D sample(float u, float v) const = 0;
    };
}