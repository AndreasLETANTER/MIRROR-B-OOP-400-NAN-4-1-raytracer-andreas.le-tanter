/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** LightCalculation
*/

#include "LightCalculation.hpp"
#include <iostream>

Math::LightCalculation::LightCalculation()
{
}

Math::LightCalculation::~LightCalculation()
{
}

Math::Vector3D Math::LightCalculation::calculateLightEffect(Math::Vector3D t_base_color, std::vector<std::shared_ptr<RayTracer::ILights>> t_lights, Math::Vector3D t_direction, Math::Point3D t_origin)
{
    std::vector<Math::Vector3D> colors;
    Math::Vector3D color_result;
    double intensity = 0;

    for (size_t i = 0; i < t_lights.size(); i++) {
        colors.push_back(t_base_color);
        intensity = t_lights[i]->getIntensityAt(t_origin, t_direction);
        colors[i] *= intensity;
    }
    for (auto color : colors) {
        color_result += color;
    }
    return (color_result);
}
