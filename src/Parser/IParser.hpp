/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** IParser
*/

#pragma once
#include "../RayTracer/Objects/IObjects.hpp"
#include "../RayTracer/Camera/Camera.hpp"
#include <libconfig.h++>
#include <vector>

namespace Parser
{
    class IParser {
        public:
            virtual ~IParser() = default;
            virtual void parse_config_file() = 0;
            virtual std::vector<RayTracer::IObjects *> getObjects() = 0;
            virtual RayTracer::Camera getCamera() = 0;

        protected:
        private:
    };
}
