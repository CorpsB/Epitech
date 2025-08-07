/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Camera.hpp
*/

/**
 * @file   Camera.hpp
 * @brief  Declares the pin-hole / thin-lens camera used by the ray tracer. 
 * @author Cyrian Pittaluga
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * The camera builds a local orthonormal basis (u-v-w), computes the view-plane
 * corners, and can optionally simulate depth-of-field via a finite lens
 * (aperture > 0).  The public method @ref Camera::ray generates primary rays
 * through normalized screen coordinates *(s,t)* in [0,1]².
*/

#pragma once

#include "core/Point3D.hpp"
#include "core/Vector3D.hpp"
#include "core/Ray.hpp"

#include <cmath>
#include <random>

namespace RayTracer {

    /**
     * @class Camera
     * @brief  Simple pin-hole / thin-lens camera model.
     *
     * The constructor pre-computes the four corner vectors of the view window.
     * With *aperture = 0* it behaves like a classic pin-hole camera.
     * With *aperture > 0* it samples the lens disk to render depth-of-field.
    */
    class Camera {
    public:
        Math::Point3D  origin;       ///< Camera position in world space.
        Math::Point3D  lower_left;   ///< Lower-left corner of the viewport.
        Math::Vector3D horizontal;   ///< Horizontal span of the viewport.
        Math::Vector3D vertical;     ///< Vertical   span of the viewport.
        Math::Vector3D u, v, w;      ///< Camera orthonormal basis.
        double lens_radius;          ///< Radius of the thin lens (= aperture / 2).
        int height;                  ///< Image height  (pixels).
        int width;                   ///< Image width   (pixels).

        /**
         * @brief Build a camera looking from *lookfrom* towards *lookat*.
         *
         * @param lookfrom      Camera position.
         * @param lookat        Target point (center of screen).
         * @param vup           “View-up” vector (usually +Y).
         * @param vfov          Vertical field of view *(degrees)*.
         * @param aspect        Aspect ratio  *width / height*.
         * @param aperture      Lens diameter (0 = pin-hole).
         * @param focus_dist    Distance from origin to the focal plane.
         * @param cam_height    Image height  in pixels (default 800).
         * @param cam_width     Image width   in pixels (default 800).
        */
        Camera(const Math::Point3D& lookfrom,
               const Math::Point3D& lookat,
               const Math::Vector3D& vup,
               double vfov,
               double aspect,
               double aperture = 0.0,
               double focus_dist = 1.0,
               int cam_height = 800,
               int cam_width = 800);

        Ray ray(double s, double t) const;

    private:
        static Math::Vector3D random_in_unit_disk();
    };

}