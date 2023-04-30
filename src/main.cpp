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
    RayTracer::Camera cam;
    RayTracer::Renderer renderer;
    RayTracer::Sphere sphere(Math::Point3D(0.5, -5, 0), 0.3, Math::Vector3D(153, 0, 153));
    RayTracer::Sphere sphere2(Math::Point3D(-0.5, -5, 0), 0.3, Math::Vector3D(255, 255, 0));
    RayTracer::Sphere sphere3(Math::Point3D(0, -5, 0.5), 0.3, Math::Vector3D(178, 255, 102));
    RayTracer::Sphere sphere4(Math::Point3D(0, -5, -0.5), 0.3, Math::Vector3D(255, 153, 153));
    std::vector<RayTracer::IObjects *> objects;

    objects.push_back(&sphere);
    objects.push_back(&sphere2);
    objects.push_back(&sphere3);
    objects.push_back(&sphere4);
    cam.m_origin = Math::Point3D(0, 5, 0);
    cam.m_screen = Rectangle3D(Math::Point3D(-0.5, 0, -0.5), Math::Vector3D(1, 0, 0), Math::Vector3D(0, 0, 1));
    renderer.setCamera(cam);
    renderer.setWidth(WIDTH);
    renderer.setHeight(HEIGHT);
    renderer.setMissColor(Math::Vector3D(0, 0, 0));
    renderer.setObjects(objects);
    renderer.renderScene();
    return 0;
}
