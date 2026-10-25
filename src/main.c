#include <GL/freeglut.h>

#include "graphics.h"

#define WIDTH_PX 1000
#define LENGTH_PX 750
#define WINDOW_NAME "Jaden's Window"


int main(int argc, char **argv)
{
    const char* name = "Jaden's Window";

    graphics_init_window(WIDTH_PX, LENGTH_PX, name, &argc, argv);

    graphics_start_loop();

    return 0;
}
