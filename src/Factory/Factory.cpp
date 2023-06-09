/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Factory
*/

#include <iostream>
#include <tuple>

#include "Factory.hpp"
#include "../RayTracer/Objects/Sphere/Sphere.hpp"
#include "../RayTracer/Objects/Plane/Plane.hpp"
#include "../RayTracer/Objects/Cone/Cone.hpp"

/**
 * @brief Create camera
 * @param t_width resolution
 * @param t_heigth resolution
 * @param t_screen rectangle of the screen
 * @param t_fov fov off the camera
 * @return RayTracer::Camera
*/
RayTracer::Camera Factory::Factory::createCamera(double t_width, double t_heigth, Rectangle3D t_screen, double t_fov)
{
    RayTracer::Camera cam;

    cam.setResolution(t_width, t_heigth);
    cam.setScreen(t_fov, t_screen);
    return cam;
}

/**
 * @brief Create ambient light
 * @param t_intensity of light
 * @return std::shared_ptr<RayTracer::AmbientLight>
*/
std::shared_ptr<RayTracer::AmbientLight> Factory::Factory::createAmbientLight(double t_intensity)
{
    RayTracer::AmbientLight light(t_intensity);
    return std::make_shared<RayTracer::AmbientLight>(light);
}

/**
 * @brief Create point light
 * @param t_position of light
 * @param t_intensity of light
 * @return std::shared_ptr<RayTracer::PointLight>
*/
std::shared_ptr<RayTracer::PointLight> Factory::Factory::createPointLight(Math::Point3D t_position, double t_intensity)
{
    RayTracer::PointLight light(t_position, t_intensity);
    return std::make_shared<RayTracer::PointLight>(light);
}

/**
 * @brief Create directional light
 * @param t_direction of light
 * @return std::shared_ptr<RayTracer::DirectionalLight>
*/
std::shared_ptr<RayTracer::DirectionalLight> Factory::Factory::createDirectionalLight(Math::Vector3D t_direction)
{
    RayTracer::DirectionalLight light(t_direction);
    return std::make_shared<RayTracer::DirectionalLight>(light);
}

/**
 * @brief Create sphere
 * @param t_position of sphere
 * @param t_radius of sphere
 * @param t_color of sphere
 * @return std::shared_ptr<RayTracer::IObjects>
*/
std::shared_ptr<RayTracer::IObjects> Factory::Factory::createSphere(Math::Point3D t_position, double t_radius, Math::Vector3D t_color)
{
    return std::make_shared<RayTracer::Sphere>(t_position, t_radius, t_color);
}

/**
 * @brief Create plane
 * @param t_position of plane
 * @param t_normal of plane
 * @param t_color of plane
 * @return std::shared_ptr<RayTracer::IObjects>
*/
std::shared_ptr<RayTracer::IObjects> Factory::Factory::createPlane(Math::Point3D t_position, Math::Vector3D t_normal, Math::Vector3D t_color)
{
    return std::make_shared<RayTracer::Plane>(t_position, t_normal, t_color);
}

/**
 * @brief Create cone
 * @param t_angle of cone
 * @param t_height of cone
 * @param t_tip of cone
 * @param t_axis of cone
 * @param t_color of cone
 * @return std::shared_ptr<RayTracer::IObjects>
*/
std::shared_ptr<RayTracer::IObjects> Factory::Factory::createCone(double t_angle, double t_height, Math::Vector3D t_tip, Math::Vector3D t_axis, Math::Vector3D t_color)
{
    return std::make_shared<RayTracer::Cone>(t_angle, t_height, t_tip, t_axis, t_color);
}
