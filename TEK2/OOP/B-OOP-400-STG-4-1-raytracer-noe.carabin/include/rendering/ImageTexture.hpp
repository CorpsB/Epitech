/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** ImageTexture
*/

/**
 * @file   ImageTexture.hpp
 * @brief  Declares a texture that samples colour data from an image file. 
 * @author Cyrian Pittaluga
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * The texture loads an 8-bit RGB(A) bitmap (PPM / PNG / etc.) during
 * construction and stores the raw byte buffer.  Sampling converts UV
 * coordinates to pixel indices, applies wrapping, and returns a
 * linear-space RGB triple in **[0,1]³**.
 */


 #pragma once

 #include "rendering/Texture.hpp"
 #include "core/Vector3D.hpp"
 #include <vector>
 #include <string>
 #include <istream>
 
 namespace RayTracer {
 
     /**
      * @class ImageTexture
      * @brief  Texture backed by an image file.
      *
      * Supports generic 8-bit images with 1–4 channels.  The constructor
      * parses the file (PPM “P6” helper included; other formats delegated to
      * stb_image if available) and stores an interleaved byte buffer.
      *
      * UV lookup is **wrap-repeat**: coordinates outside [0,1] are mapped
      * with `u = u − floor(u)` and the same for `v`.
     */
     class ImageTexture : public Texture {
     public:
         explicit ImageTexture(const std::string &filename);
 
         Math::Vector3D sample(float u, float v) const override;
 
     private:
         static void skipComments(std::istream &is);
 
         std::vector<unsigned char> _data;  ///< Interleaved pixel data (RGB[A]).
         int _width = 0;                    ///< Image width  in pixels.
         int _height = 0;                   ///< Image height in pixels.
         int _channels = 0;                 ///< 1=Grey, 3=RGB, 4=RGBA.
     };
 
 }