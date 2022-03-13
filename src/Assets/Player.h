#pragma once

#include "../Core/ScreenComponent.h"
#include "../Core/Managers/ScreenComponentManager.h"

#define PLAYER_SPEED 5

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

    void move_up(const int speed = PLAYER_SPEED);
    void move_right(const int speed = PLAYER_SPEED);
    void move_down(const int speed = PLAYER_SPEED);
    void move_left(const int speed = PLAYER_SPEED);
    void apply_gravity();
    void detect_keydown();
    bool is_colliding(Core::ScreenComponent* colliding_component);
};

}
