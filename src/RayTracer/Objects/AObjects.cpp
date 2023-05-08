/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Objects Abstract class
*/
#include "AObjects.hpp"

void RayTracer::AObjects::translate(Math::Point3D m_origin)
{
    this->m_position.m_x_component += m_origin.m_x_component;
    this->m_position.m_y_component += m_origin.m_y_component;
    this->m_position.m_z_component += m_origin.m_z_component;
}
