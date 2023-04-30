/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"

/**
 * @brief Construct a new Rectangle3D object
 * @details set the origin, the bottom side and the left side of the rectangle to 0
*/
Rectangle3D::Rectangle3D(void)
{
    m_origin = Math::Point3D();
    m_bottom_side = Math::Vector3D();
    m_left_side = Math::Vector3D();
}

/**
 * @brief Construct a new Rectangle3D object
 * @details set the origin, the bottom side and the left side of the rectangle to the given parameters
 * @param t_origin 
 * @param t_bottom_side 
 * @param t_left_side 
*/
Rectangle3D::Rectangle3D(Math::Point3D t_origin, Math::Vector3D t_bottom_side, Math::Vector3D t_left_side)
{
    m_origin = t_origin;
    m_bottom_side = t_bottom_side;
    m_left_side = t_left_side;
}

/**
 * @brief return the point at the given u and v coordinates
 * @param u 
 * @param v 
 * @return Math::Point3D 
 */
Math::Point3D Rectangle3D::pointAt(double u, double v)
{
    return (m_origin + (m_bottom_side * u) + (m_left_side * v));
}
