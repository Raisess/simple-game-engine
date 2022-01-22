#pragma once

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
    SDL_Renderer* sdl_renderer;
    SDL_Event current_event;
    WindowSize window_size;
    bool is_active = false;

    int pool_event();

  public:
    Window(const char* window_name, const int width, const int height);

    void event_loop(void (*callback)(Engine::Window* window));
    void quit() {
      Engine::Window::~Window();
    }
};

}
