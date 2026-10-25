#include <stdlib.h>
#include <stddef.h>

#include "graphics_shape.h"

typedef struct graphics_shape
{
    graphics_shape_type shape;

    int pos_x;
    int pos_y;

} graphics_shape_t;

graphics_shape_t *graphics_shape_create(graphics_shape_type shape, int initial_pos_x, int initial_pos_y)
{
    graphics_shape_t *new_shape = (graphics_shape_t *)malloc(sizeof(graphics_shape_t));

    if (!new_shape)
    {
        return NULL;
    }

    new_shape->shape = shape;
    new_shape->pos_x = initial_pos_x;
    new_shape->pos_y = initial_pos_y;

    return new_shape;
}


bool graphics_shape_update_pos(int new_pos_x, int new_pos_y, graphics_shape_t *shape)
{
    if (!shape)
    {
        return false;
    }

    // do bounds checks here
    shape->pos_x = new_pos_x;
    shape->pos_y = new_pos_y;

    return true;
}
