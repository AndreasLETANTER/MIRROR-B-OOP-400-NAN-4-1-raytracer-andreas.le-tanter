/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** IParser
*/

#pragma once

#include <libconfig.h++>
#include <vector>
#include <memory>

#include "../RayTracer/Light/AmbientLight/AmbientLight.hpp"
#include "../RayTracer/Light/DirectionalLight/DirectionalLight.hpp"
#include "../RayTracer/Light/PointLight/PointLight.hpp"
#include "../RayTracer/Camera/Camera.hpp"

namespace Factory
{
    class IFactory {
        public:
            virtual ~IFactory() = default;
            virtual RayTracer::Camera createCamera(double t_width, double t_heigth, Rectangle3D t_screen, double t_fov) = 0;
            virtual std::shared_ptr<RayTracer::AmbientLight> createAmbientLight(double t_intensity) = 0;
            virtual std::shared_ptr<RayTracer::DirectionalLight> createDirectionalLight(Math::Vector3D t_direction) = 0;
            virtual std::shared_ptr<RayTracer::PointLight> createPointLight(Math::Point3D t_position, double t_intensity) = 0;
            virtual std::shared_ptr<RayTracer::IObjects> createSphere(Math::Point3D t_position, double t_radius, Math::Vector3D t_color) = 0;
            virtual std::shared_ptr<RayTracer::IObjects> createPlane(Math::Point3D t_position, Math::Vector3D t_normal, Math::Vector3D t_color) = 0;
            virtual std::shared_ptr<RayTracer::IObjects> createCone(double t_angle, double t_height, Math::Vector3D t_tip, Math::Vector3D t_axis, Math::Vector3D t_color) = 0;
        protected:
        private:
    };
}
