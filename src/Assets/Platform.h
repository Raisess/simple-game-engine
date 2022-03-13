#pragma once

#include <vector>
#include "../Core/Managers/ScreenComponentManager.h"
#include "../Core/ScreenComponent.h"

typedef struct {
  const int x;
  const int y;
  const int width;
  const int height;
  bool fill;
} PlatformOptions;

namespace Assets {

class Platform {
  public:
    Core::ScreenComponent* component;

    Platform(Core::Managers::ScreenComponentManager* component_manager, PlatformOptions platform_options);

    static std::vector<Platform*> create_many(Core::Managers::ScreenComponentManager* component_manager, std::vector<PlatformOptions> platforms_options);
};

}
