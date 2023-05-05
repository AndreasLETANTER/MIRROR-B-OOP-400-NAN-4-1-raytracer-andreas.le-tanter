/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** PointLight
*/

#include "PointLight.hpp"
#include <cmath>
#include <iostream>

/**
 * @brief Construct a new Point Light:: Point Light object
 * @details set the position and the intensity of the light to the given parameters
 * @param t_position 
 * @param t_intensity 
*/
RayTracer::PointLight::PointLight(Math::Point3D t_position, double t_intensity)
{
    m_position = t_position;
    m_intensity = t_intensity;
}

/**
 * @brief Get the Intensity of the light based on the surface normal where the ray hit
 * @param t_surfaceNormal Surface normal where the ray hit
 * @return double Intensity of the light
*/
double RayTracer::PointLight::getIntensityAt(std::shared_ptr<RayTracer::IObjects> t_object)
{
    Math::Vector3D lightDirection = m_position - t_object->getIntersectionPoint();
    lightDirection = lightDirection / lightDirection.length();
    double angle = acos(t_object->getSurfaceNormal().dot_product(lightDirection));
    double intensity = 0;

    if (angle > 2.35619) {
        return (intensity);
    } else {
        intensity = m_intensity * (1.0 - (angle / 2.35619));
        return (intensity);
    }
}

/**
 * @brief Set the Intensity of the light
 * @param t_intensity Intensity of the light
*/
void RayTracer::PointLight::setIntensity(double t_intensity)
{
    m_intensity = t_intensity;
}
