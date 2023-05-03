/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** main
*/

#include "RayTracer/Ray/Ray.hpp"
#include "RayTracer/Objects/Sphere/Sphere.hpp"
#include "RayTracer/Camera/Camera.hpp"
#include "RayTracer/Renderer/Renderer.hpp"
#include "Parser/Parser.hpp"
#include "RayTracer/Light/AmbiantLight/AmbiantLight.hpp"
#include "RayTracer/Light/DirectionalLight/DirectionalLight.hpp"
#include "RayTracer/Light/ILights.hpp"
#include <iostream>

#define WIDTH 2500
#define HEIGHT 2500

int main(const int ac, const char **av)
{
    (void)ac;
    Parser::Parser parser(av[1]);
    RayTracer::Camera cam;
    RayTracer::Renderer renderer;
    RayTracer::AmbiantLight ambiantLight(0.2);
    RayTracer::DirectionalLight directionalLight(Math::Vector3D(-1, 1, 1.5));
    std::vector<std::shared_ptr<RayTracer::ILights>> lights;

    lights.push_back(std::make_shared<RayTracer::AmbiantLight>(ambiantLight));
    lights.push_back(std::make_shared<RayTracer::DirectionalLight>(directionalLight));
    cam.m_origin = Math::Point3D(0, 0, -5);
    cam.m_screen = Rectangle3D(Math::Point3D(-0.25, -0.25, -4), Math::Vector3D(0.5, 0, 0), Math::Vector3D(0, 0.5, 0));
    renderer.setCamera(cam);
    renderer.setWidth(WIDTH);
    renderer.setHeight(HEIGHT);
    renderer.setMissColor(Math::Vector3D(105, 105, 105));
    renderer.setObjects(parser.getObjects());
    renderer.setLights(lights);
    renderer.renderScene();
    return 0;
}
