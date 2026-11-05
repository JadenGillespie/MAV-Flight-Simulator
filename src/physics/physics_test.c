#include "physics.h"
#include "graphics_shape.h"

#define ARR_LEN 100 

static const double refresh_rate = 60.0 ; 

static const double time_inc = 1 / refresh_rate ; 

static vec2_t posf;

static vec2_t posi; 

static vec2_t velf; 

static vec2_t veli; 

static vec2_t accel; 


static double true_y[ARR_LEN] = {0} ; 
static double approx_y[ARR_LEN] = {0} ;
 






