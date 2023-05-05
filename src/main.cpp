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
#include "RayTracer/Light/AmbiantLight/AmbiantLight.hpp"
#include "RayTracer/Light/DirectionalLight/DirectionalLight.hpp"
#include "RayTracer/Light/PointLight/PointLight.hpp"
#include "RayTracer/Light/ILights.hpp"
#include <iostream>

#define WIDTH 2000
#define HEIGHT 2000

int main(void)
{
    RayTracer::Camera cam;
    RayTracer::Renderer renderer;
    RayTracer::Sphere sphere(Math::Point3D(0, -0.2, 0), 0.3, Math::Vector3D(153, 0, 153));
    RayTracer::Plane plane(Math::Point3D(0., 0.4, 0.), Math::Vector3D(0., -1., 0.), Math::Vector3D(18, 164, 139));
    RayTracer::AmbiantLight ambiantLight(0.2);
    RayTracer::PointLight pointLight(Math::Point3D(3, -7, -6), 2);
    std::vector<std::shared_ptr<RayTracer::IObjects>> objects;
    std::vector<std::shared_ptr<RayTracer::ILights>> lights;

    objects.push_back(std::make_shared<RayTracer::Sphere>(sphere));
    objects.push_back(std::make_shared<RayTracer::Plane>(plane));
    lights.push_back(std::make_shared<RayTracer::AmbiantLight>(ambiantLight));
    lights.push_back(std::make_shared<RayTracer::PointLight>(pointLight));
    cam.setResolution(WIDTH, HEIGHT);
    cam.setScreen(25, Rectangle3D(Math::Point3D(-0.5, -0.5, -4), Math::Vector3D(1., 0, 0), Math::Vector3D(0, 1., 0)));
    renderer.setCamera(cam);
    renderer.setMissColor(Math::Vector3D(105, 105, 105));
    renderer.setObjects(objects);
    renderer.setLights(lights);
    renderer.renderScene();
    return 0;
}
