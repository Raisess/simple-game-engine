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
} ObjectOptions;

namespace Assets {

class Object {
  public:
    Core::ScreenComponent* component;

    Object(Core::Managers::ScreenComponentManager* component_manager, ObjectOptions player_options);

    static std::vector<Object*> create_many(Core::Managers::ScreenComponentManager* component_manager, std::vector<ObjectOptions> objects_options);
    void move_up(const int speed = PLAYER_SPEED);
    void move_right(const int speed = PLAYER_SPEED);
    void move_down(const int speed = PLAYER_SPEED);
    void move_left(const int speed = PLAYER_SPEED);
    void apply_gravity();
    void detect_keydown();
    bool is_colliding(Core::ScreenComponent* colliding_component);
};

}
