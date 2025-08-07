/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Tetrahedron
*/

#pragma once

#include <vector>
#include <memory>
#include "core/APrimitive.hpp"
#include "core/Point3D.hpp"
#include "core/Vector3D.hpp"
#include "core/Ray.hpp"
#include "rendering/Material.hpp"
#include "Triangle.hpp"

namespace RayTracer {

    /**
     * @class Tetrahedron
     * @brief Primitive composée de 4 triangles formant un tétraèdre.
     */
    class Tetrahedron : public APrimitive {
    public:
        /**
         * @brief Constructeur
         * @param center Centre du tétraèdre
         * @param size   Taille (longueur d'une arête)
         * @param mat    Matériau
         */
        Tetrahedron(const Math::Point3D& center, double size, const Material& mat);
        bool hits(const Ray& ray, double& tHit, HitRecord& rec) const override;
        AABB bounds() const override;

    private:
        std::vector<std::shared_ptr<APrimitive>> _faces;
        void generate(const Math::Point3D& center, double size, const Material& mat);
    };

} // namespace RayTracer
