#pragma once

#include <vector>
#include "../Window.h"

namespace Core {
namespace Managers {

template<typename T, typename OPT>
class AbsComponentManager {
  protected:
    Window* window;
    std::vector<T> components;

  public:
    AbsComponentManager(Window* window) {
      this->window = window;
    };

    virtual T create_component(const int x, const int y, const int width, const int height, OPT option) = 0;
    virtual void destroy_component(T taget_component) = 0;
    virtual void destroy_components() = 0;
    virtual void update_components() = 0;
};

}
}
