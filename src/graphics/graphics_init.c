#include <GL/freeglut.h>

#include "graphics_init.h"


int graphics_init_window(int width, int height, const char *name, int *argc, char **argv)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);

    glutCreateWindow(name);

    return 0;
}
