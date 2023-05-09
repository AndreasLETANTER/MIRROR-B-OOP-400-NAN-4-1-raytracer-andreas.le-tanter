/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Objects Abstract class
*/
#include "AObjects.hpp"

void RayTracer::AObjects::translate(Math::Point3D m_origin)
{
    m_position = m_origin;
}
