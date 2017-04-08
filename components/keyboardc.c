#include "keyboardc.h"
#include "../entity.h"
#include <SDL2/SDL.h>

static void update(Component *self, Entity *e, int dt) {
    static Uint8 *keyboard[256];
    keyboard = SDL_GetKeyboardState(NULL);

    if (keyboard[SDLK_UP]) {
        
    }
}

Component new_keyboardc(int speed) {
    Component ret = {.update = update};
    ret.data = (void*)speed;
}
