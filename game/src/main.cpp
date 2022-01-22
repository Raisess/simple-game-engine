#include <iostream>
#include "Engine/Window.h"

int main(int argc, char** argv) {
  auto* window = new Engine::Window("DwarfAttack", 640, 480);

  window->event_loop([](Engine::Window* win) {});

  std::cout << "Finished!" << std::endl;

  return 0;
}
