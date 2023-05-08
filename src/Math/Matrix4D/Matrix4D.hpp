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
            Matrix4D(std::map<int, std::vector<std::pair<double, double>
            , std::pair<double, double>>> mat4D);
            Matrix4D(const Matrix4D &t_other) = default;
            Matrix4D &operator=(const Matrix4D &t_other) = default;
            Matrix4D(Matrix4D &&t_other) = default;
            Matrix4D &operator=(Matrix4D &&t_other) = default;
            ~Matrix4D(void) = default;
        public:
            std::map<int, std::vector<std::pair<double, double>
            , std::pair<double, double>>> _mat4D;
    };
}
