/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Light
*/

#pragma once
#include "../../RayTracer/Light/ILights.hpp"
#include <vector>
#include <memory>

namespace Math
{
    class LightCalculation {
        public:
            LightCalculation();
            ~LightCalculation();
            Math::Vector3D calculateLightEffect(Math::Vector3D t_base_color, std::vector<std::shared_ptr<RayTracer::ILights>> t_lights, Math::Vector3D t_surfaceNormal);

        protected:
        private:
            std::vector<RayTracer::ILights> m_lights;
    };
} // namespace Math
