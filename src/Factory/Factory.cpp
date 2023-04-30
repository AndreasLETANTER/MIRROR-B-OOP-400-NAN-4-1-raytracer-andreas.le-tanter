/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Factory
*/

#include <iostream>

#include "Factory.hpp"

Factory::Factory::Factory()
{
}

Factory::Factory::~Factory()
{
}

RayTracer::Camera Factory::Factory::createCamera(libconfig::Setting &setting)
{
    RayTracer::Camera cam;
    return cam;
}

RayTracer::IObjects *Factory::Factory::createSphere(libconfig::Setting &setting)
{
    (void)setting;
    return nullptr;
}
