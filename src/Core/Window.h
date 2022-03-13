#pragma once

#include <functional>
#include <SDL2/SDL.h>

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  int width;
  int height;
} Size;

typedef struct {
  int red;
  int green;
  int blue;
} Color;

namespace Core {

class Window {
  private:
    ~Window();

    SDL_Event current_event;
    Size size;
    Color color;
    bool is_active;
    int fps;

    int pool_event();
    void draw_background();
    void update() {
      this->draw_background();
    }

  public:
    SDL_Window* sdl_window;
    SDL_Renderer* sdl_renderer;

    Window(const char* window_name, const int width, const int height);

    int get_fps();
    void event_loop(const std::function<void(void)> callback);
    void set_backgroud_color(const int red, const int green, const int blue) {
      this->color = { red, green, blue };
    }
    Size get_size() {
      return this->size;
    }
    void set_size(const int width, const int heigth) {
      this->size = { width, heigth };
    }
    void quit() {
      Core::Window::~Window();
    }
};

}
