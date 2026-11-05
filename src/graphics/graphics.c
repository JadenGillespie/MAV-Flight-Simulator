#include <GL/freeglut.h>
#include <stdint.h>

#include "graphics.h"
#include "object_manager.h"

static object_manager_t *manager;

static void graphical_event_loop();

static void update_render();

void graphics_start_loop()
{
    manager = object_manager_init();

    if (!manager)
    {
        return;
    }

    glutDisplayFunc(graphical_event_loop);

    glutMainLoop();
}


static void graphical_event_loop()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    glEnd();
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
