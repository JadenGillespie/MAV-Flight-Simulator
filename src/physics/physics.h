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
    
    else if (STOKES) { 

        Stokes(&p0, position, &v0, velocity, acceleration, time_inc) ; 
    }

} 



static void Gravity (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 
   
    static const double g = 9.81 ; //defined temporarily to test functionality

    acceleration -> y = g ; 
    velocity -> y = g*time_inc + v0 -> y ; 
    position -> y = g * pow(time_inc,2)/2 + v0 -> y*time_inc + p0 -> y ; 

} 



static void Stokes (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 

    //defined temporarily to test functionality, metric SI units 
    static const double e = 2.71828 ;
    static const double g = 9.81 ; 
    static const double pi = 3.14159 ;
    static const double visc = 1.48 * pow(10,-4) ; 
    static const double dia = 2.0 ; 
    static const double mass = 10.0 ;

    static const double k = 3.0*pi*visc*dia/(g*mass) ; 
    static const double D = 2.0*pow(k,1.0/2.0)*g ; 

    double v0_mag = pow((pow(v0->x,2) + pow(v0->y,2)),1.0/2.0) ; 
    double E = (pow(k,-1.0/2.0)-v0_mag)/(pow(k,-1.0/2.0)+v0_mag) ; 

    
    velocity->y = pow(k,1.0/2.0)*(pow(e,(D*time_inc))/E -1)/(1 + pow(e,(D*time_inc))/E) ; 
    acceleration->y = g * (1 - pow(velocity->y,2) * k) ; 
    position->y = p0->y + pow(k,1.0/2.0) * (log(pow(E+(pow(e,(D*t)),2)/pow(E+1,2) * 1/D - t) ; 

}

#endif
