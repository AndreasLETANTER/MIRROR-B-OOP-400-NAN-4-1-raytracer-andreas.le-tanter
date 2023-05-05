/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Cylindre
*/

#include "Cylinder.hpp"

/**
 * @brief Construct a new Cylinder object
 * @details set the center, height and the radius of the cylinder to 0
*/
RayTracer::Cylinder::Cylinder()
{
    c_center = Math::Point3D(0, 0, 0);
    c_radius = 0;
    c_height = 0;
}

/**
 * @brief Construct a new Cylinder object
 * @details set the center, the radius and the height of the cylinder to the given parameters
 * @param c_center
 * @param c_radius
 * @param c_height
 */
RayTracer::Cylinder::Cylinder(Math::Point3D center, double radius
, double height)
{
    c_center = center;
    c_radius = radius;
    c_height = height;
}

/**
 * @brief Destroy the Cylinder object
*/
RayTracer::Cylinder::~Cylinder()
{
}

/**
 * @brief check if the ray hits the cylinder
 * @details check if the ray hits the cylinder using a quadratic equation
 * @param t_ray
 * @return true
 * @return false
*/
bool RayTracer::Cylinder::hits(Ray& t_ray)
{
    Math::Vector3D OC = c_center - t_ray.m_origin;
    float a = t_ray.m_direction.dot_product(t_ray.m_direction) - pow(t_ray.m_direction.m_z_component, 2);
    float b = 2 * (OC.dot_product(t_ray.m_direction) - OC.m_z_component * t_ray.m_direction.m_z_component);
    float c = OC.dot_product(OC) - OC.m_z_component * OC.m_z_component - pow(c_radius, 2);
    float discriminant = pow(b, 2) - 4 * a * c;
    return (discriminant > 0);
}
