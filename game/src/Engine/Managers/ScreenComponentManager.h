#pragma once

#include "AbsComponentManager.h"
#include "../ScreenComponent.h"

namespace Engine {
namespace Managers {

class ScreenComponentManager : public AbsComponentManager<ScreenComponent*, bool> {
  public:
    ScreenComponentManager(Window* window);

    ScreenComponent* create_component(const int x, const int y, const int width, const int height, bool fill) override;
    void destroy_component(ScreenComponent* taget_component) override;
    void destroy_components() override;
    void update_components() override;
};

}
}
