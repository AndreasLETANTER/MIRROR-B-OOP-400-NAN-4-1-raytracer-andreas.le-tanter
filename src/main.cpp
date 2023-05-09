/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** main
*/

#include "RayTracer/Ray/Ray.hpp"
#include "RayTracer/Objects/Sphere/Sphere.hpp"
#include "RayTracer/Objects/Cylinder/Cylinder.hpp"
#include "RayTracer/Objects/Plane/Plane.hpp"
#include "RayTracer/Camera/Camera.hpp"
#include "RayTracer/Renderer/Renderer.hpp"
#include "Parser/Parser.hpp"
#include "RayTracer/Light/AmbiantLight/AmbiantLight.hpp"
#include "RayTracer/Light/DirectionalLight/DirectionalLight.hpp"
#include "RayTracer/Light/PointLight/PointLight.hpp"
#include "RayTracer/Light/ILights.hpp"
#include <iostream>

#define WIDTH 1000
#define HEIGHT 1000

int main(const int ac, const char **av)
{
    (void)ac;
    Parser::Parser parser(av[1]);
    RayTracer::Camera cam = parser.getCamera();
    RayTracer::Renderer renderer;
    renderer.setCamera(cam);
    renderer.setMissColor(Math::Vector3D(0, 0, 0));
    renderer.setMissColor(Math::Vector3D(105, 105, 105));
    renderer.setObjects(parser.getObjects());
    renderer.setLights(parser.getLights());
    renderer.renderScene();
    return 0;
}
