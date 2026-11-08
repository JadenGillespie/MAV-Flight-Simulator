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

//Gravity and Drag are coupled and must be considered simaltenously. Only y dir considered
void gravity (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc); 
void stokes_true (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc);
void stokes_ode (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc);
//temporarily not delcared as static as to test the fucntions directly in physics_test.c

void update_forces (vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc);
void test (void); 

#endif


