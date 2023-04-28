/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** AmbiantLight
*/

#include "AmbiantLight.hpp"

RayTracer::AmbiantLight::AmbiantLight()
{
    m_intensity = 0;
}

RayTracer::AmbiantLight::AmbiantLight(double t_intensity)
{
    m_intensity = t_intensity;
}

RayTracer::AmbiantLight::~AmbiantLight()
{
}

double RayTracer::AmbiantLight::getIntensityAt(Math::Point3D t_origin, Math::Vector3D t_direction)
{
    (void)t_origin;
    (void)t_direction;
    return (m_intensity);
}

void RayTracer::AmbiantLight::setIntensity(double t_intensity)
{
    m_intensity = t_intensity;
}
