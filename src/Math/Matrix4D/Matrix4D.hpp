/*
** EPITECH PROJECT, 2023
** Matrix4D.hpp
** File description:
** Matrix4D.hpp
*/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <utility>

namespace Math
{
    class Matrix4D {
        public:
            Matrix4D(void);
            Matrix4D(double element[4][4]);
            Matrix4D(const Matrix4D &t_other) = default;
            Matrix4D &operator=(const Matrix4D &t_other) = default;
            Matrix4D(Matrix4D &&t_other) = default;
            Matrix4D &operator=(Matrix4D &&t_other) = default;
            ~Matrix4D(void) = default;
            double &get_elements(int row, int col);
            Math::Matrix4D inverse(void);
            double get_determinant(void);
            double getCofactor(int row, int col);
        public:
            double _m_elements[4][4];
    };
}
