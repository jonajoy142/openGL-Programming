#include<GL/glut.h>
#include<stdio.h>

void init(void)
{
 glClearColor(1.0,1.0,1.0,1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0,300.0,0.0,300.0);
}

void lineSegment () {
 
 glClear(GL_COLOR_BUFFER_BIT);

 //house base
 glBegin(GL_POLYGON);
  glColor3f(0.4,0.0,0.2);
  glVertex2f(100,10);
  glVertex2f(200,10);
  glVertex2f(200,100);
  glVertex2f(100,100);
 glEnd();

 //house roof
 glBegin(GL_POLYGON);
  glColor3f(0.6,0.2,0.2);
  glVertex2f(100,100);
  glVertex2f(200,100);
  glVertex2f(150,200);
 glEnd();

 //house chimney
 glBegin(GL_POLYGON);
  glColor3f(0.4,0.4,0.3);
  glVertex2f(180,140);
  glVertex2f(185,130);
  glVertex2f(185,190);
  glVertex2f(180,190);
 glEnd();

 //house door
 glBegin(GL_POLYGON);
  glColor3f(1.0,1.0,1.0);
  glVertex2f(130,10);
  glVertex2f(160,10);
  glVertex2f(160,50);
  glVertex2f(130,50);
 glEnd();

 //house open
 glBegin(GL_POLYGON);
  
  glColor3f(0.6,0.2,0.2);
  glVertex2f(140,10);
  glVertex2f(160,10);
  glVertex2f(160,50);
  glVertex2f(140,40);
 glEnd();
  
 //house window
 glBegin(GL_POLYGON);
  
  glColor3f(0.4,0.1,0.4);
  glVertex2f(170,60);
  glVertex2f(190,60);
  glVertex2f(190,80);
  glVertex2f(170,80);
 glEnd();
 
 //house window
 glBegin(GL_LINES);
  
  glColor3f(1.0,1.0,1.0);
  glVertex2f(180,60);
  glVertex2f(180,80);
  glVertex2f(170,70);
  glVertex2f(190,70);
 glEnd();
 
 //tree base
 glBegin(GL_POLYGON);
  glColor3f(0.6,0.2,0.2);
  glVertex2f(230,10);
  glVertex2f(235,10);
  glVertex2f(235,90);
  glVertex2f(230,90);
 glEnd();

 //tree top1
 glBegin(GL_POLYGON);
  glColor3f(0.4,0.7,0.2);
  glVertex2f(225,90);
  glVertex2f(240,90);
  glVertex2f(233,110);
 glEnd();

 //tree top2
 glBegin(GL_POLYGON);
  glColor3f(0.4,0.7,0.2);
  glVertex2f(226,100);
  glVertex2f(239,100);
  glVertex2f(233,120);
 glEnd();

 //tree top3
 glBegin(GL_POLYGON);
  glColor3f(0.4,0.7,0.2);
  glVertex2f(227,110);
  glVertex2f(238,110);
  glVertex2f(233,130);
 glEnd();

 glFlush();
 
}

int main(int argc , char **argv)
{
 glutInit(&argc, argv);
 glutCreateWindow("An example of openGl program " );
 glutInitWindowSize(400,300);
 glutInitWindowPosition(300,300);
 init();
 glutDisplayFunc(lineSegment);
 glutMainLoop();
}