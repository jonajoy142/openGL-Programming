#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
void init() {
    glClearColor(0.0, 0.0, 0.1, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800, 0.0, 600);
}
float roundValue(int v) {
    return floor(v + 0.5);
}

double X1, Y1, X2, Y2;
float dx, dy, steps, xinc, yinc;

void ddaLine() {
    float x = X1, y = Y1, xinc, yinc;
    double dx, dy, steps;
    dx = X2 - X1;
    dy = Y2 - Y1;
    if (abs(dy) > abs(dx))
        steps = abs(dy);
    else
        steps = abs(dx);

    xinc = dx / steps;
    yinc = dy / steps;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    
    for (int i = 1; i <= steps; i++) {
        glVertex2d(roundValue(x), roundValue(y));
        x += xinc;
        y += yinc;
    }
    glEnd();
    glFlush();
}
int main() {
    X1 = 100;
    X2 = 300;
    Y1 = 100;
    Y2 = 300;

    glutInit(&__argc, __argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300, 200);
    glutInitWindowSize(800, 600);
    glutCreateWindow("DDA LINE");
    init();
    glutDisplayFunc(ddaLine);
    glutMainLoop();
}