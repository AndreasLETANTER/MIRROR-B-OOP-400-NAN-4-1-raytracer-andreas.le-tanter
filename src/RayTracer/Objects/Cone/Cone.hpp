/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Cone
*/

#pragma once
#include "../../../RayTracer/Ray/Ray.hpp"
#include "../../../Math/Vector3D/Vector3D.hpp"
#include "../../../Math/Point3D/Point3D.hpp"
#include "../IObjects.hpp"

/**
 * @brief Cone class, used to create a Cone in 3D space
 * @details the Cone is defined by its center and its radius
*/
namespace RayTracer {
    class Cone : public IObjects {
        public:
            Cone(void);
            Cone(Math::Point3D t_center, double t_radius, Math::Vector3D t_color);
            ~Cone(void) = default;
            Math::Vector3D getColor(void) override;
            Math::Point3D m_center;
            double m_radius;
            Math::Vector3D m_color;
            bool hits(Ray &t_ray) override;
            Math::Vector3D getSurfaceNormal(void) override;
            double getHitDistance(void) override;
            Math::Point3D getIntersectionPoint(void) override;
            double m_hit_distance;

        protected:
            Math::Point3D m_hit_point;
        private:
    };
}