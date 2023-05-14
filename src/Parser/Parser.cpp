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

/**
 * @brief Constructor of Parser
 * @param t_filepath Path to the config file
 * @return Parser
*/
Parser::Parser::Parser(const std::string &t_filepath)
{
    m_factory = std::make_shared<Factory::Factory>();
    open_and_read_config_file(t_filepath.c_str());
    parse_config_file();
}

/**
 * @brief Parse direction
 * @param t_root Root of the config file
 * @param t_path Path to the config file
 * @return Math::Vector3D direction
*/
Math::Vector3D Parser::Parser::parse_direction(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".direction.";
    double x = t_root.lookup(name + "x");
    double y = t_root.lookup(name + "y");
    double z = t_root.lookup(name + "z");
    Math::Vector3D direction(x, y, z);

    return direction;
}

/**
 * @brief Parse intensity
 * @param t_root Root of the config file
 * @param t_path Path to the config file
 * @return double intensity
*/
double Parser::Parser::parse_intensity(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".intensity";
    double intensity = t_root.lookup(name);

    return intensity;
}

/**
 * @brief Parse position
 * @param t_root Root of the config file
 * @param t_path Path to the config file
 * @return Math::Point3D
*/
Math::Point3D Parser::Parser::parse_position(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".position.";
    double x = t_root.lookup(name + "x");
    double y = t_root.lookup(name + "y");
    double z = t_root.lookup(name + "z");
    Math::Point3D position(x, y, z);

    return position;
}

/**
 * @brief Parse normal
 * @param t_root Root of the config file
 * @param t_path Path to the config file
 * @return Math::Vector3D
*/
Math::Vector3D Parser::Parser::parse_normal(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".normal.";
    double x = t_root.lookup(name + "x");
    double y = t_root.lookup(name + "y");
    double z = t_root.lookup(name + "z");
    Math::Vector3D normal(x, y, z);

    return normal;
}

/**
 * @brief Parse origin
 * @param t_root Root of the config file
 * @param t_path Path to the config file
 * @return Math::Point3D
*/
Math::Point3D Parser::Parser::parse_origin(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".origin.";
    double x = t_root.lookup(name + "x");
    double y = t_root.lookup(name + "y");
    double z = t_root.lookup(name + "z");
    Math::Point3D origin(x, y, z);

    return origin;
}

/**
 * @brief Parse max x
 * @param t_root Root of the config file
 * @param t_path Path to the config file
 * @return Math::Vector3D
*/
Math::Vector3D Parser::Parser::parse_max_x(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".max_x.";
    double x = t_root.lookup(name + "x");
    double y = t_root.lookup(name + "y");
    double z = t_root.lookup(name + "z");
    Math::Vector3D max_x(x, y, z);

    return max_x;
}

/**
 * @brief Parse max y
 * @param t_root Root of the config file
 * @param t_path Path to the max y
 * @return Vector3D max y
*/
Math::Vector3D Parser::Parser::parse_max_y(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".max_y.";
    double x = t_root.lookup(name + "x");
    double y = t_root.lookup(name + "y");
    double z = t_root.lookup(name + "z");
    Math::Vector3D max_y(x, y, z);

    return max_y;
}

/**
 * @brief Parse screen
 * @param t_root Root of the config file
 * @param t_path Path to the screen
 * @return Rectangle3D screen
*/
Rectangle3D Parser::Parser::parse_screen(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".screen.";
    Math::Point3D origin = parse_origin(t_root, name);
    Math::Vector3D max_x = parse_max_x(t_root, name);
    Math::Vector3D max_y = parse_max_y(t_root, name);
    Rectangle3D screen(origin, max_x, max_y);

    return screen;
}

/**
 * @brief Parse radius
 * @param t_root Root of the config file
 * @param t_path Path to the radius
 * @return double radius
*/
double Parser::Parser::parse_radius(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".radius";
    double radius = t_root.lookup(name);

    return radius;
}

