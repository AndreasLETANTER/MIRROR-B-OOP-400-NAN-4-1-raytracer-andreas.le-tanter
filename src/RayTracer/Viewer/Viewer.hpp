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
            void init_menu(void);
            std::string get_scene_name(void) const;
        protected:
            unsigned int count_files_in_dir(void) const;
            void create_all_scenes_buttons(void);
            void draw_all(void);
            void check_mouse_position(int x, int y, bool click);
            sf::Image get_image_from_file() const;
        private:
            sf::RenderWindow *_window;
            sf::Texture _background_texture;
            sf::Sprite _background_sprite;
            sf::Text _title;
            sf::Font _font;
            sf::Text *_text;
            sf::RectangleShape *_rect;
            sf::Image _render;
            sf::Texture _render_texture;
            sf::Sprite _render_sprite;
            std::string _scene_name;
    };
}
