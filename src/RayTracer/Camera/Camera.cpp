/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Camera
*/

#include "Camera.hpp"
#include <iostream>

/**
 * @brief Construct a new Camera object
 * 
*/
RayTracer::Camera::Camera()
{
}

/**
 * @brief Destroy the Camera object
 * */
RayTracer::Camera::~Camera()
{
}

/**
 * @brief get the ray at the given coordinates
 * @details the ray is defined by the origin of the camera and the point at the given coordinates on the screen
 * @param u 
 * @param v 
 * @return RayTracer::Ray 
*/
RayTracer::Ray RayTracer::Camera::rayAt(double u, double v)
{
    return (RayTracer::Ray(m_origin, m_screen.pointAt(u, v) - m_origin));
}
