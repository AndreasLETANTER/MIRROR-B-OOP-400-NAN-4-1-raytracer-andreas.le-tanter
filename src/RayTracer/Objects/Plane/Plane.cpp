/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Plane
*/

#include "Plane.hpp"
#include <iostream>

/**
 * @brief Construct a new Plane object
 * @details set the position and the normal and the color to the given parameters
*/
RayTracer::Plane::Plane(Math::Point3D t_plane_position, Math::Vector3D t_plane_normal, Math::Vector3D t_color)
{
    m_plane_position = t_plane_position;
    m_plane_normal = t_plane_normal;
    m_color = t_color;
}

/**
 * @brief get the color of the plane
 * @return Math::Vector3D 
*/
Math::Vector3D RayTracer::Plane::getColor(void)
{
    return (m_color);
}

/**
    * @brief check if the ray hits the plane
    * @details the ray hits the plane if the ray is not parallel to the plane and if the ray is in front of the plane
    * @param t_ray 
    * @return true 
    * @return false 
*/
bool RayTracer::Plane::hits(RayTracer::Ray &t_ray)
{
    Math::Vector3D RayDirection = t_ray.m_direction / t_ray.m_direction.length();
    double t = 0;
    double denom = m_plane_normal.dot_product(RayDirection);

    if (std::abs(denom) < 1e-6) {
        return false;
    }
    Math::Vector3D p0l0 = m_plane_position - t_ray.m_origin;
    t = p0l0.dot_product(m_plane_normal) / denom;
    m_hit_point = t_ray.m_origin + RayDirection * t;
    return (t >= 0);
}

/**
 * @brief get the surface normal of the plane
 * @details the surface normal of the plane is the axis of the plane
 * @return Math::Vector3D 
*/
Math::Vector3D RayTracer::Plane::getSurfaceNormal(void)
{
    Math::Vector3D surface_normal = m_hit_point - Math::Point3D(0, 0, 0);

    surface_normal = surface_normal / surface_normal.length();
    return (surface_normal);
}
