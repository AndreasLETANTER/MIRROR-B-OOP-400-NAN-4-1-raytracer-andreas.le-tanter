/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** DirectionalLight
*/

#pragma once
#include "../ILights.hpp"

namespace RayTracer
{
    class DirectionalLight : public RayTracer::ILights {
        public:
            DirectionalLight();
            DirectionalLight(Math::Vector3D t_direction);
            ~DirectionalLight();
            double getIntensityAt(Math::Vector3D t_surfaceNormal) override;
            void setIntensity(double t_intensity) override;

        protected:
        private:
            double m_intensity;
            Math::Vector3D m_direction;
    };
}
