#include "physics.h"
#include <fcntl.h>
#include <unistd.h>

#define ARR_LEN 100 

static const double time_inc = 1.0 / 60.0; 
static const char *path  = "/MAV-Flight-Simulator/test/Testing_Log.txt"; 


void test (void) {
//re-initialize values to 0 for all calls of the test function
    static double true_vy[ARR_LEN] = {0}; 
    static double approx_vy[ARR_LEN] = {0};

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

    for(int i = 0; i < ARR_LEN; i++) { 

        true_vy [i] = velf_true.y;
        stokes_true (&posi_true, &posf_true, &veli_true, &velf_true, &accel_true, time_inc);

        approx_vy [i] = velf_ode.y;
        stokes_ode (&posi_ode, &posf_ode, &veli_ode, &velf_ode, &accel_ode, time_inc);
    }

    int file = open (path, O_TRUNC | O_WRONLY, 0644);
    ssize_t write_true = write (file, true_vy, sizeof(true_vy)); 
    ssize_t write_ode = write (file, approx_vy, sizeof(approx_vy));
    int cls = close (file);
}
