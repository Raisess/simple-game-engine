#include "ScreenComponent.h"

Engine::ScreenComponent::ScreenComponent(Window* window, const int x, const int y, const int width, const int height, bool fill) {
  this->window_renderer = window->sdl_renderer;
  this->fill = fill;

  this->set_position(x, y);
  this->set_size(width, height);
  this->draw_rect();
}

void Engine::ScreenComponent::draw_rect() {
  this->rect = {
    this->position.x,
    this->position.y,
    this->size.width,
    this->size.height
  };

  if (this->fill) {
    SDL_RenderFillRect(this->window_renderer, &this->rect);
  } else {
    SDL_RenderDrawRect(this->window_renderer, &this->rect);
  }

  SDL_SetRenderDrawColor(this->window_renderer, this->color.red, this->color.green, this->color.blue, 255);
}
