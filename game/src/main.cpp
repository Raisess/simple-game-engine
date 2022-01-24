#include <iostream>
#include <vector>
#include "Engine/Window.h"
#include "Engine/ScreenComponent.h"
#include "Engine/TextComponent.h"
#include "Engine/Physics.h"
#include "Engine/Keyboard.h"

#define FILL_PLAYER true
#define FILL_FLOOR true
#define PLAYER_SPEED 5

int main(int argc, char** argv) {
  auto* window = new Engine::Window("DwarfAttack", 640, 480);
  window->set_backgroud_color(0, 0, 255);

  auto* fps_text = new Engine::TextComponent(window, 0, 0, 100, 30, 24);
  fps_text->set_color(255, 255, 0);
  auto* player = new Engine::ScreenComponent(window, 0, 0, 50, 50, FILL_PLAYER);
  player->set_color(255, 0, 0);

  std::vector<Engine::ScreenComponent*> platforms = {
    new Engine::ScreenComponent(window, 0, 440, 640, 40, FILL_FLOOR),
    new Engine::ScreenComponent(window, 440, 300, 200, 40, FILL_FLOOR),
    new Engine::ScreenComponent(window, 250, 150, 200, 40, FILL_FLOOR),
  };

  for (auto platform : platforms) {
    platform->set_color(0, 255, 0);
  }
  
  const auto callback = [window, fps_text, player, platforms]() -> void {
    auto key = Engine::Keyboard::key();
    auto player_pos = player->get_position();
    auto player_size = player->get_size();

    if (key[SDL_SCANCODE_RIGHT]) {
      player->set_position(player_pos.x + PLAYER_SPEED, player_pos.y);
    } else if (key[SDL_SCANCODE_LEFT]) {
      player->set_position(player_pos.x - PLAYER_SPEED, player_pos.y);
    } else if (key[SDL_SCANCODE_UP]) {
      player->set_position(player_pos.x, player_pos.y - (PLAYER_SPEED + 2));
    } else if (key[SDL_SCANCODE_DOWN]) {
      player->set_position(player_pos.x, player_pos.y + PLAYER_SPEED);
    }

    Engine::Physics::apply_gravity(player);

    auto new_player_pos = player->get_position();

    for (auto platform : platforms) {
      auto platform_pos = platform->get_position();
      auto platform_size = platform->get_size();

      if (Engine::Physics::is_colliding(player, platform)) {
        player->set_gravity_speed(0);
        player->set_position(new_player_pos.x, platform_pos.y - platform_size.height - (player_size.height - platform_size.height));
      }

      platform->update();
    }

    std::string fps_text_str = "FPS: ";
    fps_text_str.append(std::to_string(window->get_fps()));
    fps_text->set_value(fps_text_str);
    fps_text->update();

    player->update();
    window->update();
  };

  window->event_loop(callback);
  fps_text->destroy();

  return 0;
}
