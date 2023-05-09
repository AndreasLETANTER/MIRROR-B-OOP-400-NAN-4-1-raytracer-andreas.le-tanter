/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** IParser
*/

#pragma once

#include <libconfig.h++>
#include <vector>
#include <memory>

#include "../RayTracer/Camera/Camera.hpp"
#include "../RayTracer/Light/ILights.hpp"

namespace Parser
{
    class IParser {
        public:
            virtual ~IParser() = default;
            virtual RayTracer::Camera getCamera() = 0;
            virtual std::vector<std::shared_ptr<RayTracer::IObjects>> getObjects() = 0;
            virtual std::vector<std::shared_ptr<RayTracer::ILights>> getLights() = 0;
    };
}
