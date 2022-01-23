#include <iostream>
#include "Engine/Window.h"
#include "Engine/Keyboard.h"

int main(int argc, char** argv) {
  auto* window = new Engine::Window("DwarfAttack", 640, 480);
  window->set_backgroud_color(0, 255, 0, 0);

  window->event_loop([](Engine::Window* win) {
    auto key = Engine::Keyboard::key();

    if (key[SDL_SCANCODE_RETURN]) {
      std::cout << "Return" << std::endl;
    }
  });

  std::cout << "Finished!" << std::endl;

  return 0;
}
