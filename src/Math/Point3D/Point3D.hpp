/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Point3D
*/

#pragma once
#include "../Vector3D/Vector3D.hpp"

/**
 * @brief Point3D class, used to create a point in 3D space
 * @details the point is defined by its x, y and z coordinates
*/
namespace Math
{
    class Point3D {
        public:
            Point3D(void);
            Point3D(double t_x, double t_y, double t_z);
            Point3D(const Point3D &t_other) = default;
            Point3D &operator=(const Point3D &t_other) = default;
            Point3D(Point3D &&t_other) = default;
            Point3D &operator=(Point3D &&t_other) = default;
            ~Point3D(void) = default;
            Point3D operator+(const Vector3D &t_other);
            Point3D operator+=(const Vector3D &t_other);
            Vector3D operator-(const Point3D &t_other);
            Vector3D operator-=(const Point3D &t_other);
            Vector3D operator*(const Vector3D &t_other);
            Vector3D operator*=(const Vector3D &t_other);
            double m_x_component;
            double m_y_component;
            double m_z_component;

        protected:
        private:
    };
}
