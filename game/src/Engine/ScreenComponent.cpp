#include "ScreenComponent.h"

Engine::ScreenComponent::ScreenComponent(Window* window, const int x, const int y, const int width, const int heigth, bool fill) {
  this->window_renderer = window->sdl_renderer;
  this->fill = fill;

  this->update_pos(x, y);
  this->update_size(width, heigth);
  this->draw_rect();
}

void Engine::ScreenComponent::draw_rect() {
  this->rect = {
    this->position.x,
    this->position.y,
    this->size.width,
    this->size.heigth
  };

  SDL_SetRenderDrawColor(this->window_renderer, this->color.red, this->color.green, this->color.blue, 255);
  if (this->fill) {
    SDL_RenderFillRect(this->window_renderer, &this->rect);
  }
  SDL_RenderDrawRect(this->window_renderer, &this->rect);
  SDL_RenderPresent(this->window_renderer);
}
