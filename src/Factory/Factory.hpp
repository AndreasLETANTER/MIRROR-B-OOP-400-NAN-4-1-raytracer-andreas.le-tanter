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
#include <memory>

#include "../RayTracer/Objects/IObjects.hpp"
#include "../RayTracer/Camera/Camera.hpp"
#include "../RayTracer/Light/AmbiantLight/AmbiantLight.hpp"
#include "../RayTracer/Light/DirectionalLight/DirectionalLight.hpp"

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
            std::shared_ptr<RayTracer::AmbiantLight> createAmbiantLight(double intensity);
            std::shared_ptr<RayTracer::DirectionalLight> createDirectionalLight(Math::Vector3D direction);
            std::shared_ptr<RayTracer::IObjects> createSphere(Math::Point3D position, double radius, Math::Vector3D color);

        protected:
            void open_and_read_config_file(const char *filepath);
        private:
            std::vector<RayTracer::IObjects *> m_objects;
            RayTracer::Camera m_cam;
    };
}
