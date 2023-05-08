/*
** EPITECH PROJECT, 2023
** Matrix4D.cpp
** File description:
** Matrix4D.cpp
*/

#include "Matrix4D.hpp"

/**
 * @brief Construct a new Matrix4D:: Matrix4D
 * @details set all the matrix value to 0
*/
Math::Matrix4D::Matrix4D(void)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->_m_elements[i][j] = 0.0f;
        }
    }
}

Math::Matrix4D::Matrix4D(double elements[4][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->_m_elements[i][j] = elements[i][j];
        }
    }
}

double &Math::Matrix4D::get_elements(int row, int col)
{
    return _m_elements[row][col];
}

Math::Matrix4D Math::Matrix4D::inverse(void)
{
    Math::Matrix4D result;

    float det = get_determinant();
    if (det == 0.0f) {
        return result;
    }
    float invDet = 1.0f / det;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            float cofactor = getCofactor(i, j);
            result._m_elements[j][i] = cofactor * invDet;
        }
    }
    return result;
}
