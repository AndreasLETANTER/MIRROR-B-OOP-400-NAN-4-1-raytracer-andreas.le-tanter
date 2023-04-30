/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Ray
*/

#include "Ray.hpp"

/**
 * @brief Construct a new Ray:: Ray object
 * @details set the origin and the direction of the ray to 0
*/
RayTracer::Ray::Ray()
{
    m_origin = Math::Point3D(0, 0, 0);
    m_direction = Math::Vector3D(0, 0, 0);
}

/**
 * @brief Construct a Ray object
 * @details set the origin and the direction of the ray to the given parameters
 * @param t_origin 
 * @param t_direction 
*/
RayTracer::Ray::Ray(Math::Point3D t_origin, Math::Vector3D t_direction)
{
    m_origin = t_origin;
    m_direction = t_direction;
}
