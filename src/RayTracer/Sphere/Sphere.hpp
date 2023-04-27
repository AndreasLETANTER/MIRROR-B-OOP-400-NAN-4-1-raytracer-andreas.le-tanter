/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Sphere
*/

#pragma once
#include "../../RayTracer/Ray/Ray.hpp"
#include "../../Math/Vector3D/Vector3D.hpp"
#include "../../Math/Point3D/Point3D.hpp"

namespace RayTracer {
    class Sphere {
        public:
            Sphere();
            Sphere(Math::Point3D t_center, double t_radius);
            ~Sphere();
            Math::Point3D m_center;
            double m_radius;
            bool hits(Ray &t_ray);

        protected:
        private:
    };
}
