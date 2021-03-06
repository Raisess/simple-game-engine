#include "ScreenComponent.h"

Core::ScreenComponent::ScreenComponent(Window* window, const int x, const int y, const int width, const int height, bool fill) {
  this->active = true;
  this->window = window;
  this->fill = fill;

  this->set_position(x, y);
  this->set_size(width, height);
}

Core::ScreenComponent::~ScreenComponent() {
  this->active = false;
}

void Core::ScreenComponent::draw_rect() {
  if (this->active) {
    SDL_Rect rect = {
      this->position.x,
      this->position.y,
      this->size.width,
      this->size.height
    };

    SDL_SetRenderDrawColor(this->window->sdl_renderer, this->color.red, this->color.green, this->color.blue, 0);

    if (this->fill) {
      SDL_RenderFillRect(this->window->sdl_renderer, &rect);
    } else {
      SDL_RenderDrawRect(this->window->sdl_renderer, &rect);
    }
  }
}
