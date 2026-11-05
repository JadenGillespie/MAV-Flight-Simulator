#include <stdlib.h>
#include <stddef.h>
#include <GL/glut.h>
#include <math.h>

#include "graphics_shape.h"

#ifndef M_PI
#define M_PI 3.141592653
#endif

static void render_circle(const graphics_shape_t *shape);

graphics_shape_t *graphics_shape_create(graphics_shape_info_t shape_info, vec2_t pos, vec2_t vel, vec2_t accel)
{
    graphics_shape_t *new_shape = (graphics_shape_t *) malloc(sizeof(graphics_shape_t));

    if (!new_shape)
    {
        return NULL;
    }

    switch (shape_info.shape_type)
    {
        case(CIRCLE):
        {
            new_shape->render_shape = render_circle;
            break;
        }

        case(NONE):
        {
            free(new_shape);
            return NULL;
        }

    }
    new_shape->shape_info = shape_info;
    new_shape->position = pos;
    new_shape->velocity = vel;
    new_shape->acceleration = accel;

    return new_shape;
}


void graphics_shape_destroy(graphics_shape_t *shape)
{
    free(shape);
}

static void render_circle(const graphics_shape_t *shape)
{
    if (!shape)
    {
        return;
    }

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(shape->position.x, shape->position.y);

    uint16_t segments_to_render = (shape->shape_info.num_segments < 3) ? 3 : shape->shape_info.num_segments;

    for (int i = 0; i < shape->shape_info.num_segments; i++)
    {
        float angle = 2.0F * M_PI * (float)i / (float)(shape->shape_info.num_segments);

        float vx = shape->position.x + (shape->shape_info.radius * cosf(angle));
        float vy = shape->position.y + (shape->shape_info.radius * sinf(angle));

        glVertex2f(vx, vy);
    }
    
    glEnd();

    return;
}
