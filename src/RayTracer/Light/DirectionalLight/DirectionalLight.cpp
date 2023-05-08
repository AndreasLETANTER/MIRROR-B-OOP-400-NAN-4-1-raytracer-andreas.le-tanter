/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"
#include <iostream>

/**
 * @brief Construct a new Ray Tracer:: Directional Light:: Directional Light object
 * @details set the direction of the light to the given parameter and normalize it
 * @param t_direction
*/
RayTracer::DirectionalLight::DirectionalLight(Math::Vector3D t_direction)
{
    m_direction = t_direction / t_direction.length();
}

/**
 * @brief Get the Intensity of the light based on the surface normal where the ray hit
 * @param t_surfaceNormal Surface normal where the ray hit
 * @return double Intensity of the light
*/
double RayTracer::DirectionalLight::getIntensityAt(std::shared_ptr<RayTracer::IObjects> t_object)
{
    m_intensity = -m_direction.dot_product(t_object->getSurfaceNormal());
    return (m_intensity);
}

/**
 * @brief Set the Intensity of the light
 * @param t_intensity Intensity of the light
*/
void RayTracer::DirectionalLight::setIntensity(double t_intensity)
{
    m_intensity = t_intensity;
}
