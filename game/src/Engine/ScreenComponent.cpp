#include "ScreenComponent.h"

Engine::ScreenComponent::ScreenComponent(Window* window, const int x, const int y, const int width, const int heigth) {
  this->window_renderer = window->sdl_renderer;

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

  SDL_SetRenderDrawColor(this->window_renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(this->window_renderer, &this->rect);
  SDL_RenderDrawRect(this->window_renderer, &this->rect);
  SDL_RenderPresent(this->window_renderer);
}

void Engine::ScreenComponent::update_pos(const int x, const int y) {
  this->position = { x, y };
}

void Engine::ScreenComponent::update_size(const int width, const int heigth) {
  this->size = { width, heigth };
}
