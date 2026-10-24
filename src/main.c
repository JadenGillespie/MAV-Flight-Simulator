#include <stdio.h>
#include <GL/freeglut.h>

#include "graphics.h"

#define WIDTH_PX 1000
#define LENGTH_PX 750
#define WINDOW_NAME "Jaden's Window"

static void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    const char* name = "Jaden's Window";

    graphics_init_window(WIDTH_PX, LENGTH_PX, name, &argc, argv);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
