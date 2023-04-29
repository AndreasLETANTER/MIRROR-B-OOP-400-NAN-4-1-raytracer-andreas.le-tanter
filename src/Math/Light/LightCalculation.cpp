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

Math::Vector3D Math::LightCalculation::calculateLightEffect(Math::Vector3D t_base_color, std::vector<std::shared_ptr<RayTracer::ILights>> t_lights, Math::Vector3D t_surfaceNormal)
{
    std::vector<Math::Vector3D> colors;
    Math::Vector3D color_result;
    double intensity = 0;

    for (size_t i = 0; i < t_lights.size(); i++) {
        colors.push_back(t_base_color);
        intensity = t_lights[i]->getIntensityAt(t_surfaceNormal);
        //std::cout << "intensity: " << intensity << std::endl;
        colors[i] *= intensity;
        //std::cout << "color: " << colors[i].m_x_component << " " << colors[i].m_y_component << " " << colors[i].m_z_component << std::endl;
    }
    for (auto color : colors) {
        color_result += color;
    }
    return (color_result);
}
