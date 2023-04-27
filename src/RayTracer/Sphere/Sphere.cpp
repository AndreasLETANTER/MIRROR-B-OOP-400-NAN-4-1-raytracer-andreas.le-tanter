/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Sphere
*/

#include "Sphere.hpp"

RayTracer::Sphere::Sphere()
{
    m_center = Math::Point3D(0, 0, 0);
    m_radius = 0;
}

RayTracer::Sphere::Sphere(Math::Point3D t_center, double t_radius)
{
    m_center = t_center;
    m_radius = t_radius;
}

RayTracer::Sphere::~Sphere()
{
}

bool RayTracer::Sphere::hits(RayTracer::Ray &t_ray)
{
    Math::Vector3D oc = t_ray.m_origin - m_center;
    double a = t_ray.m_direction.dot_product(t_ray.m_direction);
    double b = 2.0 * oc.dot_product(t_ray.m_direction);
    double c = oc.dot_product(oc) - m_radius * m_radius;
    double discriminant = b * b - 4 * a * c;

    return (discriminant > 0);
}
