/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bsraytracer-andreas.le-tanter
** File description:
** Cylindre
*/

#include "Cylinder.hpp"

/**
 * @brief Construct a new Cylinder object
 * @details set the center, height and the radius of the cylinder to 0
*/
RayTracer::FCylinder::FCylinder()
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
RayTracer::FCylinder::FCylinder(Math::Point3D center, double radius
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
RayTracer::FCylinder::~FCylinder()
{
}

/**
 * @brief check if the ray hits the cylinder
 * @details check if the ray hits the cylinder using a quadratic equation
 * @param t_ray
 * @return true
 * @return false
*/
// bool RayTracer::Cylinder::hits(Ray& t_ray)
// {
//     float a = pow(t_ray.m_direction.m_x_component + t_ray.m_direction.m_y_component, 2);
//     float b = 2 * (t_ray.m_origin.m_x_component * t_ray.m_direction.m_x_component
//     + t_ray.m_origin.m_y_component * t_ray.m_direction.m_y_component);
//     float c = pow(t_ray.m_direction.m_x_component, 2) + pow(t_ray.m_direction.m_y_component, 2) - pow(c_radius, 2);
//     float discriminant = pow(b, 2) - 4 * a * c;
//     const double t = (-b - sqrt(discriminant)) / (2.0 * a);
//     if (discriminant <= 0) {
//         return (false);
//     }
//     m_hit_point = t_ray.m_origin + t_ray.m_direction * t;
//     return (true);
// }

bool RayTracer::FCylinder::hits(Ray& t_ray)
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
        return (false);
    }
    double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
    double t;
    if (t1 > 0) {
        t = t1;
    } else if (t2 > 0) {
        t = t2;
    } else {
        return (false);
    }
    m_hit_point = t_ray.m_origin + t_ray.m_direction * t;
    return (true);
}

// bool RayTracer::Cylinder::hits(Ray& t_ray)
// {
//     Math::Vector3D OC = t_ray.m_origin - c_center;
//     float a = pow(t_ray.m_direction.m_x_component, 2)
//     + pow(t_ray.m_direction.m_z_component, 2);
//     float b = 2 * (t_ray.m_direction.m_x_component * OC.m_x_component
//     + t_ray.m_direction.m_z_component * OC.m_z_component);
//     float c = pow(OC.m_x_component, 2) + pow(OC.m_z_component, 2)
//     - pow(c_radius, 2);
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
//     m_hit_point = t_ray.m_origin + t_ray.m_direction * t;
//     if (m_hit_point.m_y_component < c_center.m_y_component
//     || m_hit_point.m_y_component > c_center.m_y_component + c_height) {
//         return false;
//     }
//     return true;
// }


// bool RayTracer::Cylinder::hits(Ray& t_ray)
// {
//     double **tab = (double **)malloc(sizeof(double) * 4);
//     double angle = 70.0;
//     double ratio = 1.0;
//     double near = -4.0;
//     double far = 200000000;
//     double o[] = {t_ray.m_origin.m_x_component, t_ray.m_origin.m_y_component
//     , t_ray.m_origin.m_z_component,};
//     double d[] = {t_ray.m_direction.m_x_component, t_ray.m_direction.m_y_component
//     , t_ray.m_direction.m_z_component};

//     for (int i = 0; i < 4; i++) {
//         tab[i] = (double *)malloc(sizeof(double) * 4);
//         for (int j = 0; j < 4; j++) {
//             tab[i][j] = 0.0;
//         }
//     }
//     tab[0][0] = (1 / (ratio * tan(angle / 2)));
//     tab[1][1] = (1 / (tan(angle / 2)));
//     tab[2][2] = ((near + far) / (near - far));
//     tab[2][3] = (2 * near + far) / (near - far);
//     tab[3][2] = -1;
//     float a = tab[0][0] * pow(d[0], 2) + 2 * tab[0][1] * d[0] * d[1]
//     + 2 * tab[0][2] * d[0] * d[2] + tab[1][1] * pow(d[1], 2)
//     + 2 * tab[1][2] * d[1] * d[2] + tab[2][2] * pow(d[2], 2);
//     float b = 2 * (tab[0][0] * o[0] * d[0]
//     + tab[0][1] * (o[0] * d[1] + d[0] * o[1])
//     + tab[0][2] * (o[0] * d[2] + d[0] * o[2])
//     + tab[0][3] * d[0] + tab[1][1] * o[1] * o[1] * d[1]
//     + tab[1][2] * (o[1] * d[2] + d[1] * o[2])
//     + tab[1][3] * (d[1]) + tab[2][2] * o[2] * d[2] + tab[2][3] * d[2]);
//     float c = tab[0][0] * pow(o[0], 2) + 2 * tab[0][1] * o[0] * o[1]
//     + 2 * tab[0][2] * (o[0] * o[2] + 2 * tab[0][3] * o[0]
//     + tab[1][1] * o[1] + 2 * tab[1][2] * o[1] * o[2]
//     + 2 * tab[1][3] * o[1] + tab[2][2] * pow(o[2], 2) + 2 * tab[2][3] * o[2]
//     + tab[3][3]);
//     float discriminant = pow(b, 2) - 4 * a * c;
//     const double t = (-b - sqrt(discriminant)) / (2.0 * a);
//     if (discriminant <= 0) {
//         return (false);
//     }
//     m_hit_point = t_ray.m_origin + t_ray.m_direction * abs(t);
//     return (true);
// }

/**
 * @brief get the surface normal of the cylinder
 * @details get the surface normal of the cylinder at the given point
 * @param t_point
 * @return Math::Vector3D
*/
Math::Vector3D RayTracer::FCylinder::getSurfaceNormal(void)
{
    Math::Vector3D surface_normal = m_hit_point - c_center;

    surface_normal = surface_normal / surface_normal.length();
    return (surface_normal);
}

/**
 * @brief get the color of the cylinder
 * @return Math::Vector3D
*/
Math::Vector3D RayTracer::FCylinder::getColor(void)
{
    return (m_color);
}
