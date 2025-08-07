/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** AmbientLight.cpp
*/

#include "../../include/rendering/AmbientLight.hpp"

    /**
     * @brief Construct an ambient light.
     * @param intensity  Scalar ambient intensity.
    */
   RayTracer::AmbientLight::AmbientLight(double intensity)
    : ALight(intensity)
    {}

    /**
     * @brief  Return this light’s type.
     * @return LightType::Ambient
    */
   RayTracer::LightType RayTracer::AmbientLight::type() const
    {
        return LightType::Ambient;
    }

    /**
     * @brief  Compute the incoming light direction at a point.
     * @param  hitPoint  Surface point (ignored for ambient).
     * @return Zero vector (no specific direction).
    */
    Math::Vector3D RayTracer::AmbientLight::direction(const Math::Point3D&) const
    {
        return Math::Vector3D{0, 0, 0};
    }

    /**
     * @brief  Get the light’s position.
     * @param  hitPoint  Surface point (ignored for ambient).
     * @return origin (unused).
    */
    Math::Point3D RayTracer::AmbientLight::position(const Math::Point3D&) const
    {
        return Math::Point3D{0, 0, 0};
    }
