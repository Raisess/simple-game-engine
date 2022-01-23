#include <iostream>
#include <vector>
#include "Engine/Window.h"
#include "Engine/ScreenComponent.h"
#include "Engine/Keyboard.h"

int main(int argc, char** argv) {
  auto* window = new Engine::Window("DwarfAttack", 640, 480);
  auto* some_component = new Engine::ScreenComponent(window, 0, 0, 100, 100);
  // window->set_backgroud_color(0, 255, 0, 0);
  
  const auto callback = [window, some_component]() -> void {
    auto key = Engine::Keyboard::key();

    if (key[SDL_SCANCODE_RETURN]) {
      auto some_component_pos = some_component->get_position();

      some_component->update_pos(some_component_pos.x + 10, some_component_pos.y + 10);
    }

    some_component->update();
  };

  window->event_loop(callback);

  std::cout << "Finished!" << std::endl;

  return 0;
}
