/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Primitive
*/

#pragma once

#include "core/Ray.hpp"
#include "core/Point3D.hpp"
#include "core/Vector2D.hpp"
#include "core/Vector3D.hpp"
#include "rendering/Material.hpp"
#include "IPrimitive.hpp"

namespace RayTracer {

    /** Keeps the same HitRecord (unchanged). */
    struct HitRecord {
        double t {};
        Math::Point3D  point {};
        Math::Vector3D normal {};
        Material material {};
        Math::Vector3D color {};
        Math::Vector2D uv {};
    };

    /**
     * @class Primitive
     * @brief Abstract base that stores the shared @ref Material.
     *
     * Derives from IPrimitive so it can be used polymorphically anywhere
     * an interface pointer is expected.
     */
    class APrimitive : public IPrimitive {
    protected:
        Material material;   ///< Shared by every concrete primitive.

    public:
        explicit APrimitive(const Material& mat) : material(mat) {}
        ~APrimitive() override = default;

        /** Accessor kept as-is. */
        const Material& getMaterial() const;
    };

} // namespace RayTracer
