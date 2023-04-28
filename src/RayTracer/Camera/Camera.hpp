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

/**
 * @brief Camera class, used to create a camera in 3D space
 * @details the camera is defined by its origin and its screen
*/
namespace RayTracer
{
    class Camera {
        public:
            Camera();
            ~Camera();
            Math::Point3D m_origin;
            Rectangle3D m_screen;
            RayTracer::Ray rayAt(double u, double v);

        protected:
        private:
    };
}
