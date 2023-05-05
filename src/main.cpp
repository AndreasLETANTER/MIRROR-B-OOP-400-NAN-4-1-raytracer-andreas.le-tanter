/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** main
*/

#include "RayTracer/Ray/Ray.hpp"
#include "RayTracer/Objects/Sphere/Sphere.hpp"
#include "RayTracer/Objects/Cylindre/Cylinder.hpp"
#include "RayTracer/Camera/Camera.hpp"
#include "RayTracer/Renderer/Renderer.hpp"
#include <iostream>

#define WIDTH 1500
#define HEIGHT 1500

int main(void)
{
    RayTracer::Camera cam;
    RayTracer::Renderer renderer;
    RayTracer::Sphere sphere(Math::Point3D(0, -5, 0), 0.3);
    RayTracer::Cylinder cylinder(Math::Point3D(0, -5, 0), 0.3, 0.1);

    cam.m_origin = Math::Point3D(0, 5, 0);
    cam.m_screen = Rectangle3D(Math::Point3D(-0.5, 0, -0.5), Math::Vector3D(1, 0, 0), Math::Vector3D(0, 0, 1));
    renderer.setCamera(cam);
    renderer.setWidth(WIDTH);
    renderer.setHeight(HEIGHT);
    renderer.setHitColor(Math::Vector3D(255, 0, 0));
    renderer.setMissColor(Math::Vector3D(0, 0, 0));
    renderer.setObject(&cylinder);
    renderer.renderScene();
    return 0;
}
