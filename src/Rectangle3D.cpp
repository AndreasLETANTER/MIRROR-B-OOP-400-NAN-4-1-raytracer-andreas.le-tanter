/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"

Rectangle3D::Rectangle3D()
{
    m_origin = Math::Point3D();
    m_bottom_side = Math::Vector3D();
    m_left_side = Math::Vector3D();
}

Rectangle3D::Rectangle3D(Math::Point3D t_origin, Math::Vector3D t_bottom_side, Math::Vector3D t_left_side)
{
    m_origin = t_origin;
    m_bottom_side = t_bottom_side;
    m_left_side = t_left_side;
}

Rectangle3D::~Rectangle3D()
{
}

Math::Point3D Rectangle3D::pointAt(double u, double v)
{
    return (m_origin + (m_bottom_side * u) + (m_left_side * v));
}
