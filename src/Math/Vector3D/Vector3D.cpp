/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Vector3D
*/

#include "Vector3D.hpp"
#include <cmath>

/**
 * @brief Construct a new Vector 3D object
 * @details set the x, y and z component of the vector to 0
*/
Math::Vector3D::Vector3D()
{
    m_x_component = 0;
    m_y_component = 0;
    m_z_component = 0;
}

/**
 * @brief Construct a new Vector 3D object
 * @details set the x, y and z component of the vector to the given parameters
 * @param t_x 
 * @param t_y 
 * @param t_z 
*/
Math::Vector3D::Vector3D(double t_x, double t_y, double t_z)
{
    m_x_component = t_x;
    m_y_component = t_y;
    m_z_component = t_z;
}

/**
 * @brief Destroy the Vector 3D object
*/
Math::Vector3D::~Vector3D()
{
    m_z_component = 0;
    m_y_component = 0;
    m_x_component = 0;
}

/**
 * @brief return the len of the vector
 * @return double 
*/
double Math::Vector3D::length()
{
    return (sqrt(pow(m_x_component, 2) + pow(m_y_component, 2) + pow(m_z_component, 2)));
}

/**
 * @brief perform a sum between two vectors
 * @param t_other
 * @return Math::Vector3D 
*/
Math::Vector3D Math::Vector3D::operator+(const Math::Vector3D &t_other)
{
    return (Math::Vector3D(m_x_component + t_other.m_x_component, m_y_component + t_other.m_y_component, m_z_component + t_other.m_z_component));
}

/**
 * @brief perform a sum between two vectors and affect the result to the first vector
 * @param t_other 
 * @return Math::Vector3D 
*/
Math::Vector3D Math::Vector3D::operator+=(const Math::Vector3D &t_other)
{
    m_x_component += t_other.m_x_component;
    m_y_component += t_other.m_y_component;
    m_z_component += t_other.m_z_component;
    return (*this);
}

/**
 * @brief perform a substraction between two vectors
 * @param t_other 
 * @return Math::Vector3D 
*/
Math::Vector3D Math::Vector3D::operator-(const Math::Vector3D &t_other)
{
    return (Math::Vector3D(m_x_component - t_other.m_x_component, m_y_component - t_other.m_y_component, m_z_component - t_other.m_z_component));
}

/**
 * @brief perform a substraction between two vectors and affect the result to the first vector
 * @param t_other 
 * @return Math::Vector3D 
*/
Math::Vector3D Math::Vector3D::operator-=(const Math::Vector3D &t_other)
{
    m_x_component -= t_other.m_x_component;
    m_y_component -= t_other.m_y_component;
    m_z_component -= t_other.m_z_component;
    return (*this);
}

/**
 * @brief perform a multiplication between two vectors
 * @param t_other 
 * @return Math::Vector3D 
*/
Math::Vector3D Math::Vector3D::operator*(const Math::Vector3D &t_other)
{
    return (Math::Vector3D(m_x_component * t_other.m_x_component, m_y_component * t_other.m_y_component, m_z_component * t_other.m_z_component));
}

/**
 * @brief perform a multiplication between two vectors and affect the result to the first vector
 * @param t_other 
 * @return Math::Vector3D 
*/
Math::Vector3D Math::Vector3D::operator*=(const Math::Vector3D &t_other)
{
    m_x_component *= t_other.m_x_component;
    m_y_component *= t_other.m_y_component;
    m_z_component *= t_other.m_z_component;
    return (*this);
}

/**
 * @brief perform a division between two vectors
 * @param t_other 
 * @return Math::Vector3D 
*/
Math::Vector3D Math::Vector3D::operator/(const Math::Vector3D &t_other)
{
    return (Math::Vector3D(m_x_component / t_other.m_x_component, m_y_component / t_other.m_y_component, m_z_component / t_other.m_z_component));
}

/**
 * @brief perform a division between two vectors and affect the result to the first vector
 * @param t_other 
 * @return Math::Vector3D 
*/
Math::Vector3D Math::Vector3D::operator/=(const Math::Vector3D &t_other)
{
    m_x_component /= t_other.m_x_component;
    m_y_component /= t_other.m_y_component;
    m_z_component /= t_other.m_z_component;
    return (*this);
}

/**
 * @brief perform a multiplication between a vector and a double
 * @param t_other 
 * @return Math::Vector3D 
*/
Math::Vector3D Math::Vector3D::operator*(const double &t_other)
{
    return (Math::Vector3D(m_x_component * t_other, m_y_component * t_other, m_z_component * t_other));
}

/**
 * @brief perform a multiplication between a vector and a double and affect the result to the first vector
 * @param t_other 
 * @return Math::Vector3D 
*/
Math::Vector3D Math::Vector3D::operator*=(const double &t_other)
{
    m_x_component *= t_other;
    m_y_component *= t_other;
    m_z_component *= t_other;
    return (*this);
}

/**
 * @brief perform a division between a vector and a double
 * @param t_other 
 * @return Math::Vector3D 
*/
Math::Vector3D Math::Vector3D::operator/(const double &t_other)
{
    return (Math::Vector3D(m_x_component / t_other, m_y_component / t_other, m_z_component / t_other));
}

/**
 * @brief perform a division between a vector and a double and affect the result to the first vector
 * @param t_other 
 * @return Math::Vector3D 
*/
Math::Vector3D Math::Vector3D::operator/=(const double &t_other)
{
    m_x_component /= t_other;
    m_y_component /= t_other;
    m_z_component /= t_other;
    return (*this);
}

/**
 * @brief perform a dot product between two vectors
 * @param t_other 
 * @return double 
*/
double Math::Vector3D::dot_product(const Math::Vector3D &t_other)
{
    return (m_x_component * t_other.m_x_component + m_y_component * t_other.m_y_component + m_z_component * t_other.m_z_component);
}
