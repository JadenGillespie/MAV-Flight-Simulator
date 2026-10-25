#ifndef PHYSICS_H_
#define PHYSICS_H_

#include "graphics.h" 
#define GRAVITY 1


//Not passing previous accel state, a0//
static void Gravity (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) ;




void Update_Forces (vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 

    const vec2_t a0 = *acceleration ; 
    const vec2_t v0 = *velocity ; 
    const vec2_t p0 = *position ; 

    if (GRAVITY) { 
        Gravity (&p0, position, &v0, velocity, acceleration, time_inc) ;
    }
        
} 



static void Gravity (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 
   
    static const double g = 9.81 ; 

    acceleration -> y = g ; 
    velocity -> y = g*time_inc + v0 -> y ; 
    position -> y = g*time_inc^2/2 + v0 -> y*time_inc + p0 -> y ; 
} 


#endif
