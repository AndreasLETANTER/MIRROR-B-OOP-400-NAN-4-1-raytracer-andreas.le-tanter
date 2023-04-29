/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** IObjects
*/

#pragma once
#include "../Ray/Ray.hpp"

/**
 * @brief IObjects class, used to create an interface for all objects 
*/
namespace RayTracer
{
    class IObjects {
        public:
            virtual ~IObjects() = default;
            virtual bool hits(Ray &t_ray) = 0;
            virtual Math::Vector3D getSurfaceNormal() = 0;
            virtual Math::Vector3D getColor() = 0;
        protected:
        private:
    };
} // namespace RayTracer
