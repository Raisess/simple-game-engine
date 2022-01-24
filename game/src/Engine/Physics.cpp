#include <iostream>
#include "Physics.h"

#define GRAVITY_FORCE 0.2F

void Engine::Physics::apply_gravity(ScreenComponent* component, ScreenComponent* floor_component) {
  Position component_position = component->get_position();
  Size component_size = component->get_size();
  Position floor_position = floor_component->get_position();
  Size floor_size = floor_component->get_size();

  if (Engine::Physics::is_colliding(component, floor_component)) {
    component->set_gravity_speed(0);
    component->set_position(component_position.x, floor_position.y - floor_size.height - (component_size.height - floor_size.height));
  } else {
    component->set_gravity_speed(component->get_gravity_speed() + GRAVITY_FORCE);
    component->set_position(component_position.x, component_position.y + component->get_gravity_speed());
  }
}

bool Engine::Physics::is_colliding(ScreenComponent* x_component, ScreenComponent* y_component) {
  Position x_pos = x_component->get_position();
  Size x_size = x_component->get_size();
  Position y_pos = y_component->get_position();
  Size y_size = y_component->get_size();

  int a_left = x_pos.x;
  int a_right = x_pos.x + x_size.width;
  int b_left = y_pos.x;
  int b_right = y_pos.x + y_size.width;

  int a_top = x_pos.y;
  int a_bottom = x_pos.y + x_size.height;
  int b_top = y_pos.y;
  int b_bottom = y_pos.y + y_size.height;

  return 
    Engine::Physics::overlapping(a_left, a_right, b_left, b_right) &&
    Engine::Physics::overlapping(a_top, a_bottom, b_top, b_bottom);
}
