#include "Window.h"

Engine::Window::Window(int width, int height) {
  // creates SDL Window
  this->is_active = true;
  this->window_size.width = width;
  this->window_size.height = height;
}

Engine::Window::~Window() {
  // destroy SDL Window
  this->is_active = false;
}

void Engine::Window::event_loop(void (*callback)(Engine::Window* window)) {
  while (this->is_active) {
    callback(this);
  }
}
