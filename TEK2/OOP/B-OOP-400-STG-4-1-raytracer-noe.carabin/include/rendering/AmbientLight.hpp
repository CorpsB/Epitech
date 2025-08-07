/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** AmbientLight.hpp
*/

/**
 * @file   AmbientLight.hpp
 * @brief  Declares the AmbientLight class: uniform ambient illumination.
 * @author Thibaut Louis
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * `AmbientLight` derives from `ALight` and overrides the type,
 * direction, and position methods to provide constant, scene-wide
 * ambient lighting.
*/

#pragma once
#include "ALight.hpp"

namespace RayTracer {

    /**
     * @class AmbientLight
     * @brief   Simple ambient light: same contribution everywhere.
    */
    class AmbientLight : public ALight {
    public:
        /**
         * @brief      Construct an ambient light.
         * @param intensity  Scalar ambient intensity.
        */
        explicit AmbientLight(double intensity);

        LightType type() const override;
        Math::Vector3D direction(const Math::Point3D& hitPoint) const override;
        Math::Point3D position(const Math::Point3D& hitPoint) const override;
    };

} // namespace RayTracer
