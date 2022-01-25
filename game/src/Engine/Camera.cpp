#include "Camera.h"

void Engine::Camera::set_camera_viewport(Window* window, Size world_size, ScreenComponent* rel_component) {
  Size window_size = window->get_size();
  Size rel_component_size = rel_component->get_size();
  Position rel_component_pos = rel_component->get_position();

  SDL_Rect rect = {
    ((rel_component_pos.x - (rel_component_pos.x * 2)) + (window_size.width / 2)) - (rel_component_size.width / 2),
    0,
    world_size.width,
    world_size.height
  };

  SDL_RenderSetViewport(window->sdl_renderer, &rect);
}
