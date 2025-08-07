/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** DirectionalLight.hpp
*/

/**
 * @file   DirectionalLight.hpp
 * @brief  Declares the DirectionalLight class: parallel‐ray source.  
 * @author Thibaut Louis
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * `DirectionalLight` derives from `ALight` and stores a normalized
 * direction vector.  It provides infinite‐distance lighting like
 * sunlight.
*/

#pragma once
#include "ALight.hpp"
#include "../core/Vector3D.hpp"

namespace RayTracer {

/**
 * @class DirectionalLight
 * @brief  Parallel rays from a given direction (e.g. sunlight).
*/
    class DirectionalLight : public ALight {
    public:
         /**
         * @brief      Construct a directional light.
         * @param dir        Incoming light direction (will be normalized).
         * @param intensity  Scalar intensity.
        */
        DirectionalLight(const Math::Vector3D& dir, double intensity);

        LightType               type()      const override;
        Math::Vector3D          direction(const Math::Point3D& hitPoint) const override;
        Math::Point3D           position(const Math::Point3D& hitPoint)  const override;

    private:
        Math::Vector3D _dir;    ///< Normalized light direction.
    };

} // namespace RayTracer
