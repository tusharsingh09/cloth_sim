#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>
#include <stdint.h>

#include "circle.h"

#define WORLD_GRAVITY 0.98

typedef enum {
    WORLD_SPHERE = 0,
    WORLD_JOINTS
} WORLD_TYPE;

void world_add_circle(Circle c);

void world_update(void);

void world_draw(SDL_Renderer *m_render);

#endif // WORLD_H