#include "world.h"
#include "circle.h"

static Circle circle_array[256];
static int i;
/*
void world_apply_gravity(void){
    for(uint8_t i = 0; i != 255; i++){
        circle_array[i].acc.y = circle_array[i].force.y / circle_array[i].mass;
    }
}
*/

void world_add_circle(Circle c){
    if(i >= 255) i = 255;

    // add gravity to force while instancing
    // all other forces will be added to gravity base
    c.force.y = WORLD_GRAVITY;
    circle_array[i++] = c;
}

void world_update(void){
    for(uint8_t j = 0; j < i; j++){
        update_circle(&circle_array[j]);
    }
}