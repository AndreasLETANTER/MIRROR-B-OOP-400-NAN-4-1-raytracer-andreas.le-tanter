/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** ILight
*/

#pragma once
#include "../../Math/Point3D/Point3D.hpp"
#include "../../Math/Rectangle3D/Rectangle3D.hpp"

namespace RayTracer
{
    class ILight {
        public:
            virtual ~ILight() = default;
            Math::Point3D m_origin;
            Rectangle3D m_screen;

        protected:
        private:
    };
}
