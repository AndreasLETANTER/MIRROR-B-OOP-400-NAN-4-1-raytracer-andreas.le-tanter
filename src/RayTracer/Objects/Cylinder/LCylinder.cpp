/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Limited Cylinder
*/

#include "LCylinder.hpp"

/**
 * @brief Construct a new Cylinder object
 * @details set the center, height and the radius of the cylinder to 0
*/
RayTracer::LCylinder::LCylinder()
{
    m_center = Math::Point3D(0, 0, 0);
    m_radius = 0;
    m_height = 0;
}

/**
 * @brief Construct a new Cylinder object
 * @details set the center, the radius and the height of the cylinder to the given parameters
 * @param m_center
 * @param m_radius
 * @param m_height
 */
RayTracer::LCylinder::LCylinder(Math::Point3D t_center, std::pair<double, bool> t_radius
, double t_height, Math::Vector3D t_color)
{
    m_center = t_center;
    m_radius = t_radius.first;
    m_is_point_light = t_radius.second;
    m_height = t_height;
    m_color = t_color;
}

/**
 * @brief Destroy the Cylinder object
*/
RayTracer::LCylinder::~LCylinder()
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
bool RayTracer::LCylinder::hits(Ray& t_ray)
{
    Math::Vector3D OC = t_ray.m_origin - (m_center + Math::Vector3D(0, m_height / 2, 0));
    double a = pow(t_ray.m_direction.m_x_component, 2) + pow(t_ray.m_direction.m_z_component, 2);
    double b = 2 * (t_ray.m_direction.m_x_component * OC.m_x_component + t_ray.m_direction.m_z_component * OC.m_z_component);
    double c = pow(OC.m_x_component, 2) + pow(OC.m_z_component, 2) - pow(m_radius, 2);
    double discriminant = pow(b, 2) - 4 * a * c;
    if (discriminant <= 0) {
        return false;
    }
    double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
    double t;
    if (t1 > 0) {
        t = t1;
    } else if (t2 > 0) {
        t = t2;
    } else {
        return false;
    }
    Math::Vector3D hit_point;
    hit_point.m_x_component  = t_ray.m_origin.m_x_component + t_ray.m_direction.m_x_component * t;
    hit_point.m_y_component  = t_ray.m_origin.m_y_component + t_ray.m_direction.m_y_component * t;
    hit_point.m_z_component  = t_ray.m_origin.m_z_component + t_ray.m_direction.m_z_component * t;
    Math::Vector3D cylinderCenter(m_center.m_x_component, m_center.m_y_component, m_center.m_z_component);
    Math::Vector3D relativeHitPoint = hit_point - cylinderCenter;
    double hitY = relativeHitPoint.m_y_component;
    if (hitY < -m_height / 2 || hitY > m_height / 2) {
        return false;
    }
    double distanceSquaredBottom = pow(relativeHitPoint.m_x_component, 2) + pow(relativeHitPoint.m_z_component, 2);
    if (hitY < -m_height / 2 && distanceSquaredBottom > pow(m_radius, 2)) {
        return false;
    }
    double distanceSquaredTop = pow(relativeHitPoint.m_x_component, 2) + pow(relativeHitPoint.m_z_component, 2);
    if (hitY > m_height / 2 && distanceSquaredTop > pow(m_radius, 2)) {
        return false;
    }
    m_hit_point.m_x_component = hit_point.m_x_component;
    if (m_is_point_light ==  true) {
        m_hit_point.m_y_component = hit_point.m_y_component * 3.14 * pow(m_radius, 2) * relativeHitPoint.m_y_component;
    } else {
        m_hit_point.m_y_component = hit_point.m_y_component;
    }
    m_hit_point.m_z_component = hit_point.m_z_component;
    Math::Vector3D hitToLight = m_hit_point - t_ray.m_origin;
    m_hit_distance = hitToLight.length();
    return true;
}


/**
 * @brief get the surface normal of the cylinder
 * @details get the surface normal of the cylinder at the given point
 * @param t_point
 * @return Math::Vector3D
*/
Math::Vector3D RayTracer::LCylinder::getSurfaceNormal(void)
{
    Math::Vector3D surface_normal = m_hit_point - m_center;

    surface_normal = surface_normal / surface_normal.length();
    return (surface_normal);
}

/**
 * @brief get the color of the cylinder
 * @return Math::Vector3D
*/
Math::Vector3D RayTracer::LCylinder::getColor(void)
{
    return (m_color);
}

/**
 * @brief get the distance between the ray origin and the hit point
 * @return double
*/
double RayTracer::LCylinder::getHitDistance(void)
{
    return (m_hit_distance);
}

/**
 * @brief get the hit point
 * @return Math::Point3D
*/
Math::Point3D RayTracer::LCylinder::getIntersectionPoint(void)
{
    return (m_hit_point);
}
