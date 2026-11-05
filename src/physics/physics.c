#include "physics.h"



void update_forces(vec2_t *position, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 

    const vec2_t a0 = *acceleration; 
    const vec2_t v0 = *velocity; 
    const vec2_t p0 = *position; 

    if (GRAVITY) { 
        gravity(&p0, position, &v0, velocity, acceleration, time_inc);
    }
    
    if (STOKES) { 

        stokes(&p0, position, &v0, velocity, acceleration, time_inc); 
    }

}

static void gravity(const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 
   
    static const double g = 9.81; //defined temporarily to test functionality

    acceleration -> y = g; 
    velocity -> y = g*time_inc + v0 -> y; 
    position -> y = g * pow(time_inc,2)/2 + v0 -> y*time_inc + p0 -> y; 

} 



static void stokes(const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) { 


    static const double k = 3.0*pi*dynam_visc*dia/(g*mass); 
    const double D = 2.0*pow(k,1.0/2.0)*g; 

    double v0_mag = pow((pow(v0->x,2) + pow(v0->y,2)),1.0/2.0); 
    double E = (pow(k,-1.0/2.0)-v0_mag)/(pow(k,-1.0/2.0)+v0_mag); 

    
    velocity->y = pow(k,1.0/2.0)*(pow(e,(D*time_inc))/E -1)/(1 + pow(e,(D*time_inc))/E); 
    acceleration->y = g * (1 - pow(velocity->y,2) * k); 
    position->y = p0->y + pow(k, 1.0/2.0) * (log(pow(E + pow(e, D * time_inc), 2) / pow(E + 1, 2)) * (1.0 / D) - time_inc);

}



static void ode (const vec2_t *p0, vec2_t *position, const vec2_t *v0, vec2_t *velocity, vec2_t *acceleration, const double time_inc) {

}