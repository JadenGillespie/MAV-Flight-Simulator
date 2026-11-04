#ifndef GRAPHICS_SHAPE_H_
#define GRAPHICS_SHAPE_H_

#include <stdbool.h>

typedef enum 
{
    CIRCLE = 0,
    NONE
} graphics_shape_type;

typedef struct vec2
{
    double x;
    double y;
} vec2_t;

typedef struct graphics_shape_info
{
    graphics_shape_type shape_type;
    union
    {
        struct {
            double radius;
        };
    };

} graphics_shape_info_t;

typedef struct graphics_shape
{
    graphics_shape_info_t shape_info;

    vec2_t position;
    vec2_t velocity;
    vec2_t acceleration;

    void (*render_shape)(const struct graphics_shape *shape);
} graphics_shape_t;


graphics_shape_t *graphics_shape_create(graphics_shape_info_t shape_info, vec2_t pos, vec2_t vel, vec2_t accel);

void graphics_shape_destroy(graphics_shape_t *shape);

#endif
