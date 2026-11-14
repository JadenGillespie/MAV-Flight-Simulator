#include "physics.h"
#include <fcntl.h>
#include <unistd.h>

#define ARR_LEN 30

static const double time_inc = 1.0 / 60.0; 
static const char *path_vel_true  = "./test/test_logs/velocity_true.dat"; //cwd is the MAV-Flight-Simulator repo
static const char *path_vel_ode = "./test/test_logs/velocity_ode.dat";
static const char *path_pos_true = "./test/test_logs/position_true.dat"; 
static const char *path_pos_ode = "./test/test_logs/position_ode.dat";


void test (void) {
//re-initialize values to 0 for all calls of the test function
    static double true_vy[ARR_LEN] = {0}; 
    static double approx_vy[ARR_LEN] = {0};
    static double true_py[ARR_LEN] = {0};
    static double approx_py[ARR_LEN] = {0};

    static vec2_t pos_true;
    static vec2_t vel_true; 
    static vec2_t accel_true; 

    static vec2_t pos_ode;
    static vec2_t vel_ode;  
    static vec2_t accel_ode; 

    static vec2_t prev_pos_ode;

    for(int i = 0; i < ARR_LEN; i++) { 

        true_vy [i] = vel_true.y;
        true_py [i] = pos_true.y;
        gravdrag (&pos_true, &vel_true, &accel_true, time_inc);

        approx_vy [i] = vel_ode.y;
        approx_py [i] = pos_ode.y; 
        gravdrag_ode (&pos_ode, &prev_pos_ode, &vel_ode, &accel_ode, time_inc);
    }

    int file_true_vel = open (path_vel_true, O_TRUNC | O_WRONLY, 0644);
    ssize_t write_true_vel = write (file_true_vel, true_vy, sizeof(true_vy)); 
    int cls_true_vel = close(file_true_vel);

    int file_ode_vel = open (path_vel_ode, O_TRUNC | O_WRONLY, 0644); //two seperate files for true and ODE approximations for more clear reading and writing
    ssize_t write_ode_vel = write (file_ode_vel, approx_vy, sizeof(approx_vy));
    int cls_ode_vel = close (file_ode_vel);

    int file_true_pos = open (path_pos_true, O_TRUNC | O_WRONLY, 0644);
    ssize_t write_true_pos = write (file_true_pos, true_py, sizeof(true_py)); 
    int cls_true_pos = close (file_true_pos); 

    int file_ode_pos = open (path_pos_ode, O_TRUNC | O_WRONLY, 0644);
    ssize_t write_ode_pos = write (file_ode_pos, approx_py, sizeof(approx_py)); 
    int cls_ode_pos = close (file_ode_pos); 
}
