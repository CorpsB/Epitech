/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** ALight.hpp
*/

/**
 * @file   ALight.hpp
 * @brief  Abstract base class partially implementing the ILight interface.
 * @author Thibaut Louis
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * Defines `ALight`, which stores the common `intensity` property and
 * fulfills the `intensity()` method of `ILight`.  Concrete lights
 * derive from this to implement type, direction, and position.
*/

#pragma once
#include "ILight.hpp"

namespace RayTracer {

    class ALight : public ILight {
    protected:
        double _intensity;  ///< Scalar light power.
    public:
        /**
         * @brief      Construct with given intensity.
         *  @param i    Initial light intensity.
        */
        explicit ALight(double i)
          : _intensity(i)
        {}
        double intensity() const override { return _intensity; }
    };
}
