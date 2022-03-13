#include <iostream>
#include "Object.h"
#include "../Core/Physics.h"
#include "../Core/Keyboard.h"

Assets::Object::Object(Core::Managers::ScreenComponentManager* component_manager, ObjectOptions player_options) {
  this->component = component_manager->create_component(player_options.x, player_options.y, player_options.width, player_options.height, player_options.fill);
}

std::vector<Assets::Object*> Assets::Object::create_many(Core::Managers::ScreenComponentManager* component_manager, std::vector<ObjectOptions> object_options) {
  std::vector<Object*> tmp;
  for (ObjectOptions object_options : object_options) {
    tmp.push_back(new Object(component_manager, object_options));
  }
  return tmp;
}

void Assets::Object::move_up(const int speed) {
  Position position = this->component->get_position();
  this->component->set_position(position.x, position.y - (speed));
}

void Assets::Object::move_right(const int speed) {
  Position position = this->component->get_position();
  this->component->set_position(position.x + speed, position.y);
}

void Assets::Object::move_down(const int speed) {
  Position position = this->component->get_position();
  this->component->set_position(position.x, position.y + speed);
}

void Assets::Object::move_left(const int speed) {
  Position position = this->component->get_position();
  this->component->set_position(position.x - speed, position.y);
}

void Assets::Object::apply_gravity() {
  Core::Physics::apply_gravity(this->component);

  auto pos = this->component->get_position();

  if (pos.y >= 2000) {
    this->component->set_position(pos.x - 10, 0);
  }
}

bool Assets::Object::is_colliding(Core::ScreenComponent* colliding_component) {
  return Core::Physics::is_colliding(this->component, colliding_component);
}
