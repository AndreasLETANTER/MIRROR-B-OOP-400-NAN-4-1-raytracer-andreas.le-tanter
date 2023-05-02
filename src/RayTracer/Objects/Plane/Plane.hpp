/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Plane
*/

#pragma once
#include "../IObjects.hpp"

enum PlaneAxis {
    X,
    Y,
    Z
};

namespace RayTracer
{
    class Plane : public IObjects {
        public:
            Plane(void) = default;
            Plane(PlaneAxis t_axis, double t_position, Math::Vector3D t_color);
            ~Plane(void) = default;
            Math::Vector3D getColor(void) override;
            bool hits(Ray &t_ray) override;
            Math::Vector3D getSurfaceNormal(void) override;
            Math::Vector3D m_color;
            PlaneAxis m_axis;
            double m_position;
            Math::Point3D m_hit_point;

        protected:
        private:
    };
}
