#include <iostream>
#include <vector>
#include "../Core/Window.h"
#include "../Core/Camera.h"
#include "../Core/Keyboard.h"
#include "../Core/Managers/ScreenComponentManager.h"
#include "../Core/Managers/TextComponentManager.h"
#include "../Assets/Player.h"
#include "../Assets/Platform.h"

#define FILL_ALL true
#define FILL_PLAYER FILL_ALL && true
#define FILL_FLOOR FILL_ALL && true

int main(int argc, char** argv) {
  Core::TextComponent::init();

  auto* window = new Core::Window("Simple Game Engine", 800, 600);
  window->set_backgroud_color(0, 0, 255);

  auto window_size = window->get_size();
  const int middle_screen = window_size.width / 2;
  const Size world_size = {
    1500,
    1000,
  };

  auto* text_component_manager = new Core::Managers::TextComponentManager(window);
  auto* screen_component_manager = new Core::Managers::ScreenComponentManager(window);

  auto* fps_text = text_component_manager->create_component(0, 0, 100, 30, 24);
  fps_text->set_color(255, 255, 0);

  auto* player = new Assets::Player(screen_component_manager, { middle_screen + 500, 0, 50, 50, FILL_PLAYER });
  auto* enemy = new Assets::Player(screen_component_manager, { middle_screen + 600, 0, 50, 50, FILL_PLAYER });
  std::vector<Assets::Player*> live_entities = { player, enemy };

  auto platforms = Assets::Platform::create_many(screen_component_manager, {
    { middle_screen, 440, 1000, 40, FILL_FLOOR },
    { middle_screen + 440, 300, 200, 40, FILL_FLOOR },
    { middle_screen + 250, 150, 200, 40, FILL_FLOOR },
  });

  enemy->component->set_color(255, 255, 0);
  
  const auto callback = [&]() -> void {
    std::string fps_text_str = "FPS: ";
    fps_text_str.append(std::to_string(window->get_fps()));
    fps_text->set_value(fps_text_str);

    Core::Camera::set_camera_viewport(window, world_size, player->component);

    auto key_down = Core::Keyboard::key();

    if (key_down[SDL_SCANCODE_UP]) {
      player->move_up();
    } else if (key_down[SDL_SCANCODE_RIGHT]) {
      player->move_right();
    } else if (key_down[SDL_SCANCODE_DOWN]) {
      player->move_down();
    } else if (key_down[SDL_SCANCODE_LEFT]) {
      player->move_left();
    }

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

    text_component_manager->update_components();
    screen_component_manager->update_components();
  };
  window->event_loop(callback);

  text_component_manager->destroy_components();
  screen_component_manager->destroy_components();

  Core::TextComponent::quit();
  return 0;
}
