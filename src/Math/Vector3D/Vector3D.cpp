/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Vector3D
*/

#include "Vector3D.hpp"
#include <cmath>

Math::Vector3D::Vector3D()
{
    m_x_component = 0;
    m_y_component = 0;
    m_z_component = 0;
}

Math::Vector3D::Vector3D(double t_x, double t_y, double t_z)
{
    m_x_component = t_x;
    m_y_component = t_y;
    m_z_component = t_z;
}

Math::Vector3D::~Vector3D()
{
    m_z_component = 0;
    m_y_component = 0;
    m_x_component = 0;
}

double Math::Vector3D::length()
{
    return (sqrt(pow(m_x_component, 2) + pow(m_y_component, 2) + pow(m_z_component, 2)));
}

Math::Vector3D Math::Vector3D::operator+(const Math::Vector3D &t_other)
{
    return (Math::Vector3D(m_x_component + t_other.m_x_component, m_y_component + t_other.m_y_component, m_z_component + t_other.m_z_component));
}

Math::Vector3D Math::Vector3D::operator+=(const Math::Vector3D &t_other)
{
    m_x_component += t_other.m_x_component;
    m_y_component += t_other.m_y_component;
    m_z_component += t_other.m_z_component;
    return (*this);
}

Math::Vector3D Math::Vector3D::operator-(const Math::Vector3D &t_other)
{
    return (Math::Vector3D(m_x_component - t_other.m_x_component, m_y_component - t_other.m_y_component, m_z_component - t_other.m_z_component));
}

Math::Vector3D Math::Vector3D::operator-=(const Math::Vector3D &t_other)
{
    m_x_component -= t_other.m_x_component;
    m_y_component -= t_other.m_y_component;
    m_z_component -= t_other.m_z_component;
    return (*this);
}

Math::Vector3D Math::Vector3D::operator*(const Math::Vector3D &t_other)
{
    return (Math::Vector3D(m_x_component * t_other.m_x_component, m_y_component * t_other.m_y_component, m_z_component * t_other.m_z_component));
}

Math::Vector3D Math::Vector3D::operator*=(const Math::Vector3D &t_other)
{
    m_x_component *= t_other.m_x_component;
    m_y_component *= t_other.m_y_component;
    m_z_component *= t_other.m_z_component;
    return (*this);
}

Math::Vector3D Math::Vector3D::operator/(const Math::Vector3D &t_other)
{
    return (Math::Vector3D(m_x_component / t_other.m_x_component, m_y_component / t_other.m_y_component, m_z_component / t_other.m_z_component));
}

Math::Vector3D Math::Vector3D::operator/=(const Math::Vector3D &t_other)
{
    m_x_component /= t_other.m_x_component;
    m_y_component /= t_other.m_y_component;
    m_z_component /= t_other.m_z_component;
    return (*this);
}

Math::Vector3D Math::Vector3D::operator*(const double &t_other)
{
    return (Math::Vector3D(m_x_component * t_other, m_y_component * t_other, m_z_component * t_other));
}

Math::Vector3D Math::Vector3D::operator*=(const double &t_other)
{
    m_x_component *= t_other;
    m_y_component *= t_other;
    m_z_component *= t_other;
    return (*this);
}

Math::Vector3D Math::Vector3D::operator/(const double &t_other)
{
    return (Math::Vector3D(m_x_component / t_other, m_y_component / t_other, m_z_component / t_other));
}

Math::Vector3D Math::Vector3D::operator/=(const double &t_other)
{
    m_x_component /= t_other;
    m_y_component /= t_other;
    m_z_component /= t_other;
    return (*this);
}

double Math::Vector3D::dot_product(const Math::Vector3D &t_other)
{
    return (m_x_component * t_other.m_x_component + m_y_component * t_other.m_y_component + m_z_component * t_other.m_z_component);
}
