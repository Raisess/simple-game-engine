#include "Platform.h"

Game::Platform::Platform(Engine::Managers::ScreenComponentManager* component_manager, PlatformOptions platform_options) {
  this->component = component_manager->create_component(platform_options.x, platform_options.y, platform_options.width, platform_options.height, platform_options.fill);
  this->component->set_color(0, 255, 0);
}

std::vector<Game::Platform*> Game::Platform::create_many(Engine::Managers::ScreenComponentManager* component_manager, std::vector<PlatformOptions> platforms_options) {
  std::vector<Platform*> tmp;
  for (PlatformOptions platform_options : platforms_options) {
    tmp.push_back(new Platform(component_manager, platform_options));
  }
  return tmp;
}
