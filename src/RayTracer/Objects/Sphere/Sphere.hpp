/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Sphere
*/

#pragma once
#include "../../../RayTracer/Ray/Ray.hpp"
#include "../../../Math/Vector3D/Vector3D.hpp"
#include "../../../Math/Point3D/Point3D.hpp"
#include "../IObjects.hpp"

/**
 * @brief Sphere class, used to create a sphere in 3D space
 * @details the sphere is defined by its center and its radius
*/
namespace RayTracer {
    class Sphere : public IObjects {
        public:
            Sphere();
            Sphere(Math::Point3D t_center, double t_radius, Math::Vector3D t_color);
            ~Sphere();
            Math::Vector3D getColor() override;
            Math::Point3D m_center;
            double m_radius;
            Math::Vector3D m_color;
            bool hits(Ray &t_ray) override;

        protected:
        private:
    };
}
