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

namespace Engine {

class ScreenComponent {
  private:
    SDL_Renderer* window_renderer;
    SDL_Rect rect;
    Position position;
    Size size;

    void draw_rect();

  public:
    ScreenComponent(Window* window, const int x, const int y, const int width, const int heigth);
    ~ScreenComponent();

    Position get_position() {
      return this->position;
    }
    void update_pos(const int x, const int y);
    Size get_size() {
      return this->size;
    }
    void update_size(const int width, const int heigth);
    void update() {
      this->draw_rect();
    }
};

}
