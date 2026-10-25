#include <GL/freeglut.h>

#include "graphics.h"

static void graphical_event_loop();

void graphics_start_loop()
{
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
