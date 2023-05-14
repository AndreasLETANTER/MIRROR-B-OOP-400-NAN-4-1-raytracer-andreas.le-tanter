/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Renderer
*/

#include "Renderer.hpp"
#include "../../Math/Light/LightCalculation.hpp"
#include <iostream>
#include <limits>
#include <fstream>

/**
 * @brief Construct a new Ray Tracer:: Renderer:: Renderer object
 * @details set the width and the height of the scene to the given parameters
 * @details set the camera of the scene to the given parameter
 * @param t_cam the camera of the scene
*/
RayTracer::Renderer::Renderer(RayTracer::Camera t_cam)
{
    m_cam = t_cam;
}

/**
 * @brief setMissColor function, used to set the miss color of the scene
 * @param t_color the miss color of the scene
*/
void RayTracer::Renderer::setMissColor(Math::Vector3D t_color)
{
    m_miss_color = t_color;
}

/**
 * @brief setCamera function, used to set the camera of the scene
 * @param t_cam the camera of the scene
*/
void RayTracer::Renderer::setCamera(RayTracer::Camera t_cam)
{
    m_cam = t_cam;
}

/**
 * @brief setObjects function, used to set the objects of the scene
 * @param t_objects the objects of the scene
*/
void RayTracer::Renderer::setObjects(std::vector<std::shared_ptr<RayTracer::IObjects>> t_objects)
{
    m_objects = t_objects;
}

/**
 * @brief setLights function, used to set the lights of the scene
 * @param t_lights the lights of the scene
*/
void RayTracer::Renderer::setLights(std::vector<std::shared_ptr<RayTracer::ILights>> t_lights)
{
    m_lights = t_lights;
}

/**
 * @brief print_pixel function, used to print the color of the pixel
 * @details the function will print the color of the pixel in the ppm format
 * @param t_color the color of the pixel
 * @param t_file the file to print the color in
*/
void RayTracer::Renderer::print_pixel(Math::Vector3D t_color, std::fstream &t_file)
{
    if (t_color.m_x_component > 255)
        t_color.m_x_component = 255;
    if (t_color.m_y_component > 255)
        t_color.m_y_component = 255;
    if (t_color.m_z_component > 255)
        t_color.m_z_component = 255;
    if (t_color.m_x_component < 0)
        t_color.m_x_component = 0;
    if (t_color.m_y_component < 0)
        t_color.m_y_component = 0;
    if (t_color.m_z_component < 0)
        t_color.m_z_component = 0;
    t_file << (int)t_color.m_x_component << " " << (int)t_color.m_y_component << " " << (int)t_color.m_z_component << std::endl;
}

/**
 * @brief print_header function, used to print the header of the image
 * @details the function will print the header of the ppm image
 * @param t_file the file to print the header
*/
void RayTracer::Renderer::print_header(std::fstream &t_file)
{
    t_file << "P3" << std::endl;
    t_file << get<0>(m_cam.getResolution()) << " " << get<1>(m_cam.getResolution()) << std::endl;
    t_file << "255" << std::endl;
}

/**
 * @brief check_hit function, used to check if the ray hits something
 * @details the function will iterate through all the objects and check if the ray hits something
 * if it does, it will print the color of the object, if not, it will print the miss color
 * @param r the ray to check
 * @param t_file the file to print the color in
*/
void RayTracer::Renderer::check_hit(RayTracer::Ray r, std::fstream &t_file)
{
    bool hit_something = false;
    Math::LightCalculation light_calculation;
    std::pair<double, int> closest_object = std::make_pair(std::numeric_limits<double>::max(), -1);

    for (size_t i = 0; i < m_objects.size(); i++) {
        if (m_objects[i]->hits(r) && m_objects[i]->getHitDistance() < closest_object.first) {
            closest_object = std::make_pair(m_objects[i]->getHitDistance(), i);
            hit_something = true;
        }
    }
    if (hit_something) {
        print_pixel(light_calculation.calculateLightEffect(m_objects[closest_object.second]->getColor(), m_lights, m_objects[closest_object.second]), t_file);
    } else if (!hit_something) {
        print_pixel(m_miss_color, t_file);
    }
}

/**
 * @brief renderScene function, used to render the scene
 * @param t_file_name path to the file to write the image
 * @details the function will iterate through all the pixels of the image and check if the ray hits something 
*/
void RayTracer::Renderer::renderScene(std::string t_file_name)
{
    std::fstream file;
    file.open(t_file_name, std::fstream::out);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        exit(84);
    }
    print_header(file);
    unsigned int m_width = get<0>(m_cam.getResolution());
    unsigned int m_height = get<1>(m_cam.getResolution());

    for (unsigned int y = 0; y < m_height; y++) {
        for (unsigned int x = 0; x < m_width; x++) {
            double u = (double)x / m_height;
            double v = (double)y / m_width;
            RayTracer::Ray r = m_cam.rayAt(u, v);
            check_hit(r, file);
        }
        file << std::endl;
    }
    file.close();
}
