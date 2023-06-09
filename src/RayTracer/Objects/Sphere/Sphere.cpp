/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include <cmath>
#include <iostream>

/**
 * @brief Construct a new Sphere object
 * @details set the center and the radius of the sphere to 0
*/
RayTracer::Sphere::Sphere(void)
{
    m_position = Math::Point3D(0, 0, 0);
    m_radius = 0;
}

/**
 * @brief Construct a new Sphere object
 * @details set the center and the radius of the sphere to the given parameters
 * @param t_center 
 * @param t_radius 
 */
RayTracer::Sphere::Sphere(Math::Point3D t_center, double t_radius, Math::Vector3D t_color)
{
    m_position = t_center;
    m_radius = t_radius;
    m_color = t_color;
}

/**
 * @brief get the color of the sphere
 * @return Math::Vector3D 
*/
Math::Vector3D RayTracer::Sphere::getColor(void)
{
    return (m_color);
}

/**
 * @brief check if the ray hits the sphere
 * @details check if the ray hits the sphere using a quadratic equation
 * @param t_ray 
 * @return true 
 * @return false 
*/
bool RayTracer::Sphere::hits(RayTracer::Ray &t_ray)
{
    Math::Vector3D oc = t_ray.m_origin - m_position;
    double a = t_ray.m_direction.dot_product(t_ray.m_direction);
    double b = 2.0 * oc.dot_product(t_ray.m_direction);
    double c = oc.dot_product(oc) - m_radius * m_radius;
    double discriminant = b * b - 4 * a * c;
    double t = (-b - sqrt(discriminant)) / (2.0 * a);

    if (discriminant < 0)
        return (false);
    m_hit_point = t_ray.m_origin + t_ray.m_direction * t;
    m_hit_distance = t;
    return (true);
}

/**
 * @brief get the surface normal of the sphere
 * @details get the surface normal of the sphere at the given point
 * @param t_point
 * @return Math::Vector3D 
*/
Math::Vector3D RayTracer::Sphere::getSurfaceNormal(void)
{
    Math::Vector3D surface_normal = m_hit_point - m_position;

    surface_normal = surface_normal / surface_normal.length();
    return (surface_normal);
}

/**
 * @brief get the distance between the ray origin and the hit point
 * @return double 
*/
double RayTracer::Sphere::getHitDistance(void)
{
    return (m_hit_distance);
}

/**
 * @brief get the hit point
 * @return Math::Point3D 
*/
Math::Point3D RayTracer::Sphere::getIntersectionPoint(void)
{
    return (m_hit_point);
}
