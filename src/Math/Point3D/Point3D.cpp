/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Point3D
*/

#include "Point3D.hpp"

/**
 * @brief Construct a new Point3D:: Point3D object
 * @details set the x, y and z coordinates to 0
*/
Math::Point3D::Point3D(void)
{
    m_x_component = 0;
    m_y_component = 0;
    m_z_component = 0;
}

/**
 * @brief Construct a new Point3D:: Point3D object
 * @details set the x, y and z coordinates to the given parameters
 * @param t_x 
 * @param t_y 
 * @param t_z 
*/
Math::Point3D::Point3D(double t_x, double t_y, double t_z)
{
    m_x_component = t_x;
    m_y_component = t_y;
    m_z_component = t_z;
}

/**
 * @brief perform a sum between a point and a vector
 * @param t_other
 * @return Math::Point3D
*/
Math::Point3D Math::Point3D::operator+(const Math::Vector3D &t_other)
{
    return (Math::Point3D(m_x_component + t_other.m_x_component, m_y_component + t_other.m_y_component, m_z_component + t_other.m_z_component));
}

/**
 * @brief perform a sum between a point and a vector and store the result in the point
 * @param t_other
 * @return Math::Point3D
*/
Math::Point3D Math::Point3D::operator+=(const Math::Vector3D &t_other)
{
    m_x_component += t_other.m_x_component;
    m_y_component += t_other.m_y_component;
    m_z_component += t_other.m_z_component;
    return (*this);
}

/**
 * @brief perform a substraction between two points
 * @param t_other
 * @return Math::Vector3D
*/
Math::Vector3D Math::Point3D::operator-(const Math::Point3D &t_other)
{
    return (Math::Vector3D(m_x_component - t_other.m_x_component, m_y_component - t_other.m_y_component, m_z_component - t_other.m_z_component));
}

/**
 * @brief perform a substraction between a point and a vector and store the result in the vector
 * @param t_other
 * @return Math::Point3D
*/
Math::Vector3D Math::Point3D::operator-=(const Math::Point3D &t_other)
{
    m_x_component -= t_other.m_x_component;
    m_y_component -= t_other.m_y_component;
    m_z_component -= t_other.m_z_component;
    return (Math::Vector3D(m_x_component, m_y_component, m_z_component));
}

/**
 * @brief perform a multiplication between a point and a vector and store the result in the vector
 * @param t_other
 * @return Math::Vector3D
*/
Math::Vector3D Math::Point3D::operator*(const Math::Vector3D &t_other)
{
    return (Math::Vector3D(m_x_component * t_other.m_x_component, m_y_component * t_other.m_y_component, m_z_component * t_other.m_z_component));
}

/**
 * @brief perform a multiplication between a point and a vector and store the result in the vector
 * @param t_other
 * @return Math::Vector3D
*/
Math::Vector3D Math::Point3D::operator*=(const Math::Vector3D &t_other)
{
    m_x_component *= t_other.m_x_component;
    m_y_component *= t_other.m_y_component;
    m_z_component *= t_other.m_z_component;
    return (Math::Vector3D(m_x_component, m_y_component, m_z_component));
}