#pragma once

#include "../Core/ScreenComponent.h"
#include "../Core/Managers/ScreenComponentManager.h"

typedef struct {
  const int x;
  const int y;
  const int width;
  const int height;
  bool fill;
} PlayerOptions;

namespace Assets {

class Player {
  public:
    Core::ScreenComponent* component;

    Player(Core::Managers::ScreenComponentManager* component_manager, PlayerOptions player_options);

    void move_up();
    void move_right();
    void move_down();
    void move_left();
    void apply_gravity();
    void detect_keydown();
    bool is_colliding(Core::ScreenComponent* colliding_component);
};

}
