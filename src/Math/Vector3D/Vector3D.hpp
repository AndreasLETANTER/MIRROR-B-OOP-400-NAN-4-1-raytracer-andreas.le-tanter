/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Vector3D
*/

#pragma once

namespace Math
{
    class Vector3D {
        public:
            Vector3D(); // Constructor
            Vector3D(double t_x, double t_y, double t_z); // Constructor
            Vector3D(const Vector3D &t_other) = default;
            Vector3D &operator=(const Vector3D &t_other) = default;
            Vector3D(Vector3D &&t_other) = default;
            Vector3D &operator=(Vector3D &&t_other) = default;
            ~Vector3D();
            Vector3D operator+(const Vector3D &t_other);
            Vector3D operator+=(const Vector3D &t_other);
            Vector3D operator-(const Vector3D &t_other);
            Vector3D operator-=(const Vector3D &t_other);
            Vector3D operator*(const Vector3D &t_other);
            Vector3D operator*=(const Vector3D &t_other);
            Vector3D operator/(const Vector3D &t_other);
            Vector3D operator/=(const Vector3D &t_other);
            Vector3D operator*(const double &t_other);
            Vector3D operator*=(const double &t_other);
            Vector3D operator/(const double &t_other);
            Vector3D operator/=(const double &t_other);
            double dot_product(const Vector3D &t_other);
            double length();
            double m_x_component;
            double m_y_component;
            double m_z_component;


        protected:
        private:
    };
}
