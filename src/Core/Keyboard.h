#pragma once

#include <SDL2/SDL.h>

namespace Core {

class Keyboard {
  public:
    static const Uint8* key() {
      return SDL_GetKeyboardState(NULL);
    }
};

}
