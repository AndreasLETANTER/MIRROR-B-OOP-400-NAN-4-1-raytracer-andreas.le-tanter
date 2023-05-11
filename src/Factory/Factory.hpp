/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Factory
*/

#pragma once

#include <string>
#include <libconfig.h++>
#include <vector>
#include <memory>

#include "IFactory.hpp"
#include "../RayTracer/Objects/IObjects.hpp"
#include "../RayTracer/Light/AmbiantLight/AmbiantLight.hpp"
#include "../RayTracer/Camera/Camera.hpp"

namespace Factory
{
    class Factory : IFactory {
        public:
            Factory() = default;
            ~Factory() = default;

            // Getters
            std::vector<RayTracer::IObjects *> getObjects();
            RayTracer::Camera getCamera();

            // Creator
            RayTracer::Camera createCamera(double t_width, double t_heigth, Rectangle3D t_screen, double t_fov);
            std::shared_ptr<RayTracer::AmbiantLight> createAmbiantLight(double t_intensity);
            std::shared_ptr<RayTracer::DirectionalLight> createDirectionalLight(Math::Vector3D t_direction);
            std::shared_ptr<RayTracer::PointLight> createPointLight(Math::Point3D t_position, double t_intensity);
            std::shared_ptr<RayTracer::IObjects> createSphere(Math::Point3D t_position, double t_radius, Math::Vector3D t_color);
            std::shared_ptr<RayTracer::IObjects> createPlane(Math::Point3D t_position, Math::Vector3D t_normal, Math::Vector3D t_color);
            std::shared_ptr<RayTracer::IObjects> createCone(double t_angle, double t_height, Math::Vector3D t_tip, Math::Vector3D t_axis, Math::Vector3D t_color);
        protected:
        private:
            std::vector<RayTracer::IObjects *> m_objects;
            RayTracer::Camera m_cam;
    };
}
