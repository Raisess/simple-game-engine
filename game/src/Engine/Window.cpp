#include "Window.h"

Engine::Window::Window(const char* window_name, const int width, const int height) {
  this->is_active = true;
  this->size = { width, height };

  SDL_Init(SDL_INIT_VIDEO);
  this->sdl_window = SDL_CreateWindow(
    window_name,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    this->size.width,
    this->size.height,
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

void Engine::Window::draw_background() {
  SDL_SetRenderDrawColor(this->sdl_renderer, this->color.red, this->color.green, this->color.blue, 0);
}

void Engine::Window::event_loop(const std::function<void(void)> callback) {
  while (this->is_active) {
    while (this->pool_event() != 0) {
      if (this->current_event.type == SDL_QUIT) {
        this->quit();
      }

      SDL_RenderClear(this->sdl_renderer);
      callback();
      SDL_RenderPresent(this->sdl_renderer);
    }
  }
}
