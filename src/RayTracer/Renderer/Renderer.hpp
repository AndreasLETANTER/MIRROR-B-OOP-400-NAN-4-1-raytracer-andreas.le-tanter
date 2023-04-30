/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Renderer
*/

#pragma once
#include "../../Math/Point3D/Point3D.hpp"
#include "../../Math/Vector3D/Vector3D.hpp"
#include "../Light/ILights.hpp"
#include "../Camera/Camera.hpp"
#include "../Ray/Ray.hpp"
#include "../Objects/IObjects.hpp"
#include <vector>
#include <memory>

/**
 * @brief Renderer class, used to render the scene
 * @details the renderer is defined by the miss color, the camera, the objects, the width and the height
*/
namespace RayTracer
{
    class Renderer {
        public:
            Renderer(void) = default;
            Renderer(int t_width, int t_height, RayTracer::Camera t_cam);
            ~Renderer(void) = default;
            void setMissColor(Math::Vector3D t_color);
            void setWidth(int t_width);
            void setHeight(int t_height);
            void setObjects(std::vector<std::shared_ptr<RayTracer::IObjects>> t_objects);
            void setLights(std::vector<std::shared_ptr<RayTracer::ILights>> t_lights);
            void setCamera(RayTracer::Camera t_cam);
            void renderScene(void);

        protected:
        private:
            void check_hit(RayTracer::Ray r);
            void print_pixel(Math::Vector3D t_color);
            void print_header(void);
            Math::Vector3D m_miss_color;
            RayTracer::Camera m_cam;
            std::vector<std::shared_ptr<RayTracer::IObjects>> m_objects;
            std::vector<std::shared_ptr<RayTracer::ILights>> m_lights;
            int m_width;
            int m_height;
    };
} // namespace RayTracer
