#include <iostream>
#include "../Core/Window.h"
#include "../Core/Keyboard.h"
#include "../Core/Managers/ScreenComponentManager.h"
#include "../Assets/Object.h"

#define FILL_OBJECT true

int main() {
  auto* window = new Core::Window("Pong", 800, 600);
  const auto window_size = window->get_size();

  auto* screen_component_manager = new Core::Managers::ScreenComponentManager(window);

  auto* left_player = new Assets::Object(screen_component_manager, { 10, (window_size.height / 2) - 50, 10, 100, FILL_OBJECT });
  auto left_player_size = left_player->component->get_size();
  left_player->component->set_color(255, 255, 255);

  auto* right_player = new Assets::Object(screen_component_manager, { window_size.width - 20, (window_size.height / 2) - 50, 10, 100, FILL_OBJECT });
  auto right_player_size = right_player->component->get_size();
  right_player->component->set_color(255, 255, 255);

  auto* ball = new Assets::Object(screen_component_manager, { 0, 0, 20, 20, FILL_OBJECT });
  auto ball_size = ball->component->get_size();
  ball->component->set_color(255, 255, 255);

  int player_speed = 5;
  int ball_speed = 3;
  bool to_right = true;
  bool to_down = true;

  window->loop([&]() -> void {
    auto key_down = Core::Keyboard::key();

    auto left_player_pos = left_player->component->get_position();
    auto right_player_pos = right_player->component->get_position();
    auto ball_pos = ball->component->get_position();

    if (key_down[SDL_SCANCODE_W] && left_player_pos.y >= 0) {
      left_player->move_up(player_speed);
    } else if (key_down[SDL_SCANCODE_S] && left_player_pos.y <= (window_size.height - left_player_size.height)) {
      left_player->move_down(player_speed);
    }

    if (key_down[SDL_SCANCODE_UP] && right_player_pos.y >= 0) {
      right_player->move_up(player_speed);
    } else if (key_down[SDL_SCANCODE_DOWN] && right_player_pos.y <= (window_size.height - right_player_size.height)) {
      right_player->move_down(player_speed);
    }

    if (ball_pos.y <= 0) {
      to_down = true;
    }

    if (ball_pos.y >= (window_size.height - ball_size.height)) {
      to_down = false;
    }

    if (ball_pos.x > window_size.width) {
      ball->component->set_position(window_size.width, 0);
      to_down = true;
      to_right = false;
      ball_speed = 3;
      player_speed = 5;
    }

    if (ball_pos.x < 0) {
      ball->component->set_position(0, 0);
      to_down = true;
      to_right = true;
      ball_speed = 3;
      player_speed = 5;
    }

    if (ball->is_colliding(right_player->component)) {
      to_right = false;
      player_speed += 1;
      ball_speed += 1;
    }

    if (ball->is_colliding(left_player->component)) {
      to_right = true;
      player_speed += 1;
      ball_speed += 1;
    }

    if (to_right) {
      ball->move_right(ball_speed);
    } else {
      ball->move_left(ball_speed);
    }

    if (to_down) {
      ball->move_down(ball_speed);
    } else {
      ball->move_up(ball_speed);
    }

    screen_component_manager->update_components();
  });

  screen_component_manager->destroy_components();

  return 0;
}
