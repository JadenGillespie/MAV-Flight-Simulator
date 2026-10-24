#include <stdio.h>
#include <GL/freeglut.h>

static void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowSize(1000, 750);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Sigma Window");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
