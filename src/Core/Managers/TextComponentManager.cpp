#include "TextComponentManager.h"

Core::Managers::TextComponentManager::TextComponentManager(Window* window) : AbsComponentManager(window) {}

Core::TextComponent* Core::Managers::TextComponentManager::create_component(const int x, const int y, const int width, const int height, const int font_size) {
  auto* component = new TextComponent(this->window, x, y, width, height, font_size);
  this->components.push_back(component);

  return component;
}

void Core::Managers::TextComponentManager::destroy_component(TextComponent* target_component) {
  std::vector<TextComponent*> tmp;

  for (auto* component : this->components) {
    if (target_component != component) {
      tmp.push_back(component);
    }
  }

  this->components = tmp;
  target_component->destroy();
}

void Core::Managers::TextComponentManager::destroy_components() {
  for (auto* component : this->components) {
    component->destroy();
  }

  this->components = {};
}

void Core::Managers::TextComponentManager::update_components() {
  for (auto* component : this->components) {
    component->update();
  }
}
