#include "Player.h"
#include "../Engine/Physics.h"

#define PLAYER_SPEED 5

Game::Player::Player(Engine::Managers::ScreenComponentManager* component_manager, PlayerOptions player_options) {
  this->component = component_manager->create_component(player_options.x, player_options.y, player_options.width, player_options.height, player_options.fill);
  this->component->set_color(255, 0, 0);
}

void Game::Player::move_up() {
  Position position = this->component->get_position();
  this->component->set_position(position.x, position.y - (PLAYER_SPEED + 2));
}

void Game::Player::move_right() {
  Position position = this->component->get_position();
  this->component->set_position(position.x + PLAYER_SPEED, position.y);
}

void Game::Player::move_down() {
  Position position = this->component->get_position();
  this->component->set_position(position.x, position.y + PLAYER_SPEED);
}

void Game::Player::move_left() {
  Position position = this->component->get_position();
  this->component->set_position(position.x - PLAYER_SPEED, position.y);
}

void Game::Player::apply_gravity() {
  Engine::Physics::apply_gravity(this->component);
}

bool Game::Player::is_colliding(Engine::ScreenComponent* colliding_component) {
  return Engine::Physics::is_colliding(this->component, colliding_component);
}
