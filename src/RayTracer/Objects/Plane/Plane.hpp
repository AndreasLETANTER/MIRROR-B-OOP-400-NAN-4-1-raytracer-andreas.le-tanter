/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Plane
*/

#pragma once
#include "../IObjects.hpp"

namespace RayTracer
{
    class Plane : public IObjects {
        public:
            Plane(void) = default;
            Plane(Math::Point3D t_plane_position, Math::Vector3D t_plane_normal, Math::Vector3D t_color);
            ~Plane(void) = default;
            Math::Vector3D getColor(void) override;
            bool hits(Ray &t_ray) override;
            Math::Vector3D getSurfaceNormal(void) override;
            Math::Vector3D m_color;
            Math::Point3D m_plane_position;
            Math::Vector3D m_plane_normal;
            Math::Point3D m_hit_point;

        protected:
        private:
    };
}
