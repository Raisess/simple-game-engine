#pragma once

#include <SDL2/SDL.h>
#include "Window.h"

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  int width;
  int heigth;
} Size;

typedef struct {
  int red;
  int green;
  int blue;
} Color;

namespace Engine {

class ScreenComponent {
  private:
    SDL_Renderer* window_renderer;
    SDL_Rect rect;
    Position position;
    Size size;
    Color color;
    bool fill;

    void draw_rect();

  public:
    ScreenComponent(Window* window, const int x, const int y, const int width, const int heigth, bool fill);
    ~ScreenComponent();

    Position get_position() {
      return this->position;
    }
    void update_pos(const int x, const int y) {
      this->position = { x, y };
    }
    Size get_size() {
      return this->size;
    }
    void update_size(const int width, const int heigth) {
      this->size = { width, heigth };
    }
    Color get_color() {
      return this->color;
    }
    void update_color(const int red, const int green, const int blue) {
      this->color = { red, green, blue };
    }
    void update() {
      this->draw_rect();
    }
};

}
