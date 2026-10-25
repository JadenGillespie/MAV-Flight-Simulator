#ifndef GRAPHICS_SHAPE_H_
#define GRAPHICS_SHAPE_H_

#include <stdbool.h>

typedef enum 
{
    CIRCLE = 0,
    NONE
} graphics_shape_type;

struct graphics_shape;
typedef struct graphics_shape graphics_shape_t;

graphics_shape_t *graphics_shape_create(graphics_shape_type shape, int initial_pos_x, int initial_pos_y);

bool graphics_shape_update_pos(int new_pos_x, int new_pos_y, graphics_shape_t *shape);

#endif
