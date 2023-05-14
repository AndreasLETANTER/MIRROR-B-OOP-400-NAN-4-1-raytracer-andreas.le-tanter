/*
** EPITECH PROJECT, 2023
** Viewer
** File description:
** to complete
*/

#include "Viewer.hpp"
#include "../../Parser/Parser.hpp"
#include <iostream>
#include <exception>
#include <dirent.h>
#include <sys/types.h>
#include <fstream>

RayTracer::Viewer::Viewer()
{
    _scene_name = "";
    _window = nullptr;
    _title = nullptr;
    _output_name = nullptr;
    _background_texture = sf::Texture();
    _background_sprite = sf::Sprite();
    _font = sf::Font();
    _font2 = sf::Font();
}

RayTracer::Viewer::~Viewer()
{
}

void RayTracer::Viewer::draw_all(void)
{
    _window->draw(_background_sprite);
    _window->draw(*_title);
    for (unsigned int i = 0; i < count_files_in_dir(); i++) {
        _window->draw(_rect[i]);
        _window->draw(_text[i]);
    }
    _window->draw(_render_sprite);
    _window->display();
}

std::string RayTracer::Viewer::check_mouse_position(int x, int y, sf::Event t_event)
{
    for (unsigned int i = 0; i < count_files_in_dir(); i++) {
        if (x >= _rect[i].getPosition().x && x <= _rect[i].getPosition().x + _rect[i].getSize().x &&
            y >= _rect[i].getPosition().y && y <= _rect[i].getPosition().y + _rect[i].getSize().y) {
            _text[i].setFillColor(sf::Color::Red);
            if (t_event.type == sf::Event::MouseButtonPressed && t_event.mouseButton.button == sf::Mouse::Left)
                return ("scenes/" + _text[i].getString());
        } else
            _text[i].setFillColor(sf::Color::White);
    }
    return ("");
}

std::string RayTracer::Viewer::init_menu(void)
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
        _title = new sf::Text();
        _title->setFont(_font);
        _title->setString("RayTracer Viewer");
        _title->setCharacterSize(75);
        _title->setFillColor(sf::Color::White);
        _title->setPosition(225, 50);
        create_all_scenes_buttons();

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(84);
    }
    _scene_name = "";
    sf::Event event;
    while (_window->isOpen()) {
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                _window->close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || event.type == sf::Event::MouseMoved) {
                std::string return_name = check_mouse_position(sf::Mouse::getPosition(*_window).x, sf::Mouse::getPosition(*_window).y, event);
                if (return_name != "") {
                    return (return_name);
                }
            }
            if (event.type == sf::Event::Resized) {
                _window->setPosition(sf::Vector2i(448, 156));
                _window->setSize(sf::Vector2u(1024, 768));
            }
        }
        draw_all();
    }
    _window->close();
    return ("");
}

std::string RayTracer::Viewer::getOutput(void)
{
    std::string output = "scenes/";
    _window->clear();
    _title->setString("Enter the name of the output file");
    _title->setPosition(140, 75);
    _title->setCharacterSize(50);
    sf::Font test = sf::Font();
    try {
        if (!test.loadFromFile("src/RayTracer/Viewer/Assets/arial.ttf"))
            throw std::exception();
        _output_name = new sf::Text();
        _output_name->setFont(test);
        _output_name->setString(output);
        _output_name->setCharacterSize(50);
        _output_name->setFillColor(sf::Color::White);
        _output_name->setPosition(265, 400);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(84);
    }

    while (_window->isOpen()) {
        sf::Event event;
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                _window->close();
            if (event.type == sf::Event::KeyPressed && event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) {
                output += event.key.code + 97;
                _output_name->setString(output + ".ppm");
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter) {
                output += ".ppm";
                _title->setString("Your image is rendering...");
                _title->setPosition(200, 350);
                _window->clear();
                _window->draw(_background_sprite);
                _window->draw(*_title);
                _window->display();
                return (output);
            }
            if (event.type == sf::Event::Resized) {
                _window->setPosition(sf::Vector2i(448, 156));
                _window->setSize(sf::Vector2u(1024, 768));
            }
        }
        _window->draw(_background_sprite);
        _window->draw(*_title);
        _window->draw(*_output_name);
        _window->display();
    }
    return (output);
}

std::string RayTracer::Viewer::get_scene_name(void) const
{
    return (_scene_name);
}

unsigned int RayTracer::Viewer::count_files_in_dir(void) const
{
    DIR *directory;
    struct dirent *dir;
    unsigned int count = 0;

    directory = opendir("scenes/");
    if (directory) {
        while ((dir = readdir(directory)) != NULL) {
            if (dir->d_name[0] == '.' || dir->d_name[1] == '.') {
                std::string str(dir->d_name);
                if (str.find(".cfg") == std::string::npos)
                    continue;
            }
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
            std::string str(dir->d_name);
            if (str.find(".cfg") == std::string::npos)
                continue;
            _text[count].setFont(_font);
            _text[count].setString(dir->d_name);
            _text[count].setCharacterSize(25);
            _text[count].setFillColor(sf::Color::White);
            _text[count].setPosition(540 - (std::string(dir->d_name).length() * 7), 208 + (count * 75));
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
