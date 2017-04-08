#include "pet.h"
#include "components/drawc.h"

Entity *new_pet(SDL_Renderer *r, enum PetTypes type) {
    Entity *ret = malloc(sizeof(Entity));
    ret->render = malloc(sizeof(Component));
    ret->components = new_component_hash();
    *ret->render = new_drawc(r, SS_CHARACTER, 4, 1, ch_get(position))
}
