#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <math.h>
#include "graphics.h" 

//temporary macros to test functionality
#define GRAVITY 0
#define STOKES 1




//Not passing previous accel state, a0//
static void Gravity (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) ;

//Gravity and Drag are coupled and must be considered simaltenously. Only y dir considered
static void Stokes (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) ; 




void Update_Forces (vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 

    const vec2_t a0 = *acceleration ; 
    const vec2_t v0 = *velocity ; 
    const vec2_t p0 = *position ; 

    if (GRAVITY) { 
        Gravity (&p0, position, &v0, velocity, acceleration, time_inc) ;
    }
    
    elseif (STOKES) { 

        Stokes(&p0, position, &v0, velocity, acceleration, time_inc) ; 
    }

} 



static void Gravity (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 
   
    static const double g = 9.81 ; //defined temporarily to test functionality

    acceleration -> y = g ; 
    velocity -> y = g*time_inc + v0 -> y ; 
    position -> y = g*time_inc^2/2 + v0 -> y*time_inc + p0 -> y ; 

} 



static void Stokes (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 

    //defined temporarily to test functionality, metric SI units 

    static const dounle e = 2.71828 ;
    static const double g = 9.81 ; 
    static const double pi = 3.14159
    static const double visc = 1.48*10^(-4) ; 
    static const double dia = 2 ; 
    static const double mass = 10 ;

    static const double k = 3*pi*visc*dia/(g*mass) ; 
    static const double D = 2*k^(1/2)*g ; 

    static double v0_mag = ((v0->x)^2+(v0->y)^2)^(1/2) ; 
    static double E = (k^(-1/2)-v0_mag)/(k^(-1/2)+v0_mag) ; 

    
    velocity->y = k^(1/2)*(e^(D*time_inc)/E -1)/(1 + e^(D*time_inc)/E) ; 
    acceleration->y = g * (1 - (velocity->y)^2 * k) ; 
    position->y = p0->y + k^(1/2) * (log((E+e^(D*t))^2/(E+1)^2) * 1/D - t) ; 

}

#endif
