/*
** EPITECH PROJECT, 2023
** Viewer
** File description:
** to complete
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>

namespace RayTracer {
    class Viewer {
        public:
            Viewer();
            ~Viewer() = default;
            std::string init_menu(void);
            std::string getOutput(void);
            std::string getm_sceneName(void) const;
        protected:
            unsigned int count_files_in_dir(void) const;
            void create_all_scenes_buttons(void);
            void draw_all(void);
            std::string check_mouse_position(int x, int y, sf::Event t_event);
        private:
            sf::RenderWindow *m_window;
            sf::Texture m_backgroundTexture;
            sf::Sprite m_backgroundSprite;
            sf::Text *m_title;
            sf::Text *m_output_name;
            sf::Font m_font;
            sf::Font m_font2;
            sf::Text *m_text;
            sf::RectangleShape *m_rect;
            sf::Image m_render;
            sf::Texture m_renderTexture;
            sf::Sprite m_renderSprite;
            std::string m_sceneName;
    };
}
