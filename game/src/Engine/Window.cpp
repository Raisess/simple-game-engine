#include "Window.h"

Engine::Window::Window(const char* window_name, const int width, const int height) {
  this->is_active = true;
  this->window_size = { width, height };

  SDL_Init(SDL_INIT_VIDEO);
  this->sdl_window = SDL_CreateWindow(
    window_name,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    this->window_size.width,
    this->window_size.height,
    SDL_WINDOW_SHOWN
  );
  this->sdl_renderer = SDL_CreateRenderer(this->sdl_window, -1, SDL_RENDERER_ACCELERATED);
}

Engine::Window::~Window() {
  this->is_active = false;

  SDL_DestroyRenderer(this->sdl_renderer);
  SDL_DestroyWindow(this->sdl_window);
  SDL_Quit();
}

int Engine::Window::pool_event() {
  return SDL_PollEvent(&this->current_event);
}

void Engine::Window::set_backgroud_color(const int red, const int green, const int blue) {
  this->window_bg_color = { red, green, blue };

  SDL_SetRenderDrawColor(this->sdl_renderer, red, green, blue, 0);
  SDL_RenderClear(this->sdl_renderer);
  SDL_RenderPresent(this->sdl_renderer);
}

void Engine::Window::event_loop(const std::function<void(void)> callback) {
  while (this->is_active) {
    while (this->pool_event() != 0) {
      if (this->current_event.type == SDL_QUIT) {
        this->quit();
      }

      this->update();
      callback();
    }
  }
}
