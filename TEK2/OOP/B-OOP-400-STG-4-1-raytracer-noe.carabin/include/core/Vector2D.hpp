/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Vector2D
*/

#pragma once

/**
 * @file Vector2D.hpp
 * @brief Defines a 2D vector structure used for texture coordinates or screen-space math operations.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * This structure is typically used for representing 2D data such as texture UVs,
 * screen-space positions, or other planar values. It contains basic storage and
 * initialization for two float components (x, y).
 */

namespace Math {
    /**
     * @struct Vector2D
     * @brief Represents a 2D vector or coordinate pair.
     *
     * Used for operations involving two-dimensional geometry, such as UV mapping.
     */
    struct Vector2D {
        float x = 0.0f; ///< X component of the vector
        float y = 0.0f; ///< Y component of the vector

        /**
         * @brief Default constructor. Initializes both components to 0.
         */
        Vector2D() = default;
        /**
         * @brief Construct a vector with specified coordinates.
         * @param _x X component
         * @param _y Y component
         */
        Vector2D(float _x, float _y) : x(_x), y(_y) {}
    };
}