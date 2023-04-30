/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** AmbiantLight
*/

#include "AmbiantLight.hpp"

/**
 * @brief Construct a new Ray Tracer:: Ambiant Light:: Ambiant Light object
*/
RayTracer::AmbiantLight::AmbiantLight()
{
    m_intensity = 0;
}

/**
 * @brief Construct a new Ray Tracer:: Ambiant Light:: Ambiant Light object
 * @param t_intensity Intensity of the light
*/
RayTracer::AmbiantLight::AmbiantLight(double t_intensity)
{
    m_intensity = t_intensity;
}

/**
 * @brief Get the Intensity of the light based on the surface normal where the ray hit
 * @param t_surfaceNormal Surface normal where the ray hit
 * @return double Intensity of the light
*/
double RayTracer::AmbiantLight::getIntensityAt(Math::Vector3D t_surfaceNormal)
{
    (void)t_surfaceNormal;
    return (m_intensity);
}

/**
 * @brief Set the Intensity object
 * @param t_intensity Intensity of the light
*/
void RayTracer::AmbiantLight::setIntensity(double t_intensity)
{
    m_intensity = t_intensity;
}
