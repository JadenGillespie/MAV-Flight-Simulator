#include <stddef.h>
#include <stdlib.h>

#include "object_manager.h"

static object_link_t *object_link_create();
static void object_link_destroy(object_link_t *object_link);

static bool manager_push_back(object_manager_t *manager, object_link_t *link);

object_manager_t *object_manager_init()
{
    object_manager_t *manager = (object_manager_t *) malloc(sizeof(object_manager_t));

    if (!manager)
    {
        return NULL;
    }

    manager->head = NULL;
    manager->len = 0;

    return manager;
}

bool object_manager_add_object(graphics_shape_type shape, vec2_t pos, vec2_t vel, vec2_t accel, object_manager_t *manager)
{
    graphics_shape_t *new_shape = graphics_shape_create(shape, pos, vel, accel);

    if (!new_shape)
    {
        return false;
    }

    object_link_t *new_link = object_link_create();

    if (!new_link)
    {
        graphics_shape_destroy(new_shape);
        return false;
    }

    new_link->object = new_shape;

    return manager_push_back(manager, new_link);
}

void object_manager_remove_object(object_link_t *obj, object_manager_t *manager)
{
    if (!obj || !manager)
    {
        return;
    }

    object_link_t *prev_obj = NULL;

    for (object_link_t *cur_obj = manager->head; cur_obj != NULL; cur_obj = cur_obj->next)
    {
        if (cur_obj == obj && !prev_obj) // cur_obj == manager->head
        {
            manager->head = cur_obj->next;
            obj->next = NULL;
            manager->len--;
            return;
        }

        if (cur_obj->next == obj)
        {
            cur_obj->next = obj->next;
            obj->next = NULL;
            manager->len--;
            return;
        }
    }
}


static object_link_t *object_link_create()
{
    return (object_link_t *)malloc(sizeof(object_link_t));
}

static void object_link_destroy(object_link_t *object_link)
{
    if (!object_link)
    {
        return;
    }

    free(object_link);
}

static bool manager_push_back(object_manager_t *manager, object_link_t *link)
{
    if (!manager || !link)
    {
        return false;
    }

    if (manager->len == 0)
    {
        manager->head = link;
        manager->tail = link;
    }
    else
    {
        manager->tail->next = link;
        manager->tail = link;
    }

    manager->len++;

    return true;
}
