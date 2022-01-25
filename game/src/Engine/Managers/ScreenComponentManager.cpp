#include "ScreenComponentManager.h"

Engine::Managers::ScreenComponentManager::ScreenComponentManager(Window* window) : AbsComponentManager(window) {}

Engine::ScreenComponent* Engine::Managers::ScreenComponentManager::create_component(const int x, const int y, const int width, const int height, bool fill) {
  auto* component = new ScreenComponent(this->window, x, y, width, height, fill);
  this->components.push_back(component);

  return component;
}

void Engine::Managers::ScreenComponentManager::destroy_component(ScreenComponent* target_component) {
  std::vector<ScreenComponent*> tmp;

  for (auto* component : this->components) {
    if (target_component != component) {
      tmp.push_back(component);
    }
  }

  this->components = tmp;
  target_component->destroy();
}

void Engine::Managers::ScreenComponentManager::destroy_components() {
  for (auto* component : this->components) {
    component->destroy();
  }

  this->components = {};
}

void Engine::Managers::ScreenComponentManager::update_components() {
  for (auto* component : this->components) {
    component->update();
  }
}
