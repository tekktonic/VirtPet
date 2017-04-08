#ifndef POSITIONC_H
#define POSITIONC_H

#include "../component.h"

typedef enum {
    POSITIONC_MOVE,
    POSITIONC_MOVE_REL
} PositionCEvents;

typedef enum {
    POSITIONC_RECT,
    POSITIONC_CENTER,
} PositionCInspects;

Component new_positionc(int x, int y, int w, int h);
#endif
