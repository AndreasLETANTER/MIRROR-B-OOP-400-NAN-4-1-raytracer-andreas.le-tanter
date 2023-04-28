/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Parser
*/

#pragma once
#include <string>

namespace Parser
{
    class Parser {
        public:
            Parser();
            ~Parser();
            void parse_config_file();
            std::vector<RayTracer::IObjects *> getObjects();
            RayTracer::Camera getCamera();

        protected:
        private:
            std::vector<RayTracer::IObjects *> m_objects;
            RayTracer::Camera m_cam;
            std::string m_file_path;
    };
}
