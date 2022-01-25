#pragma once

#include "../Engine/ScreenComponent.h"

namespace Game {

class Player {
  public:
    Engine::ScreenComponent* component;

    Player(Engine::ScreenComponent* component);

    void move_up();
    void move_right();
    void move_down();
    void move_left();
    void apply_gravity();
    bool is_colliding(Engine::ScreenComponent* colliding_component);
};

}
