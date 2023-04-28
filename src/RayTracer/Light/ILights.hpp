/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** ILight
*/

#pragma once
#include "../../Math/Point3D/Point3D.hpp"
#include "../../Math/Rectangle3D/Rectangle3D.hpp"

namespace RayTracer
{
    class ILights {
        public:
            virtual ~ILights() = default;
            virtual double getIntensityAt(Math::Point3D t_origin, Math::Vector3D t_direction) = 0;
            virtual void setIntensity(double t_intensity) = 0;

        protected:
        private:
    };
}
