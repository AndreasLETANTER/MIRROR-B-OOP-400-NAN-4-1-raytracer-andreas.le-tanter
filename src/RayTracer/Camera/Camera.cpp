/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Camera
*/

#include "Camera.hpp"
#include <iostream>
#include <cmath>

/**
 * @brief get the ray at the given coordinates
 * @details the ray is defined by the origin of the camera and the point at the given coordinates on the screen
 * @param u 
 * @param v 
 * @return RayTracer::Ray 
*/
RayTracer::Ray RayTracer::Camera::rayAt(double u, double v)
{
    return (RayTracer::Ray(m_position, m_screen.pointAt(u, v) - m_position));
}

/**
 * @brief set the position of the camera
 * @param t_origin 
*/
void RayTracer::Camera::setPosition(Math::Point3D t_origin)
{
    m_screen = Rectangle3D(Math::Point3D(t_origin.m_x_component - 0.25, t_origin.m_y_component - 0.25, t_origin.m_z_component), Math::Vector3D(0.5, 0, 0), Math::Vector3D(0, 0.5, 0));
}

/**
 * @brief set the screen of the camera
 * @details the screen is defined by its fov and its resolution
 * @param t_fov the fov of the camera in degrees
*/
void RayTracer::Camera::setScreen(double t_fov)
{
    double distance = -5; //nugo need to fill this (the value of the distance with the given parameter in the main should give -5 in value)

    (void) t_fov;
    m_position = Math::Point3D(m_screen.m_origin.m_x_component + 0.25, m_screen.m_origin.m_y_component + 0.25, distance);
}

/**
 * @brief set the resolution of the camera
 * @param t_width 
 * @param t_height 
*/
void RayTracer::Camera::setResolution(int t_width, int t_height)
{
    m_width = t_width;
    m_height = t_height;
}

/**
 * @brief rotate the screen of the camera
 * @details rotate the screen of the camera by the given rotation
 * @param t_rotation 
*/
void RayTracer::Camera::rotateScreen(Math::Vector3D t_rotation)
{
    (void) t_rotation;
}
