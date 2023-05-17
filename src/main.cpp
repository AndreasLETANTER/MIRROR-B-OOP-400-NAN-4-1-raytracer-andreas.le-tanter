/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** main
*/

#include "RayTracer/Ray/Ray.hpp"
#include "RayTracer/Objects/Sphere/Sphere.hpp"
#include "RayTracer/Objects/Plane/Plane.hpp"
#include "RayTracer/Camera/Camera.hpp"
#include "RayTracer/Renderer/Renderer.hpp"
#include "Parser/Parser.hpp"
#include "RayTracer/Light/AmbientLight/AmbientLight.hpp"
#include "RayTracer/Light/DirectionalLight/DirectionalLight.hpp"
#include "RayTracer/Light/PointLight/PointLight.hpp"
#include "RayTracer/Light/ILights.hpp"
#include "RayTracer/Viewer/Viewer.hpp"
#include <iostream>

int main(const int ac, const char **av)
{
    RayTracer::Viewer viewer;
    std::string input;
    if (ac == 1)
        input = viewer.init_menu();
    else
        input = std::string(av[1]);
    Parser::Parser parser(input);
    RayTracer::Camera cam = parser.getCamera();
    RayTracer::Renderer renderer;
    renderer.setCamera(cam);
    renderer.setMissColor(Math::Vector3D(105, 105, 105));
    renderer.setObjects(parser.getObjects());
    renderer.setLights(parser.getLights());
    std::string output = "scenes/output.ppm";
    if (ac == 1)
        output = viewer.getOutput();
    renderer.renderScene(output);
    return 0;
}
