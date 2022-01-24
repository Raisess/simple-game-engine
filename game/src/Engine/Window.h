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

    SDL_Event current_event;
    Size size;
    Color color;
    bool is_active = false;
    int fps = 60;

    int pool_event();
    void draw_background();

  public:
    SDL_Window* sdl_window;
    SDL_Renderer* sdl_renderer;

    Window(const char* window_name, const int width, const int height);

    int get_fps();
    void event_loop(const std::function<void(void)> callback);
    void set_backgroud_color(const int red, const int green, const int blue) {
      this->color = { red, green, blue };
    }
    void update() {
      this->draw_background();
    }
    void quit() {
      Engine::Window::~Window();
    }
};

}
