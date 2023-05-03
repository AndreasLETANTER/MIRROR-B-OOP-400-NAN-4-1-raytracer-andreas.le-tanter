/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Parser
*/

#pragma once

#include <string>
#include <libconfig.h++>
#include <vector>

#include "../RayTracer/Objects/IObjects.hpp"
#include "../RayTracer/Camera/Camera.hpp"
#include "../Factory/Factory.hpp"

namespace Parser
{
    class Parser {
        public:
            Parser() = default;
            Parser(const char *filepath);
            ~Parser();
            std::vector<std::shared_ptr<RayTracer::IObjects>> getObjects();
            RayTracer::Camera getCamera();
        protected:
            void open_and_read_config_file(const char *filepath);
            void parse_config_file();
            void check_config_file();
            void parse_camera(libconfig::Setting &camera);
            void parse_objects(libconfig::Setting &objects);
            Math::Point3D parse_position(libconfig::Setting &root, std::string path);
            double parse_radius(libconfig::Setting &root, std::string path);
            Math::Vector3D parse_color(libconfig::Setting &root, std::string path);
        private:
            std::vector<std::shared_ptr<RayTracer::IObjects>> m_objects;
            RayTracer::Camera m_cam;
            std::string m_file_path;
            libconfig::Config m_config;
            Factory::Factory *m_factory;
    };
}
