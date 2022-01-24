#pragma once

#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "Window.h"

namespace Engine {

class TextComponent {
  private:
    SDL_Renderer* window_renderer;
    SDL_Surface* sdl_surface;
    SDL_Texture* sdl_texture;
    TTF_Font* font;
    Position position;
    Size size;
    SDL_Color color;
    std::string value = "";

    void draw_text();

  public:
    TextComponent(Window* window, const int x, const int y, const int width, const int heigth, const int font_size);
    ~TextComponent();

    Position get_position() {
      return this->position;
    }
    void set_position(const int x, const int y) {
      this->position = { x, y };
    }
    Size get_size() {
      return this->size;
    }
    void set_size(const int width, const int heigth) {
      this->size = { width, heigth };
    }
    SDL_Color get_color() {
      return this->color;
    }
    void set_color(const Uint8 red, const Uint8 green, const Uint8 blue) {
      this->color = { red, green, blue };
    }
    std::string get_value() {
      return this->value;
    }
    void set_value(std::string value) {
      this->value = value;
    }
    void update() {
      this->draw_text();
    }
    void destroy() {
      Engine::TextComponent::~TextComponent();
    }
};

}
