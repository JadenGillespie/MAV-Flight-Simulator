#include <stdio.h>
#include <GL/freeglut.h>

int main()
{
    glutInit(NULL, NULL);
    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowSize(1000, 750);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Sigma Window");
    glutMainLoop();
    return 0;
}
