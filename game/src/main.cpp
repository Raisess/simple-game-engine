#include <iostream>
#include <vector>
#include "Engine/Window.h"
#include "Engine/Camera.h"
#include "Engine/Managers/ScreenComponentManager.h"
#include "Engine/Managers/TextComponentManager.h"
#include "Game/Player.h"
#include "Game/Platform.h"

#define FILL_ALL true
#define FILL_PLAYER FILL_ALL && true
#define FILL_FLOOR FILL_ALL && true

int main(int argc, char** argv) {
  Engine::TextComponent::init();

  auto* window = new Engine::Window("DwarfAttack", 800, 600);
  window->set_backgroud_color(0, 0, 255);

  auto window_size = window->get_size();
  const int middle_screen = window_size.width / 2;
  const Size world_size = {
    1500,
    1000,
  };

  auto* text_component_manager = new Engine::Managers::TextComponentManager(window);
  auto* screen_component_manager = new Engine::Managers::ScreenComponentManager(window);

  auto* fps_text = text_component_manager->create_component(0, 0, 100, 30, 24);
  fps_text->set_color(255, 255, 0);

  auto* player = new Game::Player(screen_component_manager, { middle_screen + 500, 0, 50, 50, FILL_PLAYER });
  auto* enemy = new Game::Player(screen_component_manager, { middle_screen + 600, 0, 50, 50, FILL_PLAYER });
  std::vector<Game::Player*> live_entities = { player, enemy };

  auto platforms = Game::Platform::create_many(screen_component_manager, {
    { middle_screen, 440, 1000, 40, FILL_FLOOR },
    { middle_screen + 440, 300, 200, 40, FILL_FLOOR },
    { middle_screen + 250, 150, 200, 40, FILL_FLOOR },
  });

  enemy->component->set_color(255, 255, 0);
  
  const auto callback = [&]() -> void {
    Engine::Camera::set_camera_viewport(window, world_size, player->component);

    player->detect_keydown();

    for (auto entity : live_entities) {
      entity->apply_gravity();
    }

    for (auto platform : platforms) {
      auto platform_pos = platform->component->get_position();
      auto platform_size = platform->component->get_size();

      for (auto entity : live_entities) {
        auto entity_pos = entity->component->get_position();
        auto entity_size = entity->component->get_size();

        if (entity->is_colliding(platform->component)) {
          entity->component->set_gravity_speed(0);
          entity->component->set_position(entity_pos.x, platform_pos.y - platform_size.height - (entity_size.height - platform_size.height));
        }
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
