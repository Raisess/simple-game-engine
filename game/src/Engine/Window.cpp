#include "Window.h"

#define FPS_LIMIT 30

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
  this->sdl_renderer = SDL_CreateRenderer(this->sdl_window, -1, SDL_RENDERER_SOFTWARE);
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

int Engine::Window::get_fps() {
  return this->fps;
}

void Engine::Window::event_loop(const std::function<void(void)> callback) {
  int delta_time = 0;
  int start_tick = SDL_GetTicks();
  int last_tick = 0;

  while (this->is_active) {
    while (this->pool_event() != 0) {
      if (this->current_event.type == SDL_QUIT) {
        this->quit();
      }

      delta_time = last_tick - start_tick;

      if (delta_time < FPS_LIMIT) {
        SDL_Delay(FPS_LIMIT - delta_time);
      } else if (delta_time > FPS_LIMIT) {
        this->fps = 1000 / delta_time;
      }

      SDL_RenderClear(this->sdl_renderer);
      callback();
      SDL_RenderPresent(this->sdl_renderer);

      start_tick = last_tick;
      last_tick = SDL_GetTicks();
    }
  }
}
