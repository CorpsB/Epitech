/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** PointLight.cpp
*/

#include "../../include/rendering/PointLight.hpp"

    /**
     * @brief Construct a point light.
     * @param position   World-space location of the light.
     * @param intensity  Scalar intensity.
    */
    RayTracer::PointLight::PointLight(const Math::Point3D& position, double intensity)
    : ALight(intensity)
    , _pos(position)
    {}

    /**
     * @brief  Return this light’s type.
     * @return LightType::Point
    */
    RayTracer::LightType RayTracer::PointLight::type() const
    {
        return LightType::Point;
    }

    /**
     * @brief  Compute the incoming light direction at a point.
     * @param  hitPoint  Surface intersection point.
     * @return Normalized vector from surface point to light.
    */
    Math::Vector3D RayTracer::PointLight::direction(const Math::Point3D& hitPoint) const
    {
        return (_pos - hitPoint).normalized();
    }

    /**
     * @brief  Get the light’s position.
     * @param  hitPoint  Surface point (ignored for point lights).
     * @return World-space light position.
    */
    Math::Point3D RayTracer::PointLight::position(const Math::Point3D&) const
    {
        return _pos;
    }
