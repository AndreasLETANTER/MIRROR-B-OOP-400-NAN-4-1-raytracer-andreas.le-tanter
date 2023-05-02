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
#include <iostream>

#define WIDTH 1500
#define HEIGHT 1500

int main(const int ac, const char **av)
{
    (void)ac;
    Parser::Parser parser(av[1]);
    RayTracer::Camera cam;
    RayTracer::Renderer renderer;
    cam.m_origin = Math::Point3D(0, 0, -5);
    cam.m_screen = Rectangle3D(Math::Point3D(-0.25, -0.25, -4.0), Math::Vector3D(0.5, 0, 0), Math::Vector3D(0, 0, 0.5));
    renderer.setCamera(cam);
    renderer.setWidth(WIDTH);
    renderer.setHeight(HEIGHT);
    renderer.setMissColor(Math::Vector3D(0, 0, 0));
    renderer.setObjects(parser.getObjects());
    renderer.renderScene();
    return 0;
}
