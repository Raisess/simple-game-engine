#include <iostream>
#include <vector>
#include "Engine/Window.h"
#include "Engine/ScreenComponent.h"
#include "Engine/Managers/ScreenComponentManager.h"
#include "Engine/TextComponent.h"
#include "Engine/Managers/TextComponentManager.h"
#include "Game/Player.h"
#include "Game/Platform.h"
#include "Engine/Camera.h"
#include "Engine/Physics.h"
#include "Engine/Keyboard.h"

#define FILL_ALL true
#define FILL_PLAYER FILL_ALL && true
#define FILL_FLOOR FILL_ALL && true

int main(int argc, char** argv) {
  Engine::TextComponent::init();

  auto* window = new Engine::Window("DwarfAttack", 800, 600);
  window->set_backgroud_color(0, 0, 255);

  auto window_size = window->get_size();
  Size world_size = {
    1500,
    1000,
  };

  auto* text_component_manager = new Engine::Managers::TextComponentManager(window);
  auto* screen_component_manager = new Engine::Managers::ScreenComponentManager(window);

  auto* fps_text = text_component_manager->create_component(0, 0, 100, 30, 24);
  fps_text->set_color(255, 255, 0);
  auto* test_text = text_component_manager->create_component((window_size.width / 2) - 50, 0, 100, 30, 24);
  test_text->set_color(255, 255, 255);
  test_text->set_value("Test Text");

  auto* player = new Game::Player(
    screen_component_manager->create_component(window_size.width / 2, 0, 50, 50, FILL_PLAYER)
  );

  std::vector<Game::Platform*> platforms = Game::Platform::create_many(screen_component_manager, {
    { 0, 440, 1000, 40, FILL_FLOOR },
    { 440, 300, 200, 40, FILL_FLOOR },
    { 250, 150, 200, 40, FILL_FLOOR },
  });

  for (auto platform : platforms) {
    platform->component->set_color(0, 255, 0);
  }
  
  const auto callback = [
    window,
    world_size,
    fps_text,
    test_text,
    text_component_manager,
    screen_component_manager,
    player,
    platforms
  ]() -> void {
    Engine::Camera::set_camera_viewport(window, world_size, player->component);

    auto player_pos = player->component->get_position();
    auto player_size = player->component->get_size();

    auto key = Engine::Keyboard::key();
    if (key[SDL_SCANCODE_UP]) {
      player->move_up();
    } else if (key[SDL_SCANCODE_RIGHT]) {
      player->move_right();
    } else if (key[SDL_SCANCODE_DOWN]) {
      player->move_down();
    } else if (key[SDL_SCANCODE_LEFT]) {
      player->move_left();
    }

    player->apply_gravity();

    auto new_player_pos = player->component->get_position();
    test_text->set_value("Is not colliding");
    for (auto platform : platforms) {
      auto platform_pos = platform->component->get_position();
      auto platform_size = platform->component->get_size();

      if (player->is_colliding(platform->component)) {
        player->component->set_gravity_speed(0);
        player->component->set_position(new_player_pos.x, platform_pos.y - platform_size.height - (player_size.height - platform_size.height));
        test_text->set_value("Is colliding");
      }
    }

    std::string fps_text_str = "FPS: ";
    fps_text_str.append(std::to_string(window->get_fps()));
    fps_text->set_value(fps_text_str);

    text_component_manager->update_components();
    screen_component_manager->update_components();
    window->update();
  };
  window->event_loop(callback);

  text_component_manager->destroy_components();
  screen_component_manager->destroy_components();

  Engine::TextComponent::quit();
  return 0;
}
