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
#include "RayTracer/Light/AmbiantLight/AmbiantLight.hpp"
#include "RayTracer/Light/DirectionalLight/DirectionalLight.hpp"
#include "RayTracer/Light/PointLight/PointLight.hpp"
#include "RayTracer/Light/ILights.hpp"
#include <iostream>

#define WIDTH 1920
#define HEIGHT 1080

    // RayTracer::Sphere sphere2(Math::Point3D(-0.5, 0.5, 0), 0.3, Math::Vector3D(255, 255, 0));
    // RayTracer::Sphere sphere3(Math::Point3D(0.5, -0.5, 0), 0.3, Math::Vector3D(178, 255, 102));
    // RayTracer::Sphere sphere4(Math::Point3D(-0.5, -0.5, 0), 0.3, Math::Vector3D(255, 153, 153));

int main(void)
{
    RayTracer::Camera cam;
    RayTracer::Renderer renderer;
    RayTracer::AmbiantLight ambiantLight(0.2);
    RayTracer::Sphere sphere(Math::Point3D(0.5, 0.5, 0), 0.3, Math::Vector3D(153, 0, 153));
    RayTracer::LCylinder cylinder(Math::Point3D(0, 0, 1.5), 0.3, 0.5, Math::Vector3D(153, 0, 153));
    RayTracer::DirectionalLight directionalLight(Math::Vector3D(-1, 1, 1.5));
    RayTracer::Plane plane(Math::Point3D(0., 0.4, 0.), Math::Vector3D(0., -1., 0.), Math::Vector3D(18, 164, 139));
    RayTracer::PointLight pointLight(Math::Point3D(0, -10, 0), 2);
    std::vector<std::shared_ptr<RayTracer::IObjects>> objects;
    std::vector<std::shared_ptr<RayTracer::ILights>> lights;

    objects.push_back(std::make_shared<RayTracer::LCylinder>(cylinder));
    objects.push_back(std::make_shared<RayTracer::Sphere>(sphere));
    objects.push_back(std::make_shared<RayTracer::Plane>(plane));
    lights.push_back(std::make_shared<RayTracer::AmbiantLight>(ambiantLight));
    lights.push_back(std::make_shared<RayTracer::PointLight>(pointLight));
    cam.setResolution(WIDTH, HEIGHT);
    cam.setScreen(25, Rectangle3D(Math::Point3D(-0.5, -0.5, -4), Math::Vector3D(1., 0, 0), Math::Vector3D(0, 1., 0)));
    renderer.setCamera(cam);
    renderer.setMissColor(Math::Vector3D(0, 0, 0));
    renderer.setMissColor(Math::Vector3D(105, 105, 105));
    renderer.setObjects(objects);
    renderer.setLights(lights);
    renderer.renderScene();
    return 0;
}
