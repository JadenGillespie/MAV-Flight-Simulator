#include <stdlib.h>
#include <stddef.h>

#include "graphics_shape.h"

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
    // empty signature for now
    return;
}
