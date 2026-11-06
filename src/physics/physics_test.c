#include "physics.h"
#include <fcntl.h>
#include <unistd.h>

#define ARR_LEN 100 

static void write_results (void);
static void test (void);

static const double time_inc = 1.0 / 60.0; 
static const char *path  = "/MAV-Flight-Simulator/ARCHIVE/Testing_Log.txt";

static vec2_t posf_true;
static vec2_t posi_true; 
static vec2_t velf_true; 
static vec2_t veli_true; 
static vec2_t accel_true; 

static vec2_t posf_ode;
static vec2_t posi_ode; 
static vec2_t velf_ode; 
static vec2_t veli_ode; 
static vec2_t accel_ode; 

static double true_vy[ARR_LEN] = {0}; 
static double approx_vy[ARR_LEN] = {0};


void write_results (void) { 

    int file = open (path, O_TRUNC | O_WRONLY, 0644);

}

void test (void) {
 
    for(int i = 0; i < ARR_LEN; i++) { 

        true_vy [i] = velf_true.y;
        stokes_true (&posi_true, &posf_true, &veli_true, &velf_true, &accel_true, time_inc);

        approx_vy [i] = velf_ode.y;
        stokes_ode (&posi_ode, &posf_ode, &veli_ode, &velf_ode, &accel_ode, time_inc);
    }

}
