/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter [WSL: Ubuntu]
** File description:
** main
*/

#include "RayTracer/Ray/Ray.hpp"
#include "RayTracer/Sphere/Sphere.hpp"
#include "RayTracer/Camera/Camera.hpp"
#include <iostream>

#define WIDTH 1500
#define HEIGHT 1500

static void printPPMHeader(void)
{
    std::cout << "P3" << std::endl;
    std::cout << HEIGHT << " " << WIDTH << std::endl;
    std::cout << "255" << std::endl;
}

static void write_color(Math::Vector3D color)
{
    std::cout << color.m_x_component << " " << color.m_y_component << " " << color.m_z_component << std::endl;
}

int main(void)
{
    RayTracer::Camera cam;

    printPPMHeader();
    cam.m_origin = Math::Point3D(0, 5, 0);
    cam.m_screen = Rectangle3D(Math::Point3D(-0.5, 0, -0.5), Math::Vector3D(1, 0, 0), Math::Vector3D(0, 0, 1));
    RayTracer::Sphere s(Math::Point3D(0, -5, 0), 0.2);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double u = (double)x / HEIGHT;
            double v = (double)y / WIDTH;
            RayTracer::Ray r = cam.rayAt(u, v);
            if (s.hits(r)) {
                write_color(Math::Vector3D(255, 0, 0));
            } else {
                write_color(Math::Vector3D(0, 0, 255));
            }
        }
        std::cout << std::endl;
    }
}
