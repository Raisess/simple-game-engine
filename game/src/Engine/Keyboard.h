#pragma once

#include <SDL2/SDL.h>

namespace Engine {

class Keyboard {
  public:
    static const Uint8* key() {
      return SDL_GetKeyboardState(NULL);
    }
};

}
