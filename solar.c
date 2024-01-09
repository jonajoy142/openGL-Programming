#include<GL/glut.h>
#include<math.h>


void init() {

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 600);
}

float speed = 0;

void circle(float radius) {
    float theta = 0;
    glBegin(GL_LINE_LOOP);
    for (int i = 0;i < 360;i++) {
        theta = (3.1415 / 180) * i;
        float a = radius * cos(theta);
        float b = radius * sin(theta);
        glVertex2f(a, b);
    }
    glEnd();


}

void c1() {
    glColor3f(1.0, 0.0, 0.0);
    circle(0.5);
    glColor3f(0.0, 0.0, 0.0);
    circle(2.0);
    glColor3f(0.0, 0.0, 0.0);
    circle(4.0);

    glColor3f(0.0, 0.0, 0.0);
    circle(6.0);

}

void c2() {
    glColor3f(0.0, 0.0, 1.0);
    circle(0.2);
}
void c3() {
    glColor3f(1.0, 0.0, 0.0);
    circle(0.2);
}

void earth() {
    glPushMatrix();
    glScalef(0.2, 0.2, 0.0);
    c1();
    glPopMatrix();

    glPushMatrix();

    glScalef(0.2, 0.2, 0.0);
    glRotatef(speed * 4, 0.0, 0.0, 1.0);
    glTranslatef(2.0, 0.0, 0.0);
    c2();
    glPopMatrix();
    glPushMatrix();

    glScalef(0.2, 0.2, 0.0);
    glRotatef(speed * 4, 0.0, 0.0, 1.0);
    glTranslatef(4.0, 0.0, 0.0);
    c3();
    glPopMatrix();

    glPushMatrix();

    glScalef(0.2, 0.2, 0.0);
    glRotatef(speed * 4, 0.0, 0.0, 1.0);
    glTranslatef(6.0, 0.0, 0.0);
    c3();
    glPopMatrix();




}

void frame(int x)
{
    speed += 1;
    glutPostRedisplay();
    glutTimerFunc(30, frame, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
    earth();
    glFlush();
    // glutSwapBuffers();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("earth");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, frame, 0);
    glutMainLoop();
    return 0;
}