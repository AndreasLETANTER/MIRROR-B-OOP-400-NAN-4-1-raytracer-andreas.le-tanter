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
#include "RayTracer/Light/AmbiantLight/AmbiantLight.hpp"
#include "RayTracer/Light/DirectionalLight/DirectionalLight.hpp"
#include "RayTracer/Light/PointLight/PointLight.hpp"
#include "RayTracer/Light/ILights.hpp"
#include "RayTracer/Viewer/Viewer.hpp"
#include <iostream>

#define WIDTH 500
#define HEIGHT 500

int main(const int ac, const char **av)
{
    (void)av;
    if (ac != 1) {
        std::cerr << "The program takes no arguments" << std::endl;
        return 84;
    }
    RayTracer::Viewer viewer;
    viewer.init_menu();
    // std::cout << viewer.get_scene_name() << std::endl;
    // Parser::Parser parser(av[1]);
    // RayTracer::Camera cam = parser.getCamera();
    // RayTracer::Renderer renderer;

    // renderer.setCamera(cam);
    // renderer.setMissColor(Math::Vector3D(105, 105, 105));
    // renderer.setObjects(parser.getObjects());
    // renderer.setLights(parser.getLights());
    // renderer.renderScene();
    return 0;
}
