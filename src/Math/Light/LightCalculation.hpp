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

/**
 * @brief Class for light calculation
*/
namespace Math
{
    class LightCalculation {
        public:
            LightCalculation(void) = default;
            ~LightCalculation(void) = default;
            Math::Vector3D calculateLightEffect(Math::Vector3D t_base_color, std::vector<std::shared_ptr<RayTracer::ILights>> t_lights, std::shared_ptr<RayTracer::IObjects> t_object);

        protected:
        private:
            std::vector<RayTracer::ILights> m_lights;
    };
} // namespace Math
