#pragma once

#include <functional>
#include <SDL2/SDL.h>

typedef struct {
  int width;
  int height;
} WindowSize;

namespace Engine {

class Window {
  private:
    ~Window();

    SDL_Window* sdl_window;
    SDL_Event current_event;
    WindowSize window_size;
    bool is_active = false;

    int pool_event();
    void update() {
      this->set_backgroud_color(0, 0, 0);
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
