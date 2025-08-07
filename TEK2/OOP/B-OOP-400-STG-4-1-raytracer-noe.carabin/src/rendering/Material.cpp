/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Material
*/

#include "../../include/rendering/Material.hpp"

RayTracer::Material::Material()
    : name{},
      albedo{0,0,0},
      diffuseMap{nullptr},
      roughness{0},
      metallic{0},
      specular{0,0,0},
      transparency{0},
      ior{1},
      emission{0,0,0},
      emissionStrength{1.0f}
{}

RayTracer::Material::Material(const std::string& n,
    const Math::Vector3D& a,
    float r,
    float m,
    const Math::Vector3D& s,
    float t,
    float i)
    : name(n),
      albedo(a),
      diffuseMap(nullptr),
      roughness(r),
      metallic(m),
      specular(s),
      transparency(t),
      ior(i),
      emission{0,0,0},
      emissionStrength{1.0f}
{}

RayTracer::Material::Material(const std::string& n,
    const Math::Vector3D& a,
    float r,
    float m,
    const Math::Vector3D& s,
    float t,
    float i,
    const Math::Vector3D& e)
    : name(n),
      albedo(a),
      diffuseMap(nullptr),
      roughness(r),
      metallic(m),
      specular(s),
      transparency(t),
      ior(i),
      emission(e),
      emissionStrength{1.0f}
{}