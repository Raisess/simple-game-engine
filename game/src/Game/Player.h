#pragma once

#include "../Engine/ScreenComponent.h"
#include "../Engine/Managers/ScreenComponentManager.h"

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
    void detect_keydown();
    bool is_colliding(Engine::ScreenComponent* colliding_component);
};

}
