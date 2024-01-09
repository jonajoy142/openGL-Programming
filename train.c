// train animation

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int xp = 0, delay = 0;
int offset = 10;

int win_width = 800, win_height = 600;
int win_x = 100, win_y = 100;
float bg_color[3] = { 1.0, 1.0, 1.0 }; // white

void draw_train() {
    glClear(GL_COLOR_BUFFER_BIT);
    //Train head
    glColor3f(0.9, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(xp, 50);
    glVertex2i(xp + 200, 50);
    glVertex2i(xp + 200, 100);
    glVertex2i(xp + 130, 100);
    glVertex2i(xp + 130, 150);
    glVertex2i(xp, 150);
    glEnd();


    //Link1
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(xp, 80);
    glVertex2i(xp - 20, 80);
    glVertex2i(xp - 20, 100);
    glVertex2i(xp, 100);
    glEnd();

    //Bogie1
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(xp - 20, 50);
    glVertex2i(xp - 20, 150);
    glVertex2i(xp - 120, 150);
    glVertex2i(xp - 120, 50);
    glEnd();

    //Tracks
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(-1, 50);
    glVertex2i(850, 50);
    glVertex2i(-1, 30);
    glVertex2i(850, 30);
    glEnd();

    glFlush();

}

void update() {
    while (1) {
        delay++;
        if (delay > 500) {
            xp += offset;
            delay = 0;
        }
        if (xp > 500) {
            xp = 0;
            break;
        }
        glutPostRedisplay();
        glClear(GL_COLOR_BUFFER_BIT);
        draw_train();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(win_width, win_height);
    glutInitWindowPosition(win_x, win_y);

    glutCreateWindow("Line Transformation");

    glClearColor(bg_color[0], bg_color[1], bg_color[2], 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, win_width, 0, win_height);

    glutDisplayFunc(draw_train);
    glutDisplayFunc(update);
    glutMainLoop();
}