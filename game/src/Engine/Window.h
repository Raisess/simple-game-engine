#pragma once

#include <functional>
#include <SDL2/SDL.h>

typedef struct {
  int width;
  int height;
} Size;

typedef struct {
  int red;
  int green;
  int blue;
} Color;

namespace Engine {

class Window {
  private:
    ~Window();

    SDL_Window* sdl_window;
    SDL_Event current_event;
    Size window_size;
    Color window_bg_color;
    bool is_active = false;

    int pool_event();
    void update() {
      this->set_backgroud_color(this->window_bg_color.red, this->window_bg_color.green, this->window_bg_color.blue);
    }

  public:
    SDL_Renderer* sdl_renderer;

    Window(const char* window_name, const int width, const int height);

    void set_backgroud_color(const int red, const int green, const int blue);
    void event_loop(const std::function<void(void)> callback);
    void quit() {
      Engine::Window::~Window();
    }
};

}