/**
 * @brief Parse color
 * @param t_root Root of the config file
 * @param t_path Path to the color
 * @return Math::Vector3D
*/
Math::Vector3D Parser::Parser::parse_color(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".color.";
    double r = t_root.lookup(name + "r");
    double g = t_root.lookup(name + "g");
    double b = t_root.lookup(name + "b");
    Math::Vector3D color(r, g, b);

    return color;
}

double Parser::Parser::parse_angle(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".angle";
    double angle = t_root.lookup(name);

    return angle;
}

double Parser::Parser::parse_height(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".height";
    double height = t_root.lookup(name);

    return height;
}

Math::Vector3D Parser::Parser::parse_tip(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".tip_position.";
    double x = t_root.lookup(name + "x");
    double y = t_root.lookup(name + "y");
    double z = t_root.lookup(name + "z");
    Math::Vector3D tip(x, y, z);

    return tip;
}

Math::Vector3D Parser::Parser::parse_axis(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".axis.";
    double x = t_root.lookup(name + "x");
    double y = t_root.lookup(name + "y");
    double z = t_root.lookup(name + "z");
    Math::Vector3D axis(x, y, z);

    return axis;
}

Math::Point3D Parser::Parser::parse_translation(libconfig::Setting &t_root, std::string t_path)
{
    std::string name = t_path + ".translation.";
    try {
        double x = t_root.lookup(name + "x");
        double y = t_root.lookup(name + "y");
        double z = t_root.lookup(name + "z");
        Math::Point3D translation(x, y, z);
        return translation;
    } catch (libconfig::SettingNotFoundException &nfex) {
        return Math::Point3D(0, 0, 0);
    }
}

/**
 * @brief Parse lights
 * @details Parse lights from config file
 * @param t_root Root of the config file
 * @return void
*/
void Parser::Parser::parse_lights(libconfig::Setting &t_root)
{
    for (int i = 0; i != t_root.getLength(); i++) {
        std::string type = t_root[i].getName();
        if (type == "camera" || type == "objects")
            continue;
        for (int j = 0; j != t_root[i].getLength(); j++) {
            std::string type = t_root[i][j].getName();
            if (type.find("ambient-") == 0) {
                std::string path = std::string(t_root[i].getName()) + "." + t_root[i][j].getName();
                double intensity = parse_intensity(t_root, path);
                m_lights.push_back(m_factory->createAmbientLight(intensity));
            } else if (type.find("directional-") == 0) {
                std::string path = std::string(t_root[i].getName()) + "." + t_root[i][j].getName();
                Math::Vector3D position = parse_direction(t_root, path);
                m_lights.push_back(m_factory->createDirectionalLight(position));
            } else if (type.find("point-") == 0) {
                std::string path = std::string(t_root[i].getName()) + "." + t_root[i][j].getName();
                Math::Point3D position = parse_position(t_root, path);
                double intensity = parse_intensity(t_root, path);
                m_lights.push_back(m_factory->createPointLight(position, intensity));
            }
        }
    }
}

