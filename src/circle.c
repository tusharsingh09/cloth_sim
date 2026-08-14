#include "circle.h"

#include <stdio.h>

extern double d_time;

void update_circle(Circle *c){
    c->acc.x += c->force.x / c->mass;
    c->acc.y += c->force.y / c->mass;

    c->velocity.x += c->acc.x * d_time;
    c->velocity.y += c->acc.y * d_time;

    c->position.x += c->velocity.x * d_time;
    c->position.y += c->velocity.y * d_time;

    printf("Pos: (%.5f, %.5f)\n", c->position.x, c->position.y);
}

Circle create_circle(Vector2 pos, float mass){
    Circle c = (Circle){
        pos,
        (Vector2){0, 0},
        (Vector2){0, 0},
        (Vector2){0, 0},
        mass,
        4.0
    };
    return c;
}

void draw_circle(Circle *c, SDL_Renderer *m_render){
    SDL_FRect r = (SDL_FRect){
        c->position.x - c->radius/2.0,
        c->position.y - c->radius/2.0,
        c->radius,
        c->radius
    };
    printf("%f\n", c->radius);
    SDL_SetRenderDrawColor(m_render, 255, 0, 0, 255);
    SDL_RenderFillRect(m_render, &r);
}