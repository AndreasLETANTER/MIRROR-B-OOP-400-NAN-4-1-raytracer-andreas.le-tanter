/*
** EPITECH PROJECT, 2023
** Viewer
** File description:
** to complete
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace RayTracer {
    class Viewer {
        public:
            Viewer();
            ~Viewer();
        protected:
            unsigned int count_files_in_dir(void) const;
            void create_all_scenes_buttons(void);
        private:
            sf::RenderWindow *_window;
            sf::Texture _background_texture;
            sf::Sprite _background_sprite;
            sf::Text _title;
            sf::Font _font;
            sf::Text *_text;
            sf::RectangleShape *_rect;
    };
}
