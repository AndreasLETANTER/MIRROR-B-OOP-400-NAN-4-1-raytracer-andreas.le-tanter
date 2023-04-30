/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Parser
*/

#include <ostream>
#include <iostream>
#include <vector>

#include "Parser.hpp"
#include "../Factory/Factory.hpp"

Parser::Parser::Parser(const char *filepath)
{
    m_factory = new Factory::Factory();
    open_and_read_config_file(filepath);
    parse_config_file();
}

Parser::Parser::~Parser()
{
}

void Parser::Parser::parse_config_file()
{
    libconfig::Setting &root = m_config.getRoot();
    libconfig::Setting &camera = root["camera"];
    try
    {
        m_cam = m_factory->createCamera(camera);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < camera.getLength(); i++) {
        libconfig::Setting &setting = camera[i];
        std::cout << "Setting name: " << setting.getName() << std::endl;
    }
}

std::vector<RayTracer::IObjects *> Parser::Parser::getObjects()
{
    return m_objects;
}

RayTracer::Camera Parser::Parser::getCamera()
{
    return m_cam;
}

void Parser::Parser::open_and_read_config_file(const char *filepath)
{
    try{
        m_config.readFile(filepath);
    } catch (const libconfig::FileIOException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    } catch (const libconfig::ParseException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}
