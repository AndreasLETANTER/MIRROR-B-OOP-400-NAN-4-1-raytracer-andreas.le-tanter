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
            this->_matrix[i][j] = 0.0f;
        }
    }
}

/**
 * @brief Construct a new Matrix4D:: Matrix4D object
 * @details set the float matrix _matrix value to the given parameters
 * @param elements
*/
Math::Matrix4D::Matrix4D(double elements[4][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->_matrix[i][j] = elements[i][j];
        }
    }
}

/**
 * @brief get the one element of the matrix
 * @param row
 * @param col
 * @return double
*/
double Math::Matrix4D::get_elements(int row, int col)
{
    return _matrix[row][col];
}

/**
 * @brief inverse all the elements of the matrix with the deteminant and the Cofactor
 * @return Math::Matrix4D
*/
Math::Matrix4D Math::Matrix4D::inverse(void)
{
    Math::Matrix4D result;
    double det = get_determinant();
    double invDet = 0.0;
    double cofactor = 0.0;

    if (det == 0.0f) {
        return result;
    }
    invDet = 1.0f / det;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cofactor = getCofactor(i, j);
            result._matrix[j][i] = cofactor * invDet;
        }
    }
    return result;
}

/**
 * @brief calcul the determinant of the matrix and return it
 * @return double
*/
double Math::Matrix4D::get_determinant(void)
{
    double det = 0.0;
    double cofactor = 0.0;

    for (int col = 0; col < 4; col++) {
        cofactor = getCofactor(0, col);
        det += _matrix[0][col] * cofactor;
    }
    return (det);
}

/**
 * @brief calcul the cofactor of the matrix and return it
 * @param row
 * @param col
 * @return double
*/
double Math::Matrix4D::getCofactor(int row, int col)
{
    double subMatrix[3][3];
    int subRow = 0;
    int subCol = 0;
    double sign = 0.0;
    double cofactor = 0.0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != row && j != col) {
                subMatrix[subRow][subCol] = _matrix[i][j];
                subCol++;
                if (subCol == 3) {
                    subCol = 0;
                    subRow++;
                }
            }
        }
    }
    sign = ((row + col) % 2 == 0) ? 1.0f : -1.0f;
    cofactor = sign * get_determinant3x3(subMatrix);
    return (cofactor);
}

/**
 * @brief calcul the determinant of a matrix 3x3 and return it
 * @param matrix
 * @return double
*/
double Math::Matrix4D::get_determinant3x3(double matrix[3][3])
{
    float det = 0.0f;

    det += matrix[0][0] * (matrix[1][1] * matrix[2][2]
    - matrix[1][2] * matrix[2][1]);
    det -= matrix[0][1] * (matrix[1][0] * matrix[2][2]
    - matrix[1][2] * matrix[2][0]);
    det += matrix[0][2] * (matrix[1][0] * matrix[2][1]
    - matrix[1][1] * matrix[2][0]);
    return (det);
}
