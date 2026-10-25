#ifndef OBJECT_MANAGER_H_
#define OBJECT_MANAGER_H_

#include <stdint.h>
#include "graphics_shape.h"

typedef struct object_link {
    graphics_shape_t *object;
    struct object_link *next;
} object_link_t;

typedef struct object_manager {
   object_link_t *head;
   object_link_t *tail;
   uint64_t len;
} object_manager_t;


bool object_manager_add_object(graphics_shape_type shape, vec2_t pos, vec2_t vel, vec2_t accel, object_manager_t *manager);

bool object_manager_add_object(graphics_shape_type shape, vec2_t pos, vec2_t vel, vec2_t accel, object_manager_t *manager);

void object_manager_remove_object();

#endif
