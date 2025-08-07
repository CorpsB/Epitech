/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** ILight.hpp
*/

/**
 * @file   ILight.hpp
 * @brief  Abstract interface for all light sources in the path tracer.
 * @author Thibaut Louis
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * This header defines the pure-virtual base class `ILight` used to
 * represent different types of light sources. Subclasses provide
 * implementations for ambient, directional, point, and other light types
 * by overriding the methods declared here:
 *  - *type()*      : returns the light’s enum type;
 *  - *intensity()* : returns the scalar power of the light;
 *  - *direction()* : returns the normalized direction vector from a hit point;
 *  - *position()*  : returns the world-space position of the light (if applicable).
*/

#pragma once
#include "../core/Point3D.hpp"
#include "../core/Vector3D.hpp"

namespace RayTracer {

    /**
     * @enum LightType
     * @brief Enumerates the supported light source categories.
    */
    enum class LightType { Ambient, Directional, Point };

    /**
     * @class ILight
     * @brief Pure-virtual interface for scene light sources.
     *
     * All light implementations must inherit from `ILight` and provide
     * concrete behavior for querying type, intensity, direction, and
     * position relative to a surface interaction point.
    */
    class ILight {
    public:
        virtual ~ILight() = default;

        /**
         * @brief Get the type of this light.
         * @return One of the values in @ref LightType.
        */
        virtual LightType type() const = 0;

        /**
         * @brief Get the scalar intensity (power) of the light.
         * @return Intensity value, typically in linear radiometric units.
        */
        virtual double intensity() const = 0;

        /**
         * @brief Compute the incoming light direction at a surface point.
         *
         * For directional lights, this is constant. For point lights,
         * this is the normalized vector from the hit point toward the light.
         *
         * @param hitPoint  The world-space location of the surface interaction.
         * @return          Normalized direction vector pointing toward the light.
        */
        virtual Math::Vector3D direction(const Math::Point3D& hitPoint) const = 0;

        /**
         * @brief Retrieve the light’s world-space position if applicable.
         *
         * Ambient and directional lights may return a dummy value (e.g., origin).
         * Point lights return their actual position.
         *
         * @param hitPoint  The world-space location of the surface interaction.
         * @return          World-space position of the light source.
        */
        virtual Math::Point3D position(const Math::Point3D& hitPoint) const = 0;
    };
}
