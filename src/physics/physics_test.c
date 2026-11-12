#include "physics.h"
#include <fcntl.h>
#include <unistd.h>

#define ARR_LEN 35

static const double time_inc = 1.0 / 60.0; 
static const char *path_true  = "./test/test_logs/testing_true.dat"; //cwd is the MAV-Flight-Simulator repo
static const char *path_ode = "./test/test_logs/testing_ode.dat";


void test (void) {
//re-initialize values to 0 for all calls of the test function
    static double true_vy[ARR_LEN] = {0}; 
    static double approx_vy[ARR_LEN] = {0};

    static vec2_t pos_true;
    static vec2_t vel_true; 
    static vec2_t accel_true; 

    static vec2_t pos_ode;
    static vec2_t vel_ode;  
    static vec2_t accel_ode; 

    for(int i = 0; i < ARR_LEN; i++) { 

        true_vy [i] = vel_true.y;
        gravdrag (&pos_true, &vel_true, &accel_true, time_inc);

        approx_vy [i] = vel_ode.y;
        gravdrag_ode (&pos_ode, &vel_ode, &accel_ode, time_inc);
    }

    int file_true = open (path_true, O_TRUNC | O_WRONLY, 0644);
    ssize_t write_true = write (file_true, true_vy, sizeof(true_vy)); 
    int cls_true = close(file_true);

    int file_ode = open (path_ode, O_TRUNC | O_WRONLY, 0644); //two seperate files for true and ODE approximations for more clear reading and writing
    ssize_t write_ode = write (file_ode, approx_vy, sizeof(approx_vy));
    int cls_ode = close (file_ode);
}
