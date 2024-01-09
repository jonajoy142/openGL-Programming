//car

#include <GL/glut.h>

float carPosX = 0.0, carPosY = 0.0, carPosZ = 0.0;
float carSpeed = 0.05; // Uniform speed for movement
int direction = 0; // 0 for X, 1 for Y, 2 for Z
float moveDistance = 2.0; // Distance to move in each direction

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black and opaque
    glEnable(GL_DEPTH_TEST); // Enable depth testing for z-culling
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 100.0); // Perspective projection
    glMatrixMode(GL_MODELVIEW);
}

void drawCar() {
    glPushMatrix();
    glTranslatef(carPosX, carPosY, carPosZ);

    // Car body
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_QUADS);
    glVertex3f(-1.0, -0.5, 0.0);
    glVertex3f(-1.0, 0.5, 0.0);
    glVertex3f(1.0, 0.5, 0.0);
    glVertex3f(1.0, -0.5, 0.0);
    glEnd();

    // Wheels (white color)
    glColor3f(1.0, 1.0, 1.0); // White color
    glPushMatrix();
    glTranslatef(-0.7, -0.7, 0.0);
    glutSolidSphere(0.2, 20, 20); // Rear wheel
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7, -0.7, 0.0);
    glutSolidSphere(0.2, 20, 20); // Front wheel
    glPopMatrix();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glLoadIdentity(); // Reset transformations
    gluLookAt(0.0, 0.0, 5.0,  // Camera position
        0.0, 0.0, 0.0,  // Look at point
        0.0, 1.0, 0.0); // Up vector
    drawCar();
    glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)
}

void update(int value) {
    switch (direction) {
    case 0: // Move in X direction
        carPosX += carSpeed;
        if (carPosX >= moveDistance) direction = 1;
        break;
    case 1: // Move in Y direction
        carPosY += carSpeed;
        if (carPosY >= moveDistance) direction = 2;
        break;
    case 2: // Move in negative Z direction
        carPosZ -= carSpeed;
        if (carPosZ <= -moveDistance) direction = 3;
        break;
    case 3: // Reset to original position
        carPosX = carPosY = carPosZ = 0.0;
        direction = 0; // Start the cycle again
        break;
    }

    glutPostRedisplay();
    glutTimerFunc(30, update, 0); // Re-register the timer callback
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("OpenGL Car Movement");
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000 / 60, update, 0); // Register the timer callback
    glutMainLoop();
    return 0;
}