/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Renderer
*/

#pragma once
#include "../../Math/Point3D/Point3D.hpp"
#include "../../Math/Vector3D/Vector3D.hpp"
#include "../Camera/Camera.hpp"
#include "../Ray/Ray.hpp"
#include "../Objects/IObjects.hpp"

namespace RayTracer
{
    class Renderer {
        public:
            Renderer();
            Renderer(int t_width, int t_height, RayTracer::Camera t_cam);
            ~Renderer();
            void setHitColor(Math::Vector3D t_color);
            void setMissColor(Math::Vector3D t_color);
            void setWidth(int t_width);
            void setHeight(int t_height);
            void setObject(RayTracer::IObjects *t_object);
            void setCamera(RayTracer::Camera t_cam);
            void renderScene();

        protected:
        private:
            void print_pixel(Math::Vector3D t_color);
            void print_header();
            Math::Vector3D m_hit_color;
            Math::Vector3D m_miss_color;
            RayTracer::Camera m_cam;
            RayTracer::IObjects *m_object;
            int m_width;
            int m_height;
    };
} // namespace RayTracer
