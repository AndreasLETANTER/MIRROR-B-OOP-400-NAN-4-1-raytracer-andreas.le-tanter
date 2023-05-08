/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Cylindre
*/

#pragma once
#include "../../../RayTracer/Ray/Ray.hpp"
#include "../../../Math/Vector3D/Vector3D.hpp"
#include "../../../Math/Point3D/Point3D.hpp"
#include "../IObjects.hpp"
#include <cmath>
#include <algorithm>

/**
 * @brief Cylindre class, used to create a cylindre in 3D space
 * @details the cylindre is defined by its center, its height and its radius
*/
namespace RayTracer {
    class LCylinder : public IObjects {
        public:
            LCylinder();
            LCylinder(Math::Point3D center, double radius, double height
            , Math::Vector3D color);
            ~LCylinder();
            Math::Vector3D getColor(void) override;
            Math::Vector3D getSurfaceNormal(void) override;
            bool hits(Ray &t_ray) override;
            double getHitDistance(void) override;
            Math::Point3D getIntersectionPoint(void) override;
        public:
            Math::Point3D c_center;
            Math::Vector3D c_axis;
            Math::Vector3D m_color;
            Math::Point3D m_hit_point;
            double m_hit_distance;
            double c_radius;
            double c_height;
    };
    class Cylinder : public IObjects {
        public:
            Cylinder();
            Cylinder(Math::Point3D center, double radius, double height
            , Math::Vector3D color);
            ~Cylinder();
            Math::Vector3D getColor(void) override;
            Math::Vector3D getSurfaceNormal(void) override;
            bool hits(Ray &t_ray) override;
            double getHitDistance(void) override;
            Math::Point3D getIntersectionPoint(void) override;
        public:
            Math::Point3D c_center;
            Math::Vector3D c_axis;
            Math::Vector3D m_color;
            Math::Point3D m_hit_point;
            double m_hit_distance;
            double c_radius;
            double c_height;
    };
}