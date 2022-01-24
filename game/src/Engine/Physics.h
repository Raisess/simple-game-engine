#pragma once

#include "ScreenComponent.h"

namespace Engine {

class Physics {
  private:
    bool static overlapping(const int min_a, const int max_a, const int min_b, const int max_b) {
      return min_b <= max_a && min_a <= max_b;
    }

  public:
    void static apply_gravity(ScreenComponent* component);
    bool static is_colliding(ScreenComponent* x_component, ScreenComponent* y_component);
};

}
