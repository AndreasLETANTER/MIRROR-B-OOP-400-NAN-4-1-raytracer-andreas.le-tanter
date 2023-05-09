/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Objects Abstract class
*/

#ifndef RAYTRACER_AOBJECTS_HPP
    #define RAYTRACER_AOBJECTS_HPP
    #include "../Ray/Ray.hpp"
    #include "IObjects.hpp"
namespace RayTracer
{
    class AObjects : public IObjects {
        public:
            virtual void translate(Math::Point3D m_origin);
            Math::Point3D m_position;
        protected:
        private:
    };
} // namespace RayTracer
#endif //RAYTRACER_AOBJECTS_HPP
