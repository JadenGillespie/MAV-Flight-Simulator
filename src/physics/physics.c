#include "physics.h"


void update_forces(vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 

    const vec2_t a0 = *acceleration; 
    const vec2_t v0 = *velocity; 
    const vec2_t p0 = *position; 

}

//stopped passing v0, p0 initial conditions for efficiency. Will require a intialzer funciton for position and velocity

void gravdrag (vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 


    static const double k = Cd * density * area_frontal / (2.0 * mass); 
    double boundary_cond = 1.0 / (2.0 * sqrt(g * k) ) * log( (sqrt(g) + sqrt(k) * velocity -> y) / (sqrt(g) - sqrt(k) * velocity -> y) ) ;
    double time_function = exp(2.0 * sqrt(g * k) * (time_inc + boundary_cond) ); 

    velocity -> y = (time_function - 1.0) / (time_function + 1.0) * sqrt(g/k);
    // considering only velocity in downward direction for testing
}



void gravdrag_ode (vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc) {

    static const double k = Cd * density * area_frontal / (2.0 * mass); //temporarily defined twice for testing

    velocity -> y = (-1.0 + sqrt( 1.0 + 4.0 * k * time_inc * (time_inc * g + velocity -> y) ) ) / (2.0 * k * time_inc); 
}
