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

/**
 * @brief Cylindre class, used to create a cylindre in 3D space
 * @details the cylindre is defined by its center, its height and its radius
*/
namespace RayTracer {
    class Cylinder : public IObjects {
        public:
            Cylinder();
            Cylinder(Math::Point3D c_center, double c_radius, double c_height);
            ~Cylinder();
            Math::Point3D c_center;
            double c_radius;
            double c_height;
            bool hits(Ray &t_ray) override;
        protected:
        private:
    };
}
