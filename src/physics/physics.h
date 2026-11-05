#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <math.h>
#include "graphics_shape.h"

//temporary macros to test functionality
#define GRAVITY 0
#define STOKES 1

void update_forces (vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc);


static void gravity(const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc); 


static void stokes(const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc);

#endif


