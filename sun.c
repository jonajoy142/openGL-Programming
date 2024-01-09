//earth

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

int a, b, speed=0, i;
const double PI=3.14159;

void circle(double r)
{
	float theta;
	glBegin(GL_LINE_LOOP);
	for(i=0;i<360;i++)
	{
		theta = i * PI/180;
		glVertex2f(r * cos(theta), r * sin(theta));
	}
	glEnd();
}
void c1()
{
	glColor3f(1.0,0.0,0.0);
	circle(0.5);
	glColor3f(0.0,0.0,0.0);
	circle(2);
}
void c2()
{
	glColor3f(0.0,0.3,0.0);
	circle(0.2);
}
void draw()
{
	glPushMatrix();
	glScalef(0.2,0.2,0.0);
	glTranslatef(15.0,8.0,0.0);
	c1();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.2,0.2,0.0);
	glTranslatef(15.0,8.0,0.0);
	glRotatef(speed * 4 , 0.0, 0.0, 1.0);
	glTranslatef(2.0,0.0,0.0);
	c2();
	glPopMatrix();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glutSwapBuffers();
}
void frame(int x)
{
	speed+=1;
	glutPostRedisplay();
	glutTimerFunc(30, frame, 0);
}
void init(void)
{
 glClearColor(1.0,1.0,1.0,1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0,7,-1,4);
 glMatrixMode(GL_MODELVIEW);
}
int main(int argc , char **argv)
{

 glutInit(&argc , argv);
 glutCreateWindow("An example of openGl program " );
 glutInitWindowSize(1600,1600);
 glutInitWindowPosition(300,300);
 init();
 glutDisplayFunc(display);
 glutTimerFunc(10, frame, 0);
 glutMainLoop();

 return 0;
}