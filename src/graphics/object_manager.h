#ifndef OBJECT_MANAGER_H_
#define OBJECT_MANAGER_H_

#include <stdint.h>
#include "graphics_shape.h"

#define FOR_EACH_OBJECT_LINK(manager, iter) for (iter = manager->head; iter != NULL; iter = iter->next)

typedef struct object_link {
    graphics_shape_t *object;
    struct object_link *next;
} object_link_t;

typedef struct object_manager {
   object_link_t *head;
   object_link_t *tail;
   uint64_t len;
} object_manager_t;


object_manager_t *object_manager_init();

bool object_manager_add_object(graphics_shape_t *shape, object_manager_t *manager);

void object_manager_remove_object(object_link_t *obj, object_manager_t *manager);

#endif
