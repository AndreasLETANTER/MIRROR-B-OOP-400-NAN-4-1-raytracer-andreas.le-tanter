/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Renderer
*/

#include "Renderer.hpp"
#include <iostream>

RayTracer::Renderer::Renderer()
{
}

RayTracer::Renderer::Renderer(int t_width, int t_height, RayTracer::Camera t_cam)
{
    m_width = t_width;
    m_height = t_height;
    m_cam = t_cam;
}

RayTracer::Renderer::~Renderer()
{
}

void RayTracer::Renderer::setHitColor(Math::Vector3D t_color)
{
    m_hit_color = t_color;
}

void RayTracer::Renderer::setMissColor(Math::Vector3D t_color)
{
    m_miss_color = t_color;
}

void RayTracer::Renderer::setWidth(int t_width)
{
    m_width = t_width;
}

void RayTracer::Renderer::setHeight(int t_height)
{
    m_height = t_height;
}

void RayTracer::Renderer::setCamera(RayTracer::Camera t_cam)
{
    m_cam = t_cam;
}

void RayTracer::Renderer::print_pixel(Math::Vector3D color)
{
    std::cout << color.m_x_component << " " << color.m_y_component << " " << color.m_z_component << std::endl;
}

void RayTracer::Renderer::print_header(void)
{
    std::cout << "P3" << std::endl;
    std::cout << m_height << " " << m_width << std::endl;
    std::cout << "255" << std::endl;
}

void RayTracer::Renderer::renderScene()
{
    RayTracer::Sphere s(Math::Point3D(0, -5, 0), 0.2);
    print_header();
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            double u = (double)x / m_height;
            double v = (double)y / m_width;
            RayTracer::Ray r = m_cam.rayAt(u, v);
            if (s.hits(r)) {
                print_pixel(m_hit_color);
            } else {
                print_pixel(m_miss_color);
            }
        }
        std::cout << std::endl;
    }
}
