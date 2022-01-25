#pragma once

#include "Window.h"

namespace Engine {

class ScreenComponent {
  private:
    Window* window;
    Position position;
    float gravity_speed = 0.00F;
    Size size;
    Color color;
    bool fill;

    void draw_rect();

  public:
    ScreenComponent(Window* window, const int x, const int y, const int width, const int height, bool fill);

    Position get_position() {
      return this->position;
    }
    void set_position(const int x, const int y) {
      this->position = { x, y };
    }
    float get_gravity_speed() {
      return this->gravity_speed;
    }
    void set_gravity_speed(const float gravity_speed) {
      this->gravity_speed = gravity_speed;
    }
    Size get_size() {
      return this->size;
    }
    void set_size(const int width, const int heigth) {
      this->size = { width, heigth };
    }
    Color get_color() {
      return this->color;
    }
    void set_color(const int red, const int green, const int blue) {
      this->color = { red, green, blue };
    }
    void update() {
      this->draw_rect();
    }
};

}
