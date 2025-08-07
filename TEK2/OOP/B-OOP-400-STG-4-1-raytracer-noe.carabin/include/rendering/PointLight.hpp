/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** PointLight.hpp
*/

/**
 * @file   PointLight.hpp
 * @brief  Declares the PointLight class: point‐source emitter.  
 * @author Thibaut Louis
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * `PointLight` derives from `ALight` and stores a world‐space position.
 * It emits equally in all directions with inverse‐square attenuation.
*/

#pragma once
#include "ALight.hpp"
#include "../core/Point3D.hpp"
#include "../core/Vector3D.hpp"

namespace RayTracer {

/**
 * @class PointLight
 * @brief  Emits equally in all directions from a point in space.
 */
    class PointLight : public ALight {
    public:
        /**
         * @brief      Construct a point light.
         * @param position   World-space location of the light.
         * @param intensity  Scalar intensity.
        */
        PointLight(const Math::Point3D& position, double intensity);

        LightType               type()      const override;
        Math::Vector3D          direction(const Math::Point3D& hitPoint) const override;
        Math::Point3D           position(const Math::Point3D& hitPoint)  const override;

    private:
        Math::Point3D _pos;     ///< World-space light position.
    };

} // namespace RayTracer
