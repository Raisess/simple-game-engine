#include "TextComponent.h"

#define FONT_PATH "/usr/share/fonts/TTF/OpenSans-Bold.ttf"

Engine::TextComponent::TextComponent(Window* window, const int x, const int y, const int width, const int height, const int font_size) {
  this->window_renderer = window->sdl_renderer;

  this->set_position(x, y);
  this->set_size(width, height);

  TTF_Init();
  this->font = TTF_OpenFont(FONT_PATH, font_size);
  if (!this->font) {
    std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
  }
}

Engine::TextComponent::~TextComponent() {
  SDL_FreeSurface(this->sdl_surface);
  SDL_DestroyTexture(this->sdl_texture);
  TTF_Quit();
}

void Engine::TextComponent::draw_text() {
  this->sdl_surface = TTF_RenderText_Solid(this->font, this->value.c_str(), this->color);
  this->sdl_texture = SDL_CreateTextureFromSurface(this->window_renderer, this->sdl_surface);

  SDL_Rect rect = {
    this->position.x,
    this->position.y,
    this->size.width,
    this->size.height
  };

  SDL_RenderCopy(this->window_renderer, this->sdl_texture, NULL, &rect);
}
