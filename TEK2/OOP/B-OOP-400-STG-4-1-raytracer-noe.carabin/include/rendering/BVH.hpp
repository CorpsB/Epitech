/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** BVH
*/

/**
 * @file   BVH.hpp
 * @brief  Declares the axis-aligned bounding box (AABB) and the BVH node used
 *         for ray-tracing acceleration. 
 * @author Cyrian Pittaluga
 * @version 1.0
 * @date    2025-05
 *
 * @details
 * This header provides:
 *  - the AABB structure with a fast “slab” intersection routine,
 *  - the helper function `surrounding_box()`,
 *  - the BVHNode class plus the `buildBVH()` factory that assembles a
 *    balanced tree from a list of primitives.
 */

 #pragma once

 #include <memory>
 #include <vector>
 #include <algorithm>
 #include <limits>
 
 #include "core/Ray.hpp"
 #include "core/APrimitive.hpp"
 #include "core/Point3D.hpp"
 #include "core/Vector3D.hpp"
 
 namespace RayTracer {
 
     using Float = double;   ///< Single floating-point type used by the engine.
 
     /**
      * @struct AABB
      * @brief  Axis-aligned bounding box.
      *
      * The box is defined by two opposite corners `min` and `max`
      * in world coordinates.  
      * The **hitFast** method implements a branch-free slab test that expects
      * the caller to pre-compute the inverse ray direction and the sign bits.
     */
     struct AABB {
         Math::Point3D min;  ///< Lower corner  (x-, y-, z-).
         Math::Point3D max;  ///< Upper corner  (x+,  y+,  z+).
 
         /** Builds an *empty* box (`min > max`). */
         AABB();
         
         /**
          * Builds a box from two opposite corners.
          * @param a Lower corner.
          * @param b Upper corner.
         */
         AABB(const Math::Point3D& a, const Math::Point3D& b);
 
         bool hitFast(const Math::Point3D &orig, const Float invDir[3], const int dirNeg[3], Float &tmin, Float &tmax) const;
     };
 
     AABB surrounding_box(const AABB &a, const AABB &b);
 
 
     /**
      * @class BVHNode
      * @brief  A node (internal or leaf) of the bounding-volume hierarchy.
      *
      * An internal node stores two children (`left`, `right`), while a leaf
      * stores a small array of primitive pointers.  
      * The **hit** method first tests the node box; on success it traverses the
      * children (or the primitives) and returns the closest intersection.
     */
     class BVHNode {
     public:
         AABB box;                                  ///< Bounding box of the node.
         std::unique_ptr<BVHNode> left;             ///< Left child (nullptr if leaf).
         std::unique_ptr<BVHNode> right;            ///< Right child.
         std::vector<const APrimitive*> objects;     ///< Primitives if this is a leaf.
 
         BVHNode(std::vector<const APrimitive*>& objs);
         bool hit(const Ray &ray, Float &t, HitRecord &rec) const;
     };
 
     std::unique_ptr<BVHNode> buildBVH(std::vector<const APrimitive*> objs);
 
}