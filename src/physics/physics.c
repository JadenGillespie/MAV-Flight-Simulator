#include "physics.h"


void update_forces(vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 

    const vec2_t a0 = *acceleration; 
    const vec2_t v0 = *velocity; 
    const vec2_t p0 = *position; 

    if (GRAVITY) { 
        gravity (&p0, position, &v0, velocity, acceleration, time_inc);
    }
    
    if (STOKES) { 

        stokes_true (&p0, position, &v0, velocity, acceleration, time_inc); 
    }

}



void gravity(const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 

    acceleration -> y = g; 
    velocity -> y = g * time_inc + v0 -> y; 
    position -> y = g * pow(time_inc,2) / 2 + v0 -> y * time_inc + p0 -> y; 

} 



void stokes_true(const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 


    static const double k = 3.0 * pi * dynam_visc * dia / (g * mass); 
    const double D = 2.0 * sqrt(k) * g; 

    double v0_mag = sqrt(pow(v0->x,2) + pow(v0->y,2)); 
    double E = (1/sqrt(k) - v0_mag) / (sqrt(k) + v0_mag); 

    
    velocity -> y = pow(k,0.5) * (exp(D * time_inc) / E - 1.0)/(1.0 + exp(D * time_inc) / E ); 
    acceleration -> y = g * (1 - pow(velocity -> y,2) * k); 
    position -> y = p0->y + sqrt(k) * (log(pow(E + exp(D * time_inc), 2) / pow(E + 1.0, 2)) * (1.0 / D) - time_inc);

}



void stokes_ode (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) {

    static const float c = 3 * pi * dynam_visc * dia / mass; 

    velocity -> y = (-1.0 + sqrt(1 + 16 * g * pow(time_inc,2) * c + 8 * time_inc * c * v0 -> y)) / (4 * time_inc * c); 
}