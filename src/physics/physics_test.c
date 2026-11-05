#include "physics.c"

#define ARR_LEN 100 

static const double refresh_rate = 60.0 ; 

static const double time_inc = 1 / refresh_rate ; 

static vec2_t posf ;
posf.x = 0 ; 
posf.y = 0 ; 

static vec2_t posi ; 
posi.x = 0 ; 
posi.y = 0 ; 

static vec2_t velf ; 
velf.x = 0 ; 
velf.y = 0 ; 


static vec2_t veli ; 
veli.x = 0 ; 
veli.y = 0 ; 


static vec2_t accel ; 
accel.x = 0 ; 
accel.y = 0 ; 


static double true_y[ARR_LEN] = {0} ; 
static double approx_y[ARR_LEN] = {0} ;
 
for(i = 0; i < ARRLEN; i++) { 





