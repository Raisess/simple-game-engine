#pragma once

typedef struct {
  int width;
  int height;
} WindowSize;

namespace Engine {

class Window {
  private:
    ~Window();

    int sdl_window;
    bool is_active = false;
    int current_event;
    WindowSize window_size;

    int pool_event();

  public:
    Window(int width, int height);

    void event_loop(void (*callback)(Engine::Window* window));
    void quit() {
      Engine::Window::~Window();
    }
};

}
