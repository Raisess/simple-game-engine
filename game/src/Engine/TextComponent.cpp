#include "TextComponent.h"
#include "../Utils/Logger.h"

#define FONT_PATH "/usr/share/fonts/TTF/OpenSans-Bold.ttf"

Engine::TextComponent::TextComponent(Window* window, const int x, const int y, const int width, const int height, const int font_size) {
  this->active = true;
  this->window = window;

  this->set_position(x, y);
  this->set_size(width, height);

  this->font = TTF_OpenFont(FONT_PATH, font_size);

  if (!this->font) {
    Utils::Logger::error("TextComponent", "Failed to load font: ", TTF_GetError());
  }
}

void Engine::TextComponent::init() {
  TTF_Init();
}

void Engine::TextComponent::quit() {
  TTF_Quit();
}

Engine::TextComponent::~TextComponent() {
  if (this->active) {
    this->active = false;
    SDL_FreeSurface(this->sdl_surface);
    SDL_DestroyTexture(this->sdl_texture);
  }
}

void Engine::TextComponent::draw_text() {
  if (this->active) {
    this->sdl_surface = TTF_RenderText_Solid(this->font, this->value.c_str(), this->color);
    this->sdl_texture = SDL_CreateTextureFromSurface(this->window->sdl_renderer, this->sdl_surface);

    Size window_size = this->window->get_size();
    SDL_Rect camera_rect;
    SDL_RenderGetViewport(this->window->sdl_renderer, &camera_rect);

    SDL_Rect rect = {
      ((this->position.x - camera_rect.x) + (window_size.width / 6)) - this->size.width,
      this->position.y,
      this->size.width,
      this->size.height
    };

    SDL_RenderCopy(this->window->sdl_renderer, this->sdl_texture, NULL, &rect);
  }
}
