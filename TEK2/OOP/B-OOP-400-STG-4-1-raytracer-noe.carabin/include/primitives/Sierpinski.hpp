/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Sierpinski
*/

#pragma once

#include <vector>
#include <memory>
#include <limits>
#include <cmath>
#include "core/APrimitive.hpp"
#include "core/Point3D.hpp"
#include "core/Vector3D.hpp"
#include "core/Ray.hpp"
#include "rendering/Material.hpp"
#include "Tetrahedron.hpp"

namespace RayTracer {

    /**
     * @class Sierpinski
     * @brief Représente un tétraèdre de Sierpinski récursif.
     */
    class Sierpinski : public APrimitive {
    public:
        Sierpinski(const Math::Point3D& center, double size, int depth, const Material& mat);
        bool hits(const Ray& ray, double& tHit, HitRecord& rec) const override;
        AABB bounds() const override;

    private:
        std::vector<std::shared_ptr<APrimitive>> _children;
        void generate(const Math::Point3D& center, double size, int depth);
    };

} // namespace RayTracer
