/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** AmbiantLight
*/

#pragma once
#include "../ILights.hpp"

namespace RayTracer
{
    class AmbiantLight : public RayTracer::ILights {
        public:
            AmbiantLight();
            AmbiantLight(double t_intensity);
            ~AmbiantLight();
            double getIntensityAt(Math::Point3D t_origin, Math::Vector3D t_distance) override;
            void setIntensity(double t_intensity) override;

        protected:
        private:
            double m_intensity;
    };
}
