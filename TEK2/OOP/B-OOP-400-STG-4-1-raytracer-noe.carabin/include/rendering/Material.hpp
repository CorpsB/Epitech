/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Material
*/

/**
 * @file   Material.hpp
 * @brief  Declares the physically-based material descriptor used by the renderer. 
 * @author Cyrian Pittaluga
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * A material bundles base colour (**albedo**), micro-surface parameters
 * (**roughness**, **metallic**), Fresnel-specular colour, optional
 * transparency / refraction index, an emission term, and an optional
 * diffuse texture map.  All values are expressed in linear space;
 * the shader interprets them according to a Disney / GGX BRDF.
*/

#pragma once

#include <string>
#include <memory>
#include "core/Vector3D.hpp"
#include "rendering/Texture.hpp"

namespace RayTracer {

  /**
     * @struct Material
     * @brief  Physically-based material parameters.
     *
     * Field summary  
     * | Field              | Meaning (linear space)                    |
     * |--------------------|-------------------------------------------|
     * | `name`             | Identifier for debugging / UI.            |
     * | `albedo`           | Base colour or *ρ<sub>diffuse</sub>*.     |
     * | `diffuseMap`       | Optional RGB texture replacing albedo.    |
     * | `roughness`        | [0,1] microsurface roughness (GGX α).     |
     * | `metallic`         | 0 = dielectric, 1 = pure metal.           |
     * | `specular`         | RGB specular F<sub>0</sub> for dielectrics|
     * | `transparency`     | 0 = opaque, 1 = fully transparent.        |
     * | `ior`              | Index of refraction when transparent.     |
     * | `emission`         | Self-illumination colour.                 |
     * | `emissionStrength` | Multiplier applied to `emission`.         |
    */
  struct Material {
      std::string name;                       ///< Readable material name.
      Math::Vector3D albedo;                  ///< Base diffuse colour.
      std::shared_ptr<Texture> diffuseMap;    ///< Optional diffuse texture.
      float roughness = 0.5f;                 ///< Surface roughness (GGX α).
      float metallic  = 0.0f;                 ///< Metalness factor.
      Math::Vector3D specular  {1.0,1.0,1.0}; ///< Specular F0 (dielectric).
      float transparency = 0.0f;              ///< 0 = opaque.
      float ior = 1.0f;                       ///< Refractive index.
      Math::Vector3D emission {0.0,0.0,0.0};  ///< Emissive colour.
      float emissionStrength = 1.0f;          ///< Emission multiplier.
  
      /** Default constructor creates a neutral grey, non-metallic material. */
      Material();

      /**
       * @brief Build a basic PBR material (no emission).
       * @param n  Name.
       * @param a  Albedo colour.
       * @param r  Roughness   [0,1].
       * @param m  Metalness   [0,1].
       * @param s  Specular colour (ignored if *m = 1*).
       * @param t  Transparency [0,1].
       * @param i  Index of refraction (used if *t > 0*).
      */
      Material(const std::string& n,
               const Math::Vector3D& a,
               float r,
               float m,
               const Math::Vector3D& s,
               float t,
               float i);

      /**
       * @brief Build a PBR material with an emission term.
       * @param n  Name.
       * @param a  Albedo colour.
       * @param r  Roughness [0,1].
       * @param m  Metalness [0,1].
       * @param s  Specular colour.
       * @param t  Transparency [0,1].
       * @param i  Index of refraction.
       * @param e  Emission colour (strength set to 1.0 by default).
      */
      Material(const std::string& n,
               const Math::Vector3D& a,
               float r,
               float m,
               const Math::Vector3D& s,
               float t,
               float i,
               const Math::Vector3D& e);
  };

} // namespace RayTracer