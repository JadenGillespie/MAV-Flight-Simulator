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
#define e 2.718281828459045
#define pi 3.1415926535897932


//temporarily defined for testing
#define dynam_visc 1.48e-4 
#define dia 2.0 
#define mass 10.0 

void update_forces (vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc);

#endif


