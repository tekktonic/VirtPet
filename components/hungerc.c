#include "hungerc.h"
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "../entity.h"

typedef struct Hunger {
    int satiation;
    double hungryChance;
    double healChance;
    Component draw;
    int ticks;
} Hunger;

static void cleanup(struct Component *self) {
    free(self->data);
}

static void update(struct Component *self, struct Entity *e, int dt) {
    Hunger *h = self->data;
    
    h->ticks += dt;
    

    
    if (h->ticks > 180) {
        double hungerRoll = ((double)random())/RAND_MAX;
        if (hungerRoll < h->hungryChance) {
            h->satiation--;
            h->hungryChance = 0.125;
        }
        else {
            h->hungryChance *= 2;
        }
        h->ticks = 0;
    }

    if (h->satiation >= 5) {
        double healRoll = ((double)random())/RAND_MAX;

        if (healRoll < h->healChance) {
            Component *health;
            if ((health = ch_get(e->components, "health"))) {
                health->receive()
            }
        }
    }
};

Component new_hungerc(SDL_Renderer *r, int factor) {
    Component ret = {.cleanup = cleanup, .update = update};


    return ret;
}
