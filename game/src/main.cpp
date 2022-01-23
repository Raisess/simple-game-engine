#include <iostream>
#include "Engine/Window.h"
#include "Engine/ScreenComponent.h"
#include "Engine/Keyboard.h"

int main(int argc, char** argv) {
  auto* window = new Engine::Window("DwarfAttack", 640, 480);
  window->set_backgroud_color(0, 0, 255);

  auto* some_component = new Engine::ScreenComponent(window, 0, 0, 100, 100, true);
  some_component->set_color(255, 0, 0);
  auto* floor_component = new Engine::ScreenComponent(window, 0, 440, 640, 40, true);
  floor_component->set_color(0, 255, 0);
  
  const auto callback = [window, some_component, floor_component]() -> void {
    auto key = Engine::Keyboard::key();
    auto some_component_pos = some_component->get_position();

    if (key[SDL_SCANCODE_RIGHT]) {
      some_component->set_position(some_component_pos.x + 10, some_component_pos.y);
    } else if (key[SDL_SCANCODE_LEFT]) {
      some_component->set_position(some_component_pos.x - 10, some_component_pos.y);
    } else if (key[SDL_SCANCODE_UP]) {
      some_component->set_position(some_component_pos.x, some_component_pos.y - 10);
    } else if (key[SDL_SCANCODE_DOWN]) {
      some_component->set_position(some_component_pos.x, some_component_pos.y + 10);
    }

    window->update();
    floor_component->update();
    some_component->update();
  };

  window->event_loop(callback);

  std::cout << "Finished!" << std::endl;

  return 0;
}
