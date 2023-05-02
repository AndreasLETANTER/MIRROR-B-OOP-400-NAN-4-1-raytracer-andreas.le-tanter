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
#include "RayTracer/Light/AmbiantLight/AmbiantLight.hpp"
#include "RayTracer/Light/DirectionalLight/DirectionalLight.hpp"
#include "RayTracer/Light/ILights.hpp"
#include <iostream>

#define WIDTH 2000
#define HEIGHT 2000

int main(void)
{
    RayTracer::Camera cam;
    RayTracer::Renderer renderer;
    RayTracer::Sphere sphere(Math::Point3D(0.5, 0.5, 0), 0.3, Math::Vector3D(153, 0, 153));
    RayTracer::Sphere sphere2(Math::Point3D(-0.5, 0.5, 0), 0.3, Math::Vector3D(255, 255, 0));
    RayTracer::Sphere sphere3(Math::Point3D(0.5, -0.5, 0), 0.3, Math::Vector3D(178, 255, 102));
    RayTracer::Sphere sphere4(Math::Point3D(-0.5, -0.5, 0), 0.3, Math::Vector3D(255, 153, 153));
    RayTracer::AmbiantLight ambiantLight(0.2);
    RayTracer::DirectionalLight directionalLight(Math::Vector3D(-1, 1, 1.5));
    std::vector<std::shared_ptr<RayTracer::IObjects>> objects;
    std::vector<std::shared_ptr<RayTracer::ILights>> lights;

    objects.push_back(std::make_shared<RayTracer::Sphere>(sphere));
    objects.push_back(std::make_shared<RayTracer::Sphere>(sphere2));
    objects.push_back(std::make_shared<RayTracer::Sphere>(sphere3));
    objects.push_back(std::make_shared<RayTracer::Sphere>(sphere4));
    lights.push_back(std::make_shared<RayTracer::AmbiantLight>(ambiantLight));
    lights.push_back(std::make_shared<RayTracer::DirectionalLight>(directionalLight));
    cam.setPosition(Math::Point3D(0, 0, -4));
    cam.setResolution(WIDTH, HEIGHT);
    cam.setScreen(126.87);

    renderer.setCamera(cam);
    renderer.setMissColor(Math::Vector3D(105, 105, 105));
    renderer.setObjects(objects);
    renderer.setLights(lights);
    renderer.renderScene();
    return 0;
}
