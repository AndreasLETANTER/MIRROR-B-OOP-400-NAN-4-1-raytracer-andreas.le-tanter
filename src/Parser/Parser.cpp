/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Parser
*/

#include <ostream>
#include <iostream>
#include <vector>
#include <tuple>

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

void Parser::Parser::check_config_file()
{
    try {
        libconfig::Setting &root = m_config.getRoot();
        libconfig::Setting &camera = root["camera"];
        libconfig::Setting &objects = root["objects"];
        if (camera.getLength() != 1)
            throw std::exception();
        if (objects.getLength() < 1)
            throw std::exception();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Parser::Parser::parse_lights(libconfig::Setting &root)
{
    for (int i = 0; i != root.getLength(); i++) {
        std::string type = root[i].getName();
        if (type == "camera" || type == "objects")
            continue;
        for (int j = 0; j != root[i].getLength(); j++) {
            std::string type = root[i][j].getName();
            if (type.find("ambient-") == 0) {
                std::string path = std::string(root[i].getName()) + "." + root[i][j].getName();
                double intensity = parse_intensity(root, path);
                m_lights.push_back(m_factory->createAmbiantLight(intensity));
            } else if (type.find("directional-") == 0) {
                std::string path = std::string(root[i].getName()) + "." + root[i][j].getName();
                Math::Vector3D position = parse_direction(root, path);
                m_lights.push_back(m_factory->createDirectionalLight(position));
            }
        }
    }
}

void Parser::Parser::parse_camera(libconfig::Setting &root)
{
    for (int i = 0; i != root.getLength(); i++) {
        std::string type = root[i].getName();
        if (type == "objects" || type == "lights")
            continue;
        m_cam.m_origin = parse_position(root, "camera");
        double fov = root.lookup("camera.fov");
        (void)fov;
    }
}

Math::Vector3D Parser::Parser::parse_direction(libconfig::Setting &root, std::string path)
{
    std::string name = path + ".direction.";
    double x = root.lookup(name + "x");
    double y = root.lookup(name + "y");
    double z = root.lookup(name + "z");
    Math::Vector3D direction(x, y, z);
    return direction;
}

double Parser::Parser::parse_intensity(libconfig::Setting &root, std::string path)
{
    std::string name = path + ".intensity";
    double intensity = root.lookup(name);
    return intensity;
}

Math::Point3D Parser::Parser::parse_position(libconfig::Setting &root, std::string path)
{
    std::string name = path + ".position.";
    double x = root.lookup(name + "x");
    double y = root.lookup(name + "y");
    double z = root.lookup(name + "z");
    Math::Point3D position(x, y, z);
    return position;
}

double Parser::Parser::parse_radius(libconfig::Setting &root, std::string path)
{
    std::string name = path + ".radius";
    double radius = root.lookup(name);
    return radius;
}

Math::Vector3D Parser::Parser::parse_color(libconfig::Setting &root, std::string path)
{
    std::string name = path + ".color.";
    double r = root.lookup(name + "r");
    double g = root.lookup(name + "g");
    double b = root.lookup(name + "b");
    Math::Vector3D color(r, g, b);
    return color;
}

void Parser::Parser::parse_objects(libconfig::Setting &root)
{
    for (int i = 0; i != root.getLength(); i++) {
        std::string type = root[i].getName();
        if (type == "camera" || type == "lights")
            continue;
        for (int j = 0; j != root[i].getLength(); j++) {
            std::string type = root[i][j].getName();
            if (type.find("sphere-") == 0) {
                std::string path = std::string(root[i].getName()) + "." + root[i][j].getName();
                Math::Point3D position = parse_position(root, path);
                double radius = parse_radius(root, path);
                Math::Vector3D color = parse_color(root, path);
                m_objects.push_back(m_factory->createSphere(position, radius, color));
            }
        }
    }
}

void Parser::Parser::parse_config_file()
{
    libconfig::Setting &root = m_config.getRoot();
    Parser::Parser::parse_camera(root);
    Parser::Parser::parse_objects(root);
    Parser::Parser::parse_lights(root);
}

std::vector<std::shared_ptr<RayTracer::IObjects>> Parser::Parser::getObjects()
{
    return m_objects;
}

RayTracer::Camera Parser::Parser::getCamera()
{
    return m_cam;
}

std::vector<std::shared_ptr<RayTracer::ILights>> Parser::Parser::getLights()
{
    return m_lights;
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
