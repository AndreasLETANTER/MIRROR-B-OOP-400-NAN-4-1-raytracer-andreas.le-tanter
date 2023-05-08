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

#include "IParser.hpp"
#include "../Factory/Factory.hpp"

namespace Parser
{
    class Parser : public IParser {
        public:
            // Constructor / Destructor
            Parser(void) = default;
            Parser(const char *t_filepath);
            ~Parser(void) = default;
            // Getters
            RayTracer::Camera getCamera(void);
            std::vector<std::shared_ptr<RayTracer::IObjects>> getObjects(void);
            std::vector<std::shared_ptr<RayTracer::ILights>> getLights(void);
        protected:
            // Main functions of parser
            void open_and_read_config_file(const char *t_filepath);
            void parse_config_file(void);
            void check_config_file(void);
            // Parser of 3 main objects
            void parse_objects(libconfig::Setting &t_objects);
            void parse_lights(libconfig::Setting &t_lights);
            void parse_camera(libconfig::Setting &t_camera);
            // Utils parse objects
            double parse_radius(libconfig::Setting &t_root, std::string t_path);
            double parse_intensity(libconfig::Setting &t_root, std::string t_path);
            Math::Point3D parse_position(libconfig::Setting &t_root, std::string t_path);
            Math::Point3D parse_origin(libconfig::Setting &t_root, std::string t_path);
            Math::Vector3D parse_color(libconfig::Setting &t_root, std::string t_path);
            Math::Vector3D parse_direction(libconfig::Setting &t_root, std::string t_path);
            Math::Vector3D parse_normal(libconfig::Setting &t_root, std::string t_path);
            Math::Vector3D parse_max_x(libconfig::Setting &t_root, std::string t_path);
            Math::Vector3D parse_max_y(libconfig::Setting &t_root, std::string t_path);
            Rectangle3D parse_screen(libconfig::Setting &t_root, std::string t_path);
        private:
            RayTracer::Camera m_cam;
            std::vector<std::shared_ptr<RayTracer::IObjects>> m_objects;
            std::vector<std::shared_ptr<RayTracer::ILights>> m_lights;
            libconfig::Config m_config;
            Factory::Factory *m_factory;
    };
}
