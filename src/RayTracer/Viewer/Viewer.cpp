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
    m_sceneName = "";
    m_window = nullptr;
    m_title = nullptr;
    m_output_name = nullptr;
    m_backgroundTexture = sf::Texture();
    m_backgroundSprite = sf::Sprite();
    m_font = sf::Font();
    m_font2 = sf::Font();
}

void RayTracer::Viewer::draw_all(void)
{
    m_window->draw(m_backgroundSprite);
    m_window->draw(*m_title);
    for (unsigned int i = 0; i < count_files_in_dir(); i++) {
        m_window->draw(m_rect[i]);
        m_window->draw(m_text[i]);
    }
    m_window->draw(m_renderSprite);
    m_window->display();
}

std::string RayTracer::Viewer::check_mouse_position(int x, int y, sf::Event t_event)
{
    for (unsigned int i = 0; i < count_files_in_dir(); i++) {
        if (x >= m_rect[i].getPosition().x && x <= m_rect[i].getPosition().x + m_rect[i].getSize().x &&
            y >= m_rect[i].getPosition().y && y <= m_rect[i].getPosition().y + m_rect[i].getSize().y) {
            m_text[i].setFillColor(sf::Color::Red);
            if (t_event.type == sf::Event::MouseButtonPressed && t_event.mouseButton.button == sf::Mouse::Left)
                return ("scenes/" + m_text[i].getString());
        } else
            m_text[i].setFillColor(sf::Color::White);
    }
    return ("");
}

std::string RayTracer::Viewer::init_menu(void)
{
    m_window = new sf::RenderWindow(sf::VideoMode(1024, 768), "RayTracer Viewer");
    m_window->setPosition(sf::Vector2i(448, 156));
    try {
        if (!m_backgroundTexture.loadFromFile("src/RayTracer/Viewer/Assets/background.jpg"))
            throw std::exception();
        m_backgroundSprite.setTexture(m_backgroundTexture);
        m_backgroundSprite.setScale(2, 2);
        m_backgroundSprite.setPosition(0, 0);
        if (!m_font.loadFromFile("src/RayTracer/Viewer/Assets/arial.ttf"))
            throw std::exception();
        m_title = new sf::Text();
        m_title->setFont(m_font);
        m_title->setString("RayTracer Viewer");
        m_title->setCharacterSize(75);
        m_title->setFillColor(sf::Color::White);
        m_title->setPosition(225, 50);
        create_all_scenes_buttons();

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(84);
    }
    m_sceneName = "";
    sf::Event event;
    while (m_window->isOpen()) {
        while (m_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                m_window->close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || event.type == sf::Event::MouseMoved) {
                std::string return_name = check_mouse_position(sf::Mouse::getPosition(*m_window).x, sf::Mouse::getPosition(*m_window).y, event);
                if (return_name != "") {
                    return (return_name);
                }
            }
            if (event.type == sf::Event::Resized) {
                m_window->setPosition(sf::Vector2i(448, 156));
                m_window->setSize(sf::Vector2u(1024, 768));
            }
        }
        draw_all();
    }
    m_window->close();
    return ("");
}

std::string RayTracer::Viewer::getOutput(void)
{
    std::string output = "scenes/";
    m_window->clear();
    m_title->setString("Enter the name of the output file");
    m_title->setPosition(140, 75);
    m_title->setCharacterSize(50);
    sf::Font test = sf::Font();
    try {
        if (!test.loadFromFile("src/RayTracer/Viewer/Assets/arial.ttf"))
            throw std::exception();
        m_output_name = new sf::Text();
        m_output_name->setFont(test);
        m_output_name->setString(output);
        m_output_name->setCharacterSize(50);
        m_output_name->setFillColor(sf::Color::White);
        m_output_name->setPosition(265, 400);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(84);
    }

    while (m_window->isOpen()) {
        sf::Event event;
        while (m_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                m_window->close();
            if (event.type == sf::Event::KeyPressed && event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) {
                output += event.key.code + 97;
                m_output_name->setString(output + ".ppm");
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter) {
                output += ".ppm";
                m_title->setString("Your image is rendering...");
                m_title->setPosition(200, 350);
                m_window->clear();
                m_window->draw(m_backgroundSprite);
                m_window->draw(*m_title);
                m_window->display();
                return (output);
            }
            if (event.type == sf::Event::Resized) {
                m_window->setPosition(sf::Vector2i(448, 156));
                m_window->setSize(sf::Vector2u(1024, 768));
            }
        }
        m_window->draw(m_backgroundSprite);
        m_window->draw(*m_title);
        m_window->draw(*m_output_name);
        m_window->display();
    }
    return (output);
}

std::string RayTracer::Viewer::getm_sceneName(void) const
{
    return (m_sceneName);
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

    m_text = new sf::Text[count_files_in_dir()];
    m_rect = new sf::RectangleShape[count_files_in_dir()];
    directory = opendir("scenes/");
    if (directory) {
        while ((dir = readdir(directory)) != NULL) {
            if (dir->d_name[0] == '.' || dir->d_name[1] == '.')
                continue;
            std::string str(dir->d_name);
            if (str.find(".cfg") == std::string::npos)
                continue;
            m_text[count].setFont(m_font);
            m_text[count].setString(dir->d_name);
            m_text[count].setCharacterSize(25);
            m_text[count].setFillColor(sf::Color::White);
            m_text[count].setPosition(540 - (std::string(dir->d_name).length() * 7), 208 + (count * 75));
            m_rect[count].setSize(sf::Vector2f(500, 50));
            m_rect[count].setFillColor(sf::Color::Transparent);
            m_rect[count].setOutlineThickness(2);
            m_rect[count].setOutlineColor(sf::Color::White);
            m_rect[count].setPosition(275, 200 + (count * 75));
            count++;
        }
        closedir(directory);
    }
}
