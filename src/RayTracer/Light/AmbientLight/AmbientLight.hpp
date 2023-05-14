/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** AmbientLight
*/

#pragma once
#include "../ILights.hpp"
#include <memory>

/**
 * @brief Class for ambient light
*/
namespace RayTracer
{
    class AmbientLight : public RayTracer::ILights {
        public:
            AmbientLight(void);
            AmbientLight(double t_intensity);
            ~AmbientLight(void) = default;
            double getIntensityAt(std::shared_ptr<RayTracer::IObjects> t_object) override;
            void setIntensity(double t_intensity) override;

        protected:
        private:
            double m_intensity;
    };
}
