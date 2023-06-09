/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Ray
*/

#pragma once
#include "../../Math/Point3D/Point3D.hpp"
#include "../../Math/Vector3D/Vector3D.hpp"

/**
 * @brief Ray class, used to create a ray in 3D space
 * @details the ray is defined by its origin and its direction
*/
namespace RayTracer
{
    class Ray {
        public:
            Ray(void); 
            Ray(Math::Point3D t_origin, Math::Vector3D t_direction);
            Ray(const Ray &t_other) = default;
            Ray &operator=(const Ray &t_other) = default;
            Ray(Ray &&t_other) = default;
            Ray &operator=(Ray &&t_other) = default;
            ~Ray(void) = default;
            Math::Point3D m_origin;
            Math::Vector3D m_direction;

        protected:
        private:
    };
}
