#include "physics.h"

#define ARR_LEN 100 

static double time_inc = 1.0 / 60.0 ; 

static vec2_t posf_true;

static vec2_t posi_true; 

static vec2_t velf_true; 

static vec2_t veli_true; 

static vec2_t accel_true; 


static double true_vy[ARR_LEN] = {0} ; 
static double approx_vy[ARR_LEN] = {0} ;

void test (void) {
 
    for(int i = 0; i < ARR_LEN; i++) { 

        true_vy [i] = veli_true.y ; 
        stokes(&posi_true, &posf_true, &veli_true, &velf_true, &accel_true, time_inc) ; 
    }
}




