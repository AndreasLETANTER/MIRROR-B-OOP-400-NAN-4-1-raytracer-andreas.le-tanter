/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Cone
*/

#include "Cone.hpp"
#include <cmath>
#include <iostream>

/**
 * @brief Construct a new Ray Tracer:: Cone:: Cone object
 * @details set the color, the center, the height, the angle and the vector of the Cone to 0
*/
RayTracer::Cone::Cone(void)
{
    cosa = 0;
    c = Math::Vector3D(0, 0, 0);
    v = Math::Vector3D(0, 0, 0);
    m_color = Math::Vector3D(0, 0, 0);
    h = 0;
}

/**
 * @brief Construct a new Ray Tracer:: Cone:: Cone object
 * @details set the color, the center, the height, the angle and the vector of the Cone to the given parameters
 * @param t_cosa 
 * @param t_h 
 * @param t_c 
 * @param t_v 
 * @param t_color 
 */
RayTracer::Cone::Cone(double t_cosa, double t_h, Math::Vector3D t_c, Math::Vector3D t_v, Math::Vector3D t_color)
{
    cosa = t_cosa;
    h = t_h;
    c = t_c;
    v = t_v;
    m_color = t_color;
}

/**
 * @brief get the color of the Cone
 * @return Math::Vector3D 
*/
Math::Vector3D RayTracer::Cone::getColor(void)
{
    return (m_color);
}

/**
 * @brief check if the ray hits the Cone
 * @details check if the ray hits the Cone using a quadratic equation
 * @param t_ray 
 * @return true 
 * @return false 
*/
bool RayTracer::Cone::hits(RayTracer::Ray &t_ray)
{
    t_ray.m_direction = t_ray.m_direction / t_ray.m_direction.length();
    Math::Vector3D co = t_ray.m_origin - this->c;
    double a = this->v.dot_product(t_ray.m_direction) * this->v.dot_product(t_ray.m_direction) - this->cosa * this->cosa;
    double b = 2. * (this->v.dot_product(t_ray.m_direction) * this->v.dot_product(co) - co.dot_product(t_ray.m_direction) * this->cosa * this->cosa);
    double c1 = this->v.dot_product(co) * this->v.dot_product(co) - co.dot_product(co) * this->cosa * this->cosa;
    double det = b * b - 4. * a * c1;

    if (det < 0.) {
        return (false);
    }
    det = sqrt(det);
    double t1 = (-b - det) / (2. * a);
    double t2 = (-b + det) / (2. * a);
    double t = t1;
    if (t < 0. || (t2 > 0. && t2 < t))
        t = t2;
    if (t < 0.) {
        return (false);
    }
    Math::Vector3D cp = t_ray.m_origin + t_ray.m_direction * t - this->c;
    double h1 = this->v.dot_product(cp);
    if (h1 < 0. || h1 > this->h) {
        return (false);
    }
    Math::Vector3D n = cp * cp.dot_product(this->v) / cp.dot_product(cp) - this->v;
    n = n / n.length();
    m_n = n;
    m_hit_distance = t;
    m_hit_point = Math::Point3D(t_ray.m_origin + t_ray.m_direction * t);
    return (true);
}

/**
 * @brief get the surface normal of the Cone
 * @details get the surface normal of the Cone at the given point
 * @param t_point
 * @return Math::Vector3D 
*/
Math::Vector3D RayTracer::Cone::getSurfaceNormal(void)
{
    return (m_n);
}

/**
 * @brief get the distance between the ray origin and the hit point
 * @return double 
*/
double RayTracer::Cone::getHitDistance(void)
{
    return (m_hit_distance);
}

/**
 * @brief get the hit point
 * @return Math::Point3D 
*/
Math::Point3D RayTracer::Cone::getIntersectionPoint(void)
{
    return (m_hit_point);
}
