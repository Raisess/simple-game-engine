#pragma once

#include "Window.h"
#include "ScreenComponent.h"

namespace Core {

class Camera {
  public:
    static void set_camera_viewport(Window* window, Size world_size, ScreenComponent* rel_component);
};

}
