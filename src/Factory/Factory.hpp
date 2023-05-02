/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Factory
*/

#pragma once

#include <string>
#include <libconfig.h++>
#include <vector>

#include "../RayTracer/Objects/IObjects.hpp"
#include "../RayTracer/Camera/Camera.hpp"

namespace Factory
{
    class Factory {
        public:
            Factory();
            ~Factory();

            // Getters
            std::vector<RayTracer::IObjects *> getObjects();
            RayTracer::Camera getCamera();

            // Setters
            RayTracer::Camera createCamera(libconfig::Setting &setting);
            RayTracer::IObjects *createSphere(Math::Point3D position, double radius, Math::Vector3D color);

        protected:
            void open_and_read_config_file(const char *filepath);
        private:
            std::vector<RayTracer::IObjects *> m_objects;
            RayTracer::Camera m_cam;
    };
}
