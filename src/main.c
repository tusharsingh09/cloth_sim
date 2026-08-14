#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "SDL3/SDL.h"

#include "world.h"
#include "circle.h"
#include "vec.h"

double d_time;

static SDL_Window *m_window;
static SDL_Renderer *m_render;
static uint8_t m_running;
static SDL_Event m_event;

static void input_loop(void);
static void run(void);

static uint8_t init_window(void){
    if(!SDL_Init(SDL_INIT_VIDEO)){
        puts("Error Init Window\n");
        exit(EXIT_FAILURE);
    } else puts("Init Window Success\n");
    m_window = SDL_CreateWindow("Cloth Sim", 800, 600, SDL_WINDOW_ALWAYS_ON_TOP);
    m_render = SDL_CreateRenderer(m_window, "opengl");

    m_running = 1;
}

static void run(void){
    input_loop();
    world_update();
    SDL_RenderClear(m_render);
    SDL_RenderPresent(m_render);
}

static void input_loop(void){
    while(SDL_PollEvent(&m_event)){
        if(m_event.type == SDL_EVENT_QUIT) m_running = false;
        if(m_event.type == SDL_EVENT_KEY_DOWN){
            switch(m_event.key.scancode){
                case SDL_SCANCODE_ESCAPE:
                    m_running = 0;
                    break;
                default: 
                    break;
            }
        }
    }
}

int main(int argc, char **argv){
    init_window();

    Circle c = {
        (Vector2){0, 0},
        (Vector2){0, 0},
        (Vector2){0, 0},
        (Vector2){0, 0},

        1.0,
        1.0
    };

    world_add_circle(c);

    while(m_running){
        uint64_t temp_t = SDL_GetTicks();
        run();
        d_time = ((double)((SDL_GetTicks() - temp_t))) / 1000.0;
    }
    SDL_Quit();
    return 0;
}