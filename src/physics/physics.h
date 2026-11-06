#ifndef PHYSICS_H_
#define PHYSICS_H_

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES 
#endif


#include <math.h>
#include "graphics_shape.h"


//temporary macros to test functionality
#define GRAVITY 0
#define STOKES 1


//useful constants 
#define g 9.81 


//temporarily defined for testing
#define dynam_visc 1.48e-4 
#define dia 2.0 
#define mass 10.0 


void update_forces (vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc);

//Gravity and Drag are coupled and must be considered simaltenously. Only y dir considered
static void gravity (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc); 


static void stokes (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc);


static void ode (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc);
#endif


