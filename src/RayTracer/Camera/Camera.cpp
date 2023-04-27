/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Camera
*/

#include "Camera.hpp"
#include <iostream>

RayTracer::Camera::Camera()
{
}

RayTracer::Camera::~Camera()
{
}

RayTracer::Ray RayTracer::Camera::rayAt(double u, double v)
{
    return (RayTracer::Ray(m_origin, m_screen.pointAt(u, v) - m_origin));
}
