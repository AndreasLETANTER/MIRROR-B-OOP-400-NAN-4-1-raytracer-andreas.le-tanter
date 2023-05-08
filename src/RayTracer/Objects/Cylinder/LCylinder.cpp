/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Limited Cylinder
*/

#include "Cylinder.hpp"

/**
 * @brief Construct a new Cylinder object
 * @details set the center, height and the radius of the cylinder to 0
*/
RayTracer::LCylinder::LCylinder()
{
    c_center = Math::Point3D(0, 0, 0);
    c_radius = 0;
    c_height = 0;
}

/**
 * @brief Construct a new Cylinder object
 * @details set the center, the radius and the height of the cylinder to the given parameters
 * @param c_center
 * @param c_radius
 * @param c_height
 */
RayTracer::LCylinder::LCylinder(Math::Point3D center, double radius
, double height, Math::Vector3D color)
{
    c_center = center;
    c_radius = radius;
    c_height = height;
    m_color = color;
}

/**
 * @brief Destroy the Cylinder object
*/
RayTracer::LCylinder::~LCylinder()
{
}

/**
 * @brief check if the ray hits the cylinder
 * @details check if the ray hits the cylinder using a quadratic equation
 * @param t_ray
 * @return true
 * @return false
*/
bool RayTracer::LCylinder::hits(Ray& t_ray)
{
    Math::Vector3D OC = t_ray.m_origin - c_center;
    float a = pow(t_ray.m_direction.m_x_component, 2)
    + pow(t_ray.m_direction.m_z_component, 2);
    float b = 2 * (t_ray.m_direction.m_x_component * OC.m_x_component
    + t_ray.m_direction.m_z_component * OC.m_z_component);
    float c = pow(OC.m_x_component, 2) + pow(OC.m_z_component, 2)
    - pow(c_radius, 2);
    float discriminant = pow(b, 2) - 4 * a * c;

    if (discriminant <= 0) {
        return false;
    }
    double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
    double t;
    if (t1 > 0) {
        t = t1;
    } else if (t2 > 0) {
        t = t2;
    } else {
        return false;
    }
    m_hit_point = t_ray.m_origin + t_ray.m_direction * t;
    if (m_hit_point.m_y_component < c_center.m_y_component
    || m_hit_point.m_y_component > c_center.m_y_component + c_height) {
        return false;
    }
    return true;
}

// bool RayTracer::LCylinder::hits(Ray& t_ray, const Math::Matrix4& projectionMatrix)
// {
//     // Transform t_ray.m_origin and c_center to camera space using the projectionMatrix
//     Math::Vector4 originCameraSpace = projectionMatrix * Math::Vector4(t_ray.m_origin, 1.0);
//     Math::Vector4 centerCameraSpace = projectionMatrix * Math::Vector4(c_center, 1.0);

//     // Convert to 3D vectors in camera space
//     Math::Vector3D OC(originCameraSpace.x, originCameraSpace.y, originCameraSpace.z);
//     Math::Vector3D CC(centerCameraSpace.x, centerCameraSpace.y, centerCameraSpace.z);

//     // Perform ray-cylinder intersection calculation in camera space
//     float a = pow(t_ray.m_direction.m_x_component, 2) + pow(t_ray.m_direction.m_z_component, 2);
//     float b = 2 * (t_ray.m_direction.m_x_component * OC.m_x_component + t_ray.m_direction.m_z_component * OC.m_z_component);
//     float c = pow(OC.m_x_component, 2) + pow(OC.m_z_component, 2) - pow(c_radius, 2);
//     float discriminant = pow(b, 2) - 4 * a * c;

//     if (discriminant <= 0) {
//         return false;
//     }

//     double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
//     double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
//     double t;

//     if (t1 > 0) {
//         t = t1;
//     } else if (t2 > 0) {
//         t = t2;
//     } else {
//         return false;
//     }

//     // Calculate the intersection point in camera space
//     Math::Vector3D hitPointCameraSpace = OC + t * t_ray.m_direction;

//     // Check if the intersection point is within the finite height of the cylinder
//     if (hitPointCameraSpace.m_y_component < CC.m_y_component || hitPointCameraSpace.m_y_component > CC.m_y_component + c_height) {
//         return false;
//     }

//     // Transform the intersection point back to world space
//     Math::Vector4 hitPointWorldSpace = projectionMatrix.inverse() * Math::Vector4(hitPointCameraSpace, 1.0);
//     m_hit_point = Math::Vector3D(hitPointWorldSpace.x, hitPointWorldSpace.y, hitPointWorldSpace.z);

//     return true;
// }


/**
 * @brief get the surface normal of the cylinder
 * @details get the surface normal of the cylinder at the given point
 * @param t_point
 * @return Math::Vector3D
*/
Math::Vector3D RayTracer::LCylinder::getSurfaceNormal(void)
{
    Math::Vector3D surface_normal = m_hit_point - c_center;

    surface_normal = surface_normal / surface_normal.length();
    return (surface_normal);
}

/**
 * @brief get the color of the cylinder
 * @return Math::Vector3D
*/
Math::Vector3D RayTracer::LCylinder::getColor(void)
{
    return (m_color);
}

/**
 * @brief get the distance between the ray origin and the hit point
 * @return double 
*/
double RayTracer::LCylinder::getHitDistance(void)
{
    return (m_hit_distance);
}

/**
 * @brief get the hit point
 * @return Math::Point3D 
*/
Math::Point3D RayTracer::LCylinder::getIntersectionPoint(void)
{
    return (m_hit_point);
}
