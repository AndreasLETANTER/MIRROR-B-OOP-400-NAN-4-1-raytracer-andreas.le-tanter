/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Camera
*/

#pragma once
#include "../../Math/Point3D/Point3D.hpp"
#include "../../Math/Vector3D/Vector3D.hpp"
#include "../../Math/Rectangle3D/Rectangle3D.hpp"
#include "../Ray/Ray.hpp"
#include <tuple>

/**
 * @brief Camera class, used to create a camera in 3D space
 * @details the camera is defined by its origin and its screen
*/
namespace RayTracer
{
    class Camera {
        public:
            Camera(void) = default;
            ~Camera(void) = default;
            void setPosition(Math::Point3D t_origin);
            void setScreen(double t_fov);
            void setResolution(int t_width, int t_height);
            void rotateScreen(Math::Vector3D t_rotation);
            std::tuple<int, int> getResolution(void) { return (std::make_tuple(m_width, m_height)); };
            RayTracer::Ray rayAt(double t_u, double t_v);

        protected:
        private:
            Math::Point3D m_position;
            Rectangle3D m_screen;
            int m_width;
            int m_height;
    };
}
