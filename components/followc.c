#include <SDL2/SDL.h>
#include "followc.h"
#include "positionc.h"
#include "../util.h"
#include "../entity.h"

typedef struct  {
    int speed;
    int distance;
    Component *following;
}Follow;

void update(Component *self, Entity *e, int dt) {
    Follow *s = (Follow*)self->data;
    SDL_Rect *target = s->following->inspect(s->following, POSITIONC_CENTER);
    Component *position = ch_get(e->components, "position");
    SDL_Rect *self_pos = position->inspect(position, POSITIONC_CENTER);
    int dist = distance(self_pos->x, self_pos->y, target->x, target->y);

    if (dist > s->distance) {
        double angle = atan2(target->y - self_pos->y, target->x - self_pos->x);
        int rel_x = (int)(cos(angle) * s->speed);
        int rel_y = (int)(sin(angle) * s->speed);
        SDL_Rect arg = {.x = rel_x, .y = rel_y};
        Event e = {.t = POSITIONC_MOVE_REL, .d.data = &arg};
        position->receive(position, e);
    }

    free(self_pos);    
    free(target);    

}
