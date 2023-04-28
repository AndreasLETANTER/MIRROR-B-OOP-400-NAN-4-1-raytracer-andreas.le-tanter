/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser::Parser()
{
}

Parser::Parser::~Parser()
{
}


void Parser::Parser::parse_config_file()
{

}

std::vector<RayTracer::IObjects *> Parser::Parser::getObjects()
{
    return m_objects;
}

RayTracer::Camera Parser::Parser::getCamera()
{
    return m_cam;
}
