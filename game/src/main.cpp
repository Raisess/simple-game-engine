#include <iostream>
#include "Engine/Window.h"
#include "Engine/ScreenComponent.h"
#include "Engine/Physics.h"
#include "Engine/Keyboard.h"

#define FILL_PLAYER true
#define FILL_FLOOR true
#define PLAYER_SPEED 5

int main(int argc, char** argv) {
  auto* window = new Engine::Window("DwarfAttack", 640, 480);
  window->set_backgroud_color(0, 0, 255);

  auto* player = new Engine::ScreenComponent(window, 0, 0, 50, 50, FILL_PLAYER);
  player->set_color(255, 0, 0);
  auto* floor = new Engine::ScreenComponent(window, 0, 440, 640, 40, FILL_FLOOR);
  floor->set_color(0, 255, 0);
  
  const auto callback = [window, player, floor]() -> void {
    auto key = Engine::Keyboard::key();
    auto player_pos = player->get_position();

    if (key[SDL_SCANCODE_RIGHT]) {
      player->set_position(player_pos.x + PLAYER_SPEED, player_pos.y);
    } else if (key[SDL_SCANCODE_LEFT]) {
      player->set_position(player_pos.x - PLAYER_SPEED, player_pos.y);
    } else if (key[SDL_SCANCODE_UP]) {
      player->set_position(player_pos.x, player_pos.y - (PLAYER_SPEED + 2));
    } else if (key[SDL_SCANCODE_DOWN]) {
      player->set_position(player_pos.x, player_pos.y + PLAYER_SPEED);
    }

    Engine::Physics::apply_gravity(player, floor);
    player->update();
    floor->update();
    window->update();

    // std::cout << "FPS: " << window->get_fps() << std::endl;
  };

  window->event_loop(callback);

  std::cout << "Finished!" << std::endl;

  return 0;
}