/**
 * @brief Parse the objects in the scene
 * @details Parse sphere, plane, cylinder and cone objects
 * @param root The root of the configuration file
 * @return void
*/
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
                Math::Point3D translation = parse_translation(root, path);
                std::shared_ptr<RayTracer::IObjects> sphere = m_factory->createSphere(position, radius, color);
                if (translation.m_x_component != 0 || translation.m_y_component != 0 || translation.m_z_component != 0) {
                    sphere->translate(translation);
                }
                m_objects.push_back(sphere);
            }
            if (type.find("plane-") == 0) {
                std::string path = std::string(root[i].getName()) + "." + root[i][j].getName();
                Math::Point3D position = parse_position(root, path);
                Math::Vector3D normal = parse_normal(root, path);
                Math::Vector3D color = parse_color(root, path);
                Math::Point3D translation = parse_translation(root, path);
                std::shared_ptr<RayTracer::IObjects> plane = m_factory->createPlane(position, normal, color);
                if (translation.m_x_component != 0 || translation.m_y_component != 0 || translation.m_z_component != 0) {
                    plane->translate(translation);
                }
                m_objects.push_back(plane);
            }
            if (type.find("cone-") == 0) {
                std::string path = std::string(root[i].getName()) + "." + root[i][j].getName();
                double angle = parse_angle(root, path);
                double height = parse_height(root, path);
                Math::Vector3D tip = parse_tip(root, path);
                Math::Vector3D axis = parse_axis(root, path);
                Math::Vector3D color = parse_color(root, path);
                Math::Point3D translation = parse_translation(root, path);
                std::shared_ptr<RayTracer::IObjects> cone = m_factory->createCone(angle, height, tip, axis, color);
                if (translation.m_x_component != 0 || translation.m_y_component != 0 || translation.m_z_component != 0) {
                    cone->translate(translation);
                }
                m_objects.push_back(cone);
            }
        }
    }
}

/**
 * @brief Parse camera from config file
 * @details Parse resolution, screen, fov
 * @param t_root root of config file
 * @return void
*/
void Parser::Parser::parse_camera(libconfig::Setting &t_root)
{
    for (int i = 0; i != t_root.getLength(); i++) {
        std::string type = t_root[i].getName();
        if (type == "lights" || type == "objects")
            continue;
        std::string name = t_root[i].getName();
        for (int j = 0; j != t_root[i].getLength(); j++) {
            std::string type = t_root[i][j].getName();
            double width = t_root.lookup(name + ".resolution.width");
            double height = t_root.lookup(name + ".resolution.height");
            Rectangle3D screen = parse_screen(t_root, name);
            double fov = t_root.lookup(name + ".fov");
            m_cam = m_factory->createCamera(width, height, screen, fov);
        }
    }
}

/**
 * @brief Get the objects
 * @return std::vector<std::shared_ptr<RayTracer::IObjects>>
*/
std::vector<std::shared_ptr<RayTracer::IObjects>> Parser::Parser::getObjects(void)
{
    return m_objects;
}

/**
 * @brief Get the camera object
 * @return RayTracer::Camera
*/
RayTracer::Camera Parser::Parser::getCamera(void)
{
    return m_cam;
}

/**
 * @brief Get the lights object
 * @return std::vector<std::shared_ptr<RayTracer::ILights>>
*/
std::vector<std::shared_ptr<RayTracer::ILights>> Parser::Parser::getLights(void)
{
    return m_lights;
}

/**
 * @brief Parse the config file
 * @details Parse the config file and create the objects, lights and camera
 * @return void
*/
void Parser::Parser::parse_config_file(void)
{
    libconfig::Setting &root = m_config.getRoot();

    Parser::Parser::parse_camera(root);
    Parser::Parser::parse_objects(root);
    Parser::Parser::parse_lights(root);
}

/**
 * @brief Check if the config file is valid
 * @details Check if the config file contains a camera, at least one object and one light
 * @return void
*/
void Parser::Parser::check_config_file(void)
{
    try {
        libconfig::Setting &root = m_config.getRoot();
        libconfig::Setting &camera = root["camera"];
        libconfig::Setting &objects = root["objects"];
        libconfig::Setting &lights = root["lights"];

        if (camera.getLength() != 1)
            throw std::exception();
        if (objects.getLength() < 1)
            throw std::exception();
        if (lights.getLength() < 1)
            throw std::exception();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Open and read the config file
 * @param t_filepath The path of the config file
 * @return void
*/
void Parser::Parser::open_and_read_config_file(const std::string &t_filepath)
{
    try{
        m_config.readFile(t_filepath.c_str());
    } catch (const libconfig::FileIOException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    } catch (const libconfig::ParseException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}
