#include <GL/freeglut.h>
#include <stdint.h>

#include "graphics.h"
#include "object_manager.h"

static object_manager_t *manager;

static void graphical_event_loop();

static void graphics_add_circle();

static void update_render();

void graphics_start_loop()
{
    manager = object_manager_init();

    if (!manager)
    {
        return;
    }

    graphics_add_circle();

    glutDisplayFunc(graphical_event_loop);

    glutMainLoop();
}


static void graphical_event_loop()
{
    glClear(GL_COLOR_BUFFER_BIT);

    update_render();

    glFlush();
}

static void update_render()
{
    object_link_t *obj_link;
    FOR_EACH_OBJECT_LINK(manager, obj_link)
    {
        obj_link->object->render_shape(obj_link->object);
    }
}

static void graphics_add_circle()
{
    graphics_shape_info_t shape_info = {
        .shape_type = CIRCLE,
        .num_segments = 100,
        .radius = 0.25
    };

    vec2_t pos, vel, accel;

    graphics_shape_t *shape = graphics_shape_create(shape_info, pos, vel, accel);
    
    object_manager_add_object(shape, manager);
}
