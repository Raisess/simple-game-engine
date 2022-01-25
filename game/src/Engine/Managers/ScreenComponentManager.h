#pragma once

#include <vector>
#include "../Window.h"
#include "../ScreenComponent.h"

namespace Engine {
namespace Managers {

class ScreenComponentManager {
  private:
    Window* window;
    std::vector<ScreenComponent*> components;

  public:
    ScreenComponentManager(Window* window);

    ScreenComponent* create_component(const int x, const int y, const int width, const int height, bool fill);
    void destroy_component(ScreenComponent* taget_component);
    void update_components();
};

}
}
