/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Cylinder
*/

#pragma once
#include "../../../RayTracer/Ray/Ray.hpp"
#include "../../../Math/Vector3D/Vector3D.hpp"
#include "../../../Math/Point3D/Point3D.hpp"
#include "../AObjects.hpp"
#include <cmath>
#include <algorithm>

/**
 * @brief Cylinder class, used to create a cylinder in 3D space
 * @details the cylinder is defined by its center, its height and its radius
*/
namespace RayTracer {
    class Cylinder : public AObjects {
        public:
            Cylinder();
            Cylinder(Math::Point3D t_center, std::pair<double, bool> t_radius
            , double t_height, Math::Vector3D t_color);
            ~Cylinder();
            Math::Vector3D getColor(void);
            Math::Vector3D getSurfaceNormal(void);
            bool hits(Ray &t_ray);
            double getHitDistance(void);
            Math::Point3D getIntersectionPoint(void);
        public:
            Math::Point3D m_center;
            Math::Vector3D m_axis;
            Math::Vector3D m_color;
            Math::Point3D m_hit_point;
            Math::Vector3D m_surface_normal;
            double m_hit_distance;
            double m_radius;
            double m_height;
            bool m_is_point_light;
    };
}
