/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** ILight
*/

#pragma once
#include "../../Math/Point3D/Point3D.hpp"
#include "../../Math/Rectangle3D/Rectangle3D.hpp"

/**
 * @brief Interface for lights
 * @details Interface for lights to be used in the raytracer project
 * it contains a method to get the intensity at a given point and a method to set the intensity
 */
namespace RayTracer
{
    class ILights {
        public:
            virtual ~ILights(void) = default;
            virtual double getIntensityAt(Math::Vector3D t_surfaceNormal) = 0;
            virtual void setIntensity(double t_intensity) = 0;

        protected:
        private:
    };
}
