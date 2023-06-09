/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** DirectionalLight
*/

#pragma once
#include "../ILights.hpp"

/**
 * @brief Class for directional light
 * @details This class is used to create a directional light for the scene
 */
namespace RayTracer
{
    class DirectionalLight : public RayTracer::ILights {
        public:
            DirectionalLight(void) = default;
            DirectionalLight(Math::Vector3D t_direction);
            ~DirectionalLight(void) = default;
            double getIntensityAt(std::shared_ptr<RayTracer::IObjects> t_object) override;
            void setIntensity(double t_intensity) override;

        protected:
        private:
            double m_intensity;
            Math::Vector3D m_direction;
    };
}
