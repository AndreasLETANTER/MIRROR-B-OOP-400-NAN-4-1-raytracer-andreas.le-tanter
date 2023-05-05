/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** AmbiantLight
*/

#pragma once
#include "../ILights.hpp"
#include <memory>

/**
 * @brief Class for ambiant light
*/
namespace RayTracer
{
    class AmbiantLight : public RayTracer::ILights {
        public:
            AmbiantLight(void);
            AmbiantLight(double t_intensity);
            ~AmbiantLight(void) = default;
            double getIntensityAt(std::shared_ptr<RayTracer::IObjects> t_object) override;
            void setIntensity(double t_intensity) override;

        protected:
        private:
            double m_intensity;
    };
}
