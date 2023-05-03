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

Factory::Factory::Factory()
{
}

Factory::Factory::~Factory()
{
}

RayTracer::Camera Factory::Factory::createCamera(libconfig::Setting &setting)
{
    (void)setting;
    RayTracer::Camera cam;
    return cam;
}

std::shared_ptr<RayTracer::IObjects> Factory::Factory::createSphere(Math::Point3D position, double radius, Math::Vector3D color)
{
    std::shared_ptr<RayTracer::IObjects> sphere = std::make_shared<RayTracer::Sphere>(position, radius, color);
    return sphere;
}