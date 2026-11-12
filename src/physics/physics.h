#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <math.h>
#include "graphics_shape.h"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES 
#endif


//useful constants 
#define g 9.81 
#define e M_E
#define pi M_PI


//temporarily defined for testing
#define density 800
#define Cd 0.5
#define mass 10.0 
#define area_frontal 0.3

//Gravity and Drag are coupled and must be considered simaltenously. Only y dir considered
void gravdrag (vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc);
void gravdrag_ode (vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc);
//temporarily not delcared as static as to test the fucntions directly in physics_test.c

void update_forces (vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc);
void test (void); 

#endif


