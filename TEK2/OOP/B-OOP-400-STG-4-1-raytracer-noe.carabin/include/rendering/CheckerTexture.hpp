/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** CheckerTexture
*/

/**
 * @file   CheckerTexture.hpp
 * @brief  Declares a 2-D procedural checkerboard texture. 
 * @author Cyrian Pittaluga
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * The texture alternates two user colours on a square grid.  
 * The grid frequency is controlled by the *scale* factor:
 * a larger scale produces smaller, more frequent checks.
 */


 #pragma once

 #include "Texture.hpp"
 #include <cmath>
 
 namespace RayTracer {
 
     /**
      * @class CheckerTexture
      * @brief  Procedural checkerboard pattern.
      *
      * Evaluates to colour **c1** or **c2** according to the parity of the
      * integer parts of *(u·scale)* and *(v·scale)*.  Anti-aliasing is left to
      * the caller (supersampling or filtering).
     */
     class CheckerTexture : public Texture {
         Math::Vector3D _c1;     ///< First colour (even squares).
         Math::Vector3D _c2;     ///< Second colour (odd  squares).
         float          _scale;  ///< Number of checks per unit UV length.
 
     public:
         /**
          * @brief Construct a checker texture.
          * @param c1    Colour of even checks.
          * @param c2    Colour of odd  checks.
          * @param scale Frequency of the pattern (≥ 1).
         */
         CheckerTexture(const Math::Vector3D& c1,
                        const Math::Vector3D& c2,
                        float scale);
 
         Math::Vector3D sample(float u, float v) const override;
     };
 
 }