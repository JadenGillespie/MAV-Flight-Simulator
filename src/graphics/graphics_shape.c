#include <stdlib.h>
#include <stddef.h>

#include "graphics_shape.h"


graphics_shape_t *graphics_shape_create(graphics_shape_type shape, vec2_t pos, vec2_t vel, vec2_t accel)
{
    graphics_shape_t *new_shape = (graphics_shape_t *) malloc(sizeof(graphics_shape_t));

    if (!new_shape)
    {
        return NULL;
    }

    new_shape->shape = shape;
    new_shape->position = pos;
    new_shape->acceleration = accel;

    return new_shape;
}
