
#include<GL/glut.h>
#include<stdio.h>


int x1, y1, x2, y2;
void bresah_algo()
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p0 = 2 * dy - dx;
    float x = x1, y = y1;
    int incx = 1, incy = 1;

    if (dx < 0)
    {
        incx = -1;
        dx = -dx;
    }
    if (dy < 0)
    {
        incy = -1;
        dy = -dy;
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    int p = p0;
    for (int k = 0;k < dx;k++)
    {
        if (p < 0)
        {
            x = x + incx;
            p = p + 2 * dy;

        }
        else
        {
            x = x + incx;
            y = y + incy;
            p = p + 2 * dy - 2 * dx;
        }
        glVertex2i(x, y);
    }
    glEnd();
    glFlush();
}
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

int main(int argc, char** argv)
{
    x2 = 100;
    y2 = 100;
    x1 = 200;
    y1 = 200;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("An example of openGl program ");
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(300, 300);
    init();
    glutDisplayFunc(bresah_algo);
    glutMainLoop();

    return 0;
}