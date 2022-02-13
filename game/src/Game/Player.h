#pragma once

#include "../Engine/Managers/ScreenComponentManager.h"
#include "../Engine/ScreenComponent.h"

typedef struct {
  const int x;
  const int y;
  const int width;
  const int height;
  bool fill;
} PlayerOptions;

namespace Game {

class Player {
  public:
    Engine::ScreenComponent* component;

    Player(Engine::Managers::ScreenComponentManager* component_manager, PlayerOptions player_options);

    void move_up();
    void move_right();
    void move_down();
    void move_left();
    void apply_gravity();
    bool is_colliding(Engine::ScreenComponent* colliding_component);
};

}
