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
    return (RayTracer::Ray(m_origin, m_screen.pointAt(u, v) - m_origin));
}

/**
 * @brief set the position of the camera
 * @param t_origin
*/
void RayTracer::Camera::setOrigin(Math::Point3D t_origin)
{
    m_origin = Math::Point3D(t_origin.m_x_component, t_origin.m_y_component, t_origin.m_z_component);
}

/**
 * @brief set the screen of the camera
 * @details the screen is defined by its fov and its resolution
 * @param t_fov the fov of the camera in degrees
*/
void RayTracer::Camera::setScreen(double t_fov, const Rectangle3D &t_screen)
{
    m_screen = t_screen;
    double distance = (m_screen.m_bottom_side.m_x_component / 2) / tan((t_fov / 2) * M_PI / 180);
    setOrigin(Math::Point3D(0, 0, m_screen.m_origin.m_z_component - distance));
}

/**
 * @brief set the resolution of the camera
 * @param t_width
 * @param t_height
*/
void RayTracer::Camera::setResolution(unsigned int t_width, unsigned int t_height)
{
    double aspect_ratio = t_width / t_height;

    m_width = t_width;
    m_height = t_width / aspect_ratio;
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
