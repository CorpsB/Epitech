/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** PostFX
*/

#include "../../include/rendering/PostFX.hpp"

#include <algorithm>

/**
 * @brief Clamp a scalar to the [0,1] range.
 * @param v Input value.
 * @return  `0` if `v < 0`, `1` if `v > 1`, otherwise `v`.
*/
float PostFX::clamp01(float v) {
    return v < 0.f ? 0.f : (v > 1.f ? 1.f : v);
}

/**
 * @brief Adjust contrast of a colour.
 * @param c         Input RGB colour (linear, unclamped).
 * @param contrast  1.0 leaves the colour unchanged; 
 *                  >1 increases contrast, <1 flattens it.
 * @return          Adjusted RGB colour (unclamped).
*/
Math::Vector3D PostFX::adjustContrast(const Math::Vector3D& c, float contrast) {
    return {
        clamp01((c.x - 0.5f) * contrast + 0.5f),
        clamp01((c.y - 0.5f) * contrast + 0.5f),
        clamp01((c.z - 0.5f) * contrast + 0.5f)
    };
}

/**
 * @brief Adjust saturation of a colour.
 * @param c     Input RGB colour (linear).
 * @param satF  Saturation factor (1.0 = original, 0.0 = grey).
 * @return      Adjusted RGB colour.
*/
Math::Vector3D PostFX::adjustSaturation(const Math::Vector3D& c, float satF) {
    float r = clamp01((float)c.x), g = clamp01((float)c.y), b = clamp01((float)c.z);
    float maxv = std::max({r, g, b});
    float minv = std::min({r, g, b});
    float l = (maxv + minv) * 0.5f;
    float s = (maxv == minv) ? 0.0f :
              (l < 0.5f ? (maxv - minv) / (maxv + minv)
                        : (maxv - minv) / (2.0f - maxv - minv));
    s = clamp01(s * satF);

    Math::Vector3D gray{l, l, l};
    return gray * (1.0f - s) + c * s;
}

/**
 * @brief Apply a simple filmic tone-mapping curve.
 * @param c Linear-space HDR RGB colour.
 * @return  Tone-mapped RGB colour clamped to [0,1].
 *
 * Current implementation uses the ACES™ approximation
 *    `c / (c + 1)`  (can be replaced by a more accurate curve later).
*/
Math::Vector3D PostFX::toneMap(const Math::Vector3D& c) {
    return {
        c.x / (1.0 + c.x),
        c.y / (1.0 + c.y),
        c.z / (1.0 + c.z)
    };
}

/**
 * @brief Radial vignette fall-off factor for pixel *(i,j)*.
 * @param i,j Pixel coordinates (0 … w-1, 0 … h-1).
 * @param w,h Frame-buffer dimensions.
 * @param strength  0 = no vignette, 1 = full darkening at the corners.
 * @return  Multiplicative factor ∈ [1-strength, 1].
*/
float PostFX::vignetteFactor(int i, int j, int w, int h, float strength) {
    float x = 2.0f * i / (w - 1) - 1.0f;
    float y = 2.0f * j / (h - 1) - 1.0f;
    float d = std::sqrt(x*x + y*y);
    return clamp01(1.0f - d * strength);
}

/**
 * @brief Execute the full post-processing pipeline on a frame-buffer.
 *
 * @param fb                Flat vector of RGB pixels, row-major, size = *w·h*.
 * @param w,h               Resolution in pixels.
 * @param contrast          Contrast factor (see @ref adjustContrast).
 * @param saturation        Saturation factor (see @ref adjustSaturation).
 * @param vignetteStrength  Strength of the vignette (see @ref vignetteFactor).
 *
 * Each pixel is processed in place:
 * `c → contrast → saturation → toneMap → vignette`.
*/
void PostFX::postProcess(std::vector<Math::Vector3D>& fb,
                         int w, int h,
                         float contrast,
                         float saturation,
                         float vignetteStrength)
{
    for (int j = 0; j < h; ++j) {
        for (int i = 0; i < w; ++i) {
            int idx = j * w + i;
            auto c = fb[idx];
            c = adjustContrast(c, contrast);
            c = adjustSaturation(c, saturation);
            c = toneMap(c);
            float v = vignetteFactor(i, j, w, h, vignetteStrength);
            fb[idx] = c * v;
        }
    }
}
