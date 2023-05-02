/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Plane
*/

#include "Plane.hpp"
#include <iostream>

/**
 * @brief Plane constructor
 * @details the plane is defined by its axis, its position and its color
 * @param t_axis 
 * @param t_position 
 * @param t_color 
*/
RayTracer::Plane::Plane(PlaneAxis t_axis, double t_position, Math::Vector3D t_color)
{
    m_axis = t_axis;
    m_position = t_position;
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
    Math::Vector3D PlaneNormal = Math::Vector3D(-1., 0., 0.);
    Math::Vector3D RayDirection = t_ray.m_direction / t_ray.m_direction.length();
    Math::Point3D PlanePosition = Math::Point3D(0.3, 0., 0.);
    double hitDistance = 0;
    double denom = PlaneNormal.dot_product(RayDirection);

    if (std::abs(denom) < 1e-6) {
        return false;
    }
    Math::Vector3D p0l0 = PlanePosition - t_ray.m_origin;
    hitDistance = p0l0.dot_product(PlaneNormal) / denom;
    if (hitDistance < 0) {
        return false;
    }
    m_hit_point = t_ray.m_origin + (RayDirection * hitDistance);
    return (hitDistance >= 0);
}

/**
 * @brief get the surface normal of the plane
 * @details the surface normal of the plane is the axis of the plane
 * @return Math::Vector3D 
*/
Math::Vector3D RayTracer::Plane::getSurfaceNormal(void)
{
    Math::Vector3D surface_normal = m_hit_point - Math::Point3D(-1., 0., 0.);

    surface_normal = surface_normal / surface_normal.length();
    return (surface_normal);
}
