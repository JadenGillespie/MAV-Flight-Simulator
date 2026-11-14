#include "physics.h"


void update_forces(vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 

    const vec2_t a0 = *acceleration; 
    const vec2_t v0 = *velocity; 
    const vec2_t p0 = *position; 

}

//stopped passing v0, p0 initial conditions for efficiency. Will require a intialzer funciton for position and velocity

void gravdrag (vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 

    static const double k = Cd * density * area_frontal / (2.0 * mass); 
    double boundary_vel = 1.0 / (2.0 * sqrt (g * k) ) * log ( (sqrt(g) + sqrt(k) * velocity -> y) / (sqrt(g) - sqrt(k) * velocity -> y) ) ;
    double time_function = exp(2.0 * sqrt(g * k) * (time_inc + boundary_vel) ); 
    double boundary_pos = position -> y - 1 / k * log (exp (2 * sqrt (g * k) * boundary_vel) + 1); 

    velocity -> y = (time_function - 1.0) / (time_function + 1.0) * sqrt(g/k);
    // considering only velocity in downward direction for testing

    position -> y = 1 / k * log (time_function + 1) - time_inc * sqrt (g / k) + boundary_pos;
    // considering only position in downward direction for testing
}


void gravdrag_ode (vec2_t *position, vec2_t *prev_position, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { //to evaluate position will require the previous position state as well as the current

    static const double k = Cd * density * area_frontal / (2.0 * mass); //temporarily defined twice for testing, will want this to be local only to the function

    velocity -> y = (-1.0 + sqrt( 1.0 + 4.0 * k * time_inc * (time_inc * g + velocity -> y) ) ) / (2.0 * k * time_inc); 
    // considering only y-dir for testing purposes 

    double prev_position_buffer_y = position -> y; //store current postion to used for next iters previous posotion state
    position -> y = (-1.0 * (2.0 * position -> y + 1.0 / k) + sqrt( pow(2.0 * position -> y + 1 / k, 2.0) + 4 / k * (g * pow(time_inc, 2.0) + 2 * position -> y - prev_position -> y + k * pow(position -> y, 2.0) ) ) ) / 2.0;
    prev_position -> y = prev_position_buffer_y; //modify previous position now that is has been used
    // considering only y-dir for testing purposes


}
