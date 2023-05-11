/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

/**
 * @brief Construct a new Cylinder object
 * @details set the center, height and the radius of the cylinder to 0
*/
RayTracer::Cylinder::Cylinder()
{
    m_center = Math::Point3D(0, 0, 0);
    m_radius = 0;
    m_height = 0;
}

/**
 * @brief Construct a new Cylinder object
 * @details set the center, the radius and the height of the cylinder to the given parameters
 * @param t_center
 * @param t_radius
 * @param t_height
 * @param t_color
 */
RayTracer::Cylinder::Cylinder(Math::Point3D t_center, double t_radius
, double t_height, Math::Vector3D t_color)
{
    m_center = t_center;
    m_radius = t_radius;
    m_height = t_height;
    m_color = t_color;
}

/**
 * @brief Destroy the Cylinder object
*/
RayTracer::Cylinder::~Cylinder()
{
}

/**
 * @brief check if the ray hits the cylinder
 * @details check if the ray hits the cylinder using a quadratic equation and
 * @details calcul the normal surface of the cylinder to have the right hit points
 * @param t_ray
 * @return true
 * @return false
*/
bool RayTracer::Cylinder::hits(Ray& t_ray)
{
    Math::Vector3D OC = t_ray.m_origin - m_center;
    double a = pow(t_ray.m_direction.m_x_component, 2) + pow(t_ray.m_direction.m_z_component, 2);
    double b = 2 * (t_ray.m_direction.m_x_component * OC.m_x_component + t_ray.m_direction.m_z_component * OC.m_z_component);
    double c = pow(OC.m_x_component, 2) + pow(OC.m_z_component, 2) - pow(m_radius, 2);
    double discriminant = pow(b, 2) - 4 * a * c;
    if (discriminant <= 0) {
        return false;
    }
    double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    double t;
    if (t1 > 0) {
        t = t1;
    } else {
        return false;
    }
    m_hit_point = t_ray.m_origin + t_ray.m_direction * t;
    Math::Vector3D hitPointOnCylinder;
    hitPointOnCylinder.m_x_component = m_center.m_x_component + 0;
    hitPointOnCylinder.m_y_component = m_center.m_y_component +  m_hit_point.m_y_component;
    hitPointOnCylinder.m_z_component = m_center.m_z_component + 0;
    Math::Vector3D surfaceNormal;
    surfaceNormal.m_x_component = m_hit_point.m_x_component - hitPointOnCylinder.m_x_component;
    surfaceNormal.m_y_component = m_hit_point.m_y_component - hitPointOnCylinder.m_y_component;
    surfaceNormal.m_z_component = m_hit_point.m_z_component - hitPointOnCylinder.m_z_component;
    surfaceNormal.normalize();
    m_surface_normal = surfaceNormal;
    m_hit_point.m_x_component = m_surface_normal.m_x_component;
    m_hit_point.m_y_component = m_surface_normal.m_y_component;
    m_hit_point.m_z_component = m_surface_normal.m_z_component;
    return true;
}

/**
 * @brief get the surface normal of the cylinder
 * @details get the surface normal of the cylinder at the given point
 * @param t_point
 * @return Math::Vector3D
*/
Math::Vector3D RayTracer::Cylinder::getSurfaceNormal(void)
{
    Math::Vector3D surface_normal = m_hit_point - m_center;

    surface_normal = surface_normal / surface_normal.length();
    return (surface_normal);
}

/**
 * @brief get the color of the cylinder
 * @return Math::Vector3D
*/
Math::Vector3D RayTracer::Cylinder::getColor(void)
{
    return (m_color);
}

/**
 * @brief get the distance between the ray origin and the hit point
 * @return double
*/
double RayTracer::Cylinder::getHitDistance(void)
{
    return (m_hit_distance);
}

/**
 * @brief get the hit point
 * @return Math::Point3D
*/
Math::Point3D RayTracer::Cylinder::getIntersectionPoint(void)
{
    return (m_hit_point);
}