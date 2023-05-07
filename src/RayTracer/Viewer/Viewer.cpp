/*
** EPITECH PROJECT, 2023
** Viewer
** File description:
** to complete
*/

#include "Viewer.hpp"
#include <iostream>
#include <exception>
#include <dirent.h>

RayTracer::Viewer::Viewer()
{
    _window = new sf::RenderWindow(sf::VideoMode(1024, 768), "RayTracer Viewer");
    _window->setPosition(sf::Vector2i(448, 156));
    try {
        if (!_background_texture.loadFromFile("src/RayTracer/Viewer/Assets/background.jpg"))
            throw std::exception();
        _background_sprite.setTexture(_background_texture);
        _background_sprite.setScale(2, 2);
        _background_sprite.setPosition(0, 0);
        if (!_font.loadFromFile("src/RayTracer/Viewer/Assets/arial.ttf"))
            throw std::exception();
        _title.setFont(_font);
        _title.setString("RayTracer Viewer");
        _title.setCharacterSize(75);
        _title.setFillColor(sf::Color::White);
        _title.setPosition(225, 50);
        create_all_scenes_buttons();

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(84);
    }
    while (_window->isOpen())
    {
        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                _window->close();
        }
        _window->draw(_background_sprite);
        _window->draw(_title);
        for (unsigned int i = 0; i < count_files_in_dir(); i++) {
            _window->draw(_rect[i]);
            _window->draw(_text[i]);
        }
        _window->display();
    }
    
}

RayTracer::Viewer::~Viewer()
{
}

unsigned int RayTracer::Viewer::count_files_in_dir(void) const
{
    DIR *directory;
    struct dirent *dir;
    unsigned int count = 0;

    directory = opendir("scenes/");
    if (directory) {
        while ((dir = readdir(directory)) != NULL) {
            if (dir->d_name[0] == '.' || dir->d_name[1] == '.')
                continue;
            count++;
        }
        closedir(directory);
    }
    return (count);
}

void RayTracer::Viewer::create_all_scenes_buttons(void)
{
    DIR *directory;
    struct dirent *dir;
    unsigned int count = 0;

    _text = new sf::Text[count_files_in_dir()];
    _rect = new sf::RectangleShape[count_files_in_dir()];
    directory = opendir("scenes/");
    if (directory) {
        while ((dir = readdir(directory)) != NULL) {
            if (dir->d_name[0] == '.' || dir->d_name[1] == '.')
                continue;
            _text[count].setFont(_font);
            _text[count].setString(dir->d_name);
            _text[count].setCharacterSize(25);
            _text[count].setFillColor(sf::Color::White);
            _text[count].setPosition(550 - (std::string(dir->d_name).length() * 7.5), 208 + (count * 75));
            _rect[count].setSize(sf::Vector2f(500, 50));
            _rect[count].setFillColor(sf::Color::Transparent);
            _rect[count].setOutlineThickness(2);
            _rect[count].setOutlineColor(sf::Color::White);
            _rect[count].setPosition(275, 200 + (count * 75));
            count++;
        }
        closedir(directory);
    }
}
