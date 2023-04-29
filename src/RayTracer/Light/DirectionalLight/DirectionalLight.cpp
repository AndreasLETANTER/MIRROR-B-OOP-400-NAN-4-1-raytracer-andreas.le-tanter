/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"
#include <iostream>

RayTracer::DirectionalLight::DirectionalLight()
{
}

RayTracer::DirectionalLight::DirectionalLight(Math::Vector3D t_direction)
{
    m_direction = t_direction / t_direction.length();
}

RayTracer::DirectionalLight::~DirectionalLight()
{
}

double RayTracer::DirectionalLight::getIntensityAt(Math::Vector3D t_surfaceNormal)
{
    m_intensity = -m_direction.dot_product(t_surfaceNormal);
    return (m_intensity);
}

void RayTracer::DirectionalLight::setIntensity(double t_intensity)
{
    m_intensity = t_intensity;
}
