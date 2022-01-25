#pragma once

#include "AbsComponentManager.h"
#include "../TextComponent.h"

namespace Engine {
namespace Managers {

class TextComponentManager : public AbsComponentManager<TextComponent*, const int> {
  public:
    TextComponentManager(Window* window);

    TextComponent* create_component(const int x, const int y, const int width, const int height, const int font_size) override;
    void destroy_component(TextComponent* taget_component) override;
    void destroy_components() override;
    void update_components() override;
};

}
}
