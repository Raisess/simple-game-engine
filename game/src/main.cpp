#include <iostream>
#include "Engine/Window.h"

int main(int argc, char** argv) {
  auto* window = new Engine::Window(300, 200);

  window->event_loop([](Engine::Window* win) {
    win->quit();
  });

  std::cout << "Finished!" << std::endl;

  return 0;
}
