/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Rectangle3D
*/

#pragma once
#include "../Point3D/Point3D.hpp"
#include "../Vector3D/Vector3D.hpp"

/**
 * @brief Rectangle3D class, used to create a rectangle in 3D space (used for the camera) 
*/
class Rectangle3D {
    public:
        Rectangle3D(void);
        Rectangle3D(Math::Point3D t_origin, Math::Vector3D t_bottom_side, Math::Vector3D t_left_side);
        ~Rectangle3D(void) = default;
        Math::Point3D pointAt(double u, double v);
        Math::Point3D m_origin;
        Math::Vector3D m_bottom_side;
        Math::Vector3D m_left_side;

    protected:
    private:
};
