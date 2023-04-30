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

namespace Factory
{
    class IFactory {
        public:
            virtual ~IFactory() = default;
            virtual std::vector<RayTracer::IObjects *> getObjects();
            virtual RayTracer::Camera getCamera();

            // Setters
            virtual RayTracer::Camera createCamera(libconfig::Setting &setting);
            virtual RayTracer::IObjects *createSphere(libconfig::Setting &setting);

        protected:
        private:
    };
}
