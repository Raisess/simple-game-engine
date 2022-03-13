#include <iostream>
#include "Player.h"
#include "../Core/Physics.h"
#include "../Core/Keyboard.h"

#define PLAYER_SPEED 5

Assets::Player::Player(Core::Managers::ScreenComponentManager* component_manager, PlayerOptions player_options) {
  this->component = component_manager->create_component(player_options.x, player_options.y, player_options.width, player_options.height, player_options.fill);
  this->component->set_color(255, 0, 0);
}

void Assets::Player::move_up() {
  Position position = this->component->get_position();
  this->component->set_position(position.x, position.y - (PLAYER_SPEED + 2));
}

void Assets::Player::move_right() {
  Position position = this->component->get_position();
  this->component->set_position(position.x + PLAYER_SPEED, position.y);
}

void Assets::Player::move_down() {
  Position position = this->component->get_position();
  this->component->set_position(position.x, position.y + PLAYER_SPEED);
}

void Assets::Player::move_left() {
  Position position = this->component->get_position();
  this->component->set_position(position.x - PLAYER_SPEED, position.y);
}

void Assets::Player::apply_gravity() {
  Core::Physics::apply_gravity(this->component);

  auto pos = this->component->get_position();

  if (pos.y >= 2000) {
    this->component->set_position(pos.x - 10, 0);
  }
}

bool Assets::Player::is_colliding(Core::ScreenComponent* colliding_component) {
  return Core::Physics::is_colliding(this->component, colliding_component);
}
