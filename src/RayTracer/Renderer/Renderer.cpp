/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Renderer
*/

#include "Renderer.hpp"
#include "../../Math/Light/LightCalculation.hpp"
#include <iostream>

/**
 * @brief Construct a new Ray Tracer:: Renderer:: Renderer object
*/
RayTracer::Renderer::Renderer()
{
}

/**
 * @brief Construct a new Ray Tracer:: Renderer:: Renderer object
 * @details set the width and the height of the scene to the given parameters
 * @details set the camera of the scene to the given parameter
 * @param t_width 
 * @param t_height 
 * @param t_cam 
*/
RayTracer::Renderer::Renderer(int t_width, int t_height, RayTracer::Camera t_cam)
{
    m_width = t_width;
    m_height = t_height;
    m_cam = t_cam;
}

/**
 * @brief Destroy the Ray Tracer:: Renderer:: Renderer object
*/
RayTracer::Renderer::~Renderer()
{
}

/**
 * @brief setMissColor function, used to set the miss color of the scene
 * @param t_color 
*/
void RayTracer::Renderer::setMissColor(Math::Vector3D t_color)
{
    m_miss_color = t_color;
}

/**
 * @brief setWidth function, used to set the width of the scene
 * @param t_width 
*/
void RayTracer::Renderer::setWidth(int t_width)
{
    m_width = t_width;
}

/**
 * @brief setHeight function, used to set the height of the scene
 * @param t_height 
*/
void RayTracer::Renderer::setHeight(int t_height)
{
    m_height = t_height;
}

/**
 * @brief setCamera function, used to set the camera of the scene
 * @param t_cam
*/
void RayTracer::Renderer::setCamera(RayTracer::Camera t_cam)
{
    m_cam = t_cam;
}

/**
 * @brief setObjects function, used to set the objects of the scene
 * @param t_objects 
*/
void RayTracer::Renderer::setObjects(std::vector<std::shared_ptr<RayTracer::IObjects>> t_objects)
{
    m_objects = t_objects;
}

/**
 * @brief setLights function, used to set the lights of the scene
 * @param t_lights 
*/
void RayTracer::Renderer::setLights(std::vector<std::shared_ptr<RayTracer::ILights>> t_lights)
{
    m_lights = t_lights;
}

/**
 * @brief print_pixel function, used to print the color of the pixel
 * @details the function will print the color of the pixel in the ppm format
 * @param color 
*/
void RayTracer::Renderer::print_pixel(Math::Vector3D color)
{
    std::cout << (int) color.m_x_component << " " << (int) color.m_y_component << " " << (int) color.m_z_component << std::endl;
}

/**
 * @brief print_header function, used to print the header of the image
 * @details the function will print the header of the ppm image
*/
void RayTracer::Renderer::print_header(void)
{
    std::cout << "P3" << std::endl;
    std::cout << m_height << " " << m_width << std::endl;
    std::cout << "255" << std::endl;
}

/**
 * @brief check_hit function, used to check if the ray hits something
 * @details the function will iterate through all the objects and check if the ray hits something
 * if it does, it will print the color of the object, if not, it will print the miss color
 * @param r the ray to check
*/
void RayTracer::Renderer::check_hit(RayTracer::Ray r)
{
    bool hit_something = false;
    Math::LightCalculation light_calculation;

    for (size_t i = 0; i < m_objects.size(); i++) {
        if (m_objects[i]->hits(r)) {
            print_pixel(light_calculation.calculateLightEffect(m_objects[i]->getColor(), m_lights, r.m_direction, r.m_origin));
            hit_something = true;
            return;
        }
    }
    if (!hit_something)
        print_pixel(m_miss_color);
}

/**
 * @brief renderScene function, used to render the scene
 * @details the function will iterate through all the pixels of the image and check if the ray hits something 
*/
void RayTracer::Renderer::renderScene()
{
    print_header();
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            double u = (double)x / m_height;
            double v = (double)y / m_width;
            RayTracer::Ray r = m_cam.rayAt(u, v);
            check_hit(r);
        }
        std::cout << std::endl;
    }
}
