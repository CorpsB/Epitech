/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** DirectionalLight.cpp
*/

#include "../../include/rendering/DirectionalLight.hpp"

    /**
     * @brief Construct a directional light.
     * @param dir        Incoming light direction (will be normalized).
     * @param intensity  Scalar intensity.
    */
   RayTracer::DirectionalLight::DirectionalLight(const Math::Vector3D& dir, double intensity)
    : ALight(intensity)
    , _dir(dir.normalized())
    {}

    /**
     * @brief  Return this light’s type.
     * @return LightType::Directional
    */
   RayTracer::LightType RayTracer::DirectionalLight::type() const
    {
        return LightType::Directional;
    }

    /**
     * @brief  Compute the incoming light direction at a point.
     * @param  hitPoint  Surface point (ignored for directional).
     * @return Normalized direction vector.
    */
    Math::Vector3D RayTracer::DirectionalLight::direction(const Math::Point3D&) const
    {
        return _dir;
    }

    /**
     * @brief  Get the light’s position.
     * @param  hitPoint  Surface point (ignored for directional).
     * @return origin (unused).
    */
    Math::Point3D RayTracer::DirectionalLight::position(const Math::Point3D&) const
    {
        return Math::Point3D{0, 0, 0};
    }
