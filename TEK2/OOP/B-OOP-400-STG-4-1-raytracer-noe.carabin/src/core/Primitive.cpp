/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Primitive
*/

/**
 * @file APrimitive.cpp
 * @brief Implements the abstract primitive base class method(s) used in the raytracer pipeline.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * Provides shared functionality for all geometric primitives, including access to the associated material.
 */

#include "../../include/core/APrimitive.hpp"

const RayTracer::Material& RayTracer::APrimitive::getMaterial() const {
    return material;
}
