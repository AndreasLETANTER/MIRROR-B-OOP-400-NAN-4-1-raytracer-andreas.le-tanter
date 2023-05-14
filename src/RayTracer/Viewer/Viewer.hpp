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
            ~Viewer();
            std::string init_menu(void);
            std::string getOutput(void);
            std::string get_scene_name(void) const;
        protected:
            unsigned int count_files_in_dir(void) const;
            void create_all_scenes_buttons(void);
            void draw_all(void);
            std::string check_mouse_position(int x, int y, sf::Event t_event);
        private:
            sf::RenderWindow *_window;
            sf::Texture _background_texture;
            sf::Sprite _background_sprite;
            sf::Text *_title;
            sf::Text *_output_name;
            sf::Font _font;
            sf::Font _font2;
            sf::Text *_text;
            sf::RectangleShape *_rect;
            sf::Image _render;
            sf::Texture _render_texture;
            sf::Sprite _render_sprite;
            std::string _scene_name;
    };
}
