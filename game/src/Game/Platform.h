#pragma once

#include <vector>
#include "../Engine/Managers/ScreenComponentManager.h"
#include "../Engine/ScreenComponent.h"

typedef struct {
  const int x;
  const int y;
  const int width;
  const int height;
  bool fill;
} PlatformOptions;

namespace Game {

class Platform {
  public:
    Engine::ScreenComponent* component;

    Platform(Engine::Managers::ScreenComponentManager* component_manager, PlatformOptions platform_options);

    static std::vector<Platform*> create_many(Engine::Managers::ScreenComponentManager* component_manager, std::vector<PlatformOptions> platforms_options);
};

}
