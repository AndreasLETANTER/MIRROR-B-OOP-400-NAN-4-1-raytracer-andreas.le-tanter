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

Factory::Factory::Factory()
{
}

Factory::Factory::~Factory()
{
}


RayTracer::Camera Factory::Factory::createCamera(double width, double heigth, Rectangle3D screen, double fov)
{
    RayTracer::Camera cam;

    cam.setResolution(width, heigth);
    cam.setScreen(fov, screen);
    return cam;
}

std::shared_ptr<RayTracer::AmbiantLight> Factory::Factory::createAmbiantLight(double intensity)
{
    RayTracer::AmbiantLight light(intensity);
    return std::make_shared<RayTracer::AmbiantLight>(light);
}

std::shared_ptr<RayTracer::PointLight> Factory::Factory::createPointLight(Math::Point3D position, double intensity)
{
    RayTracer::PointLight light(position, intensity);
    return std::make_shared<RayTracer::PointLight>(light);
}

std::shared_ptr<RayTracer::DirectionalLight> Factory::Factory::createDirectionalLight(Math::Vector3D direction)
{
    RayTracer::DirectionalLight light(direction);
    return std::make_shared<RayTracer::DirectionalLight>(light);
}

std::shared_ptr<RayTracer::IObjects> Factory::Factory::createSphere(Math::Point3D position, double radius, Math::Vector3D color)
{
    return std::make_shared<RayTracer::Sphere>(position, radius, color);
}

std::shared_ptr<RayTracer::IObjects> Factory::Factory::createPlane(Math::Point3D position, Math::Vector3D normal, Math::Vector3D color)
{
    return std::make_shared<RayTracer::Plane>(position, normal, color);
}
