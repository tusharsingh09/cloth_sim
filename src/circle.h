#ifndef CIRCLE_H
#define CIRCLE_H

#include "SDL3/SDL.h"
#include "vec.h"

typedef struct {
    Vector2 position;
    Vector2 velocity;
    Vector2 force;
    Vector2 acc;

    float mass;
    float radius;
} Circle;

Circle create_circle(Vector2 pos, float mass);
void draw_circle(Circle *c, SDL_Renderer *m_render);
void update_circle(Circle *c);

#endif // CIRCLE_H