/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Skybox
*/

/**
 * @file   Skybox.hpp
 * @brief  Declares a minimal PPM-based skybox loader and sampler. 
 * @author Cyrian Pittaluga
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * The module provides two ways to obtain background radiance for rays that
 * miss all geometry:
 *  1. **Textured skybox** – a single lat-long PPM image loaded at start-up;
 *  2. **Procedural gradient** – a simple horizon-to-zenith blend.
 *
 * The active mode depends on whether @ref initializeSkybox succeeds.
 */

 #pragma once

 #include "core/Vector3D.hpp"
 #include <string>
 #include <vector>
 
 /* π helpers (in case <cmath> did not provide them) */
 #ifndef M_PI
 #define M_PI 3.14159265358979323846
 #endif
 
 #ifndef M_PI_2
 #define M_PI_2 (M_PI / 2.0)
 #endif
 
 #define SKYBOX_TEXTURE_SCALE 1.0    ///< Optional UV scale for tiled panoramas.
 
 namespace Skybox {
 
     /**
      * @struct PPMImage
      * @brief  Raw 8-bit RGB image loaded from an ASCII or binary PPM file.
      *
      * The pixel buffer is interleaved **RGBRGB…** with one byte per channel.
      * No gamma conversion is applied—values are returned in linear space
      * by dividing by 255.0.
     */
     struct PPMImage {
         int width  = 0;                       ///< Image width  in pixels.
         int height = 0;                       ///< Image height in pixels.
         std::vector<unsigned char> data;      ///< Interleaved RGB bytes.
 
         bool isLoaded() const;
         Math::Vector3D getColorAtTexel(int x, int y) const;
         Math::Vector3D sample(double u, double v) const;
     };
 
     /** @internal Global skybox texture used when sampling rays. */
     namespace detail {
         extern PPMImage globalSkyboxTexture;
     }
 
     bool loadPPMFile(const std::string& filepath, PPMImage& image);
     bool initializeSkybox(const std::string& filepath);
     Math::Vector3D skyGradient(const Math::Vector3D& unitDir);
 
 } // namespace Skybox