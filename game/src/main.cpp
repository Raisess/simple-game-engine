#include <iostream>
#include <vector>
#include "Engine/Window.h"
#include "Engine/ScreenComponent.h"
#include "Engine/Managers/ScreenComponentManager.h"
#include "Engine/TextComponent.h"
#include "Engine/Camera.h"
#include "Engine/Physics.h"
#include "Engine/Keyboard.h"

#define FILL_PLAYER true
#define FILL_FLOOR true
#define PLAYER_SPEED 5

int main(int argc, char** argv) {
  auto* window = new Engine::Window("DwarfAttack", 640, 480);
  auto* screen_component_manager = new Engine::Managers::ScreenComponentManager(window);
  auto window_size = window->get_size();
  window->set_backgroud_color(0, 0, 255);

  Size world_size = {
    1500,
    1000,
  };

  Engine::TextComponent::init();
  auto* fps_text = new Engine::TextComponent(window, 0, 0, 100, 30, 24);
  fps_text->set_color(255, 255, 0);
  auto* test_text = new Engine::TextComponent(window, (window_size.width / 2) - 50, 0, 100, 30, 24);
  test_text->set_color(255, 255, 255);
  test_text->set_value("Test Text");

  auto* player = screen_component_manager->create_component(window_size.width / 2, 0, 50, 50, FILL_PLAYER);
  player->set_color(255, 0, 0);

  std::vector<Engine::ScreenComponent*> platforms = {
    screen_component_manager->create_component(0, 440, 1000, 40, FILL_FLOOR),
    screen_component_manager->create_component(440, 300, 200, 40, FILL_FLOOR),
    screen_component_manager->create_component(250, 150, 200, 40, FILL_FLOOR),
  };

  for (auto platform : platforms) {
    platform->set_color(0, 255, 0);
  }
  
  const auto callback = [window, world_size, fps_text, test_text, screen_component_manager, player, platforms]() -> void {
    Engine::Camera::set_camera_viewport(window, world_size, player);

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
        test_text->destroy();
      }
    }

    std::string fps_text_str = "FPS: ";
    fps_text_str.append(std::to_string(window->get_fps()));
    fps_text->set_value(fps_text_str);
    fps_text->update();
    test_text->update();

    screen_component_manager->update_components();
    window->update();
  };

  window->event_loop(callback);
  fps_text->destroy();
  test_text->destroy();

  Engine::TextComponent::quit();

  return 0;
}
