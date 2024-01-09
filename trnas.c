#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int n=2,x[10],y[10],y_shift,x_shift,x_scale,y_scale,cX=0, cY=0,x_shear,y_shear,choice;
double theta;

void init(void)
{
 glClearColor(0.0,0.0,0.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-450.0,450.0,-450.0,450.0);
}

void polygonTranslate () {
 
 glClear(GL_COLOR_BUFFER_BIT);

 glBegin(GL_LINES);
  glColor3f(0.4,0.7,0.2);
  glPointSize(0.2);
  for(int i=0;i<n;i++)
  	glVertex2f(x[i],y[i]);
 glEnd();

 glBegin(GL_LINES);
  glColor3f(1.0,0.0,0.0);
  glPointSize(0.2);
  for(int i=0;i<n;i++)
  	glVertex2f(x[i]+x_shift,y[i]+y_shift);
 glEnd();


 glFlush();
 
}

void polygonScale () {
 
 glClear(GL_COLOR_BUFFER_BIT);

 glBegin(GL_LINES);
  glColor3f(0.4,0.7,0.2);
  glPointSize(0.2);
  for(int i=0;i<n;i++)
  	glVertex2f(x[i],y[i]);
 glEnd();

 glBegin(GL_LINES);
  glColor3f(1.0,0.0,0.0);
  glPointSize(0.2);
  for(int i=0;i<n;i++)
  	glVertex2f(x[i]*x_scale,y[i]*y_scale);
 glEnd();


 glFlush();
 
}

void polygonRotate () {
 
 glClear(GL_COLOR_BUFFER_BIT);

 glBegin(GL_LINES);
  glColor3f(0.4,0.7,0.2);
  glPointSize(0.2);
  for(int i=0;i<n;i++)
  	glVertex2f(x[i],y[i]);
 glEnd();
 
 glPushMatrix();
 glRotatef(theta, 0.0f, 0.0f, 1.0f);

 glBegin(GL_LINES);
  glColor3f(1.0,0.0,0.0);
  glPointSize(0.2);
  for(int i=0;i<n;i++)
  {
  	glVertex2f(x[i],y[i]); 
  }
 glEnd();


 glFlush();
 
}

void polygonReflection () {
 
 glClear(GL_COLOR_BUFFER_BIT);

 glBegin(GL_LINES);
  glColor3f(0.4,0.7,0.2);
  glPointSize(0.2);
  for(int i=0;i<n;i++)
  	glVertex2f(x[i],y[i]);
 glEnd();
 
 glPushMatrix();
 glRotatef(theta, 0.0f, 0.0f, 1.0f);

 glBegin(GL_LINES);
  glColor3f(1.0,0.0,0.0);
  glPointSize(0.2);
  if(choice == 1)
  {
	for(int i=0;i<n;i++)
	{
	 glVertex2f(x[i],y[i]*-1);
	}
  }
  else if(choice == 2)
  {
	for(int i=0;i<n;i++)
	{
	glVertex2f(x[i]*-1,y[i]); 
	}
  }
  else
  {
	for(int i=0;i<n;i++)
	{
	glVertex2f(x[i]*-1,y[i]*-1); 
	}
  }
 glEnd();


 glFlush();
 
}

void polygonShear () {
 
 glClear(GL_COLOR_BUFFER_BIT);

 glBegin(GL_LINES);
  glColor3f(0.4,0.7,0.2);
  glPointSize(0.2);
  for(int i=0;i<n;i++)
  	glVertex2f(x[i],y[i]);
 glEnd();

 glBegin(GL_LINES);
  glColor3f(1.0,0.0,0.0);
  glPointSize(0.2);
  if(choice == 1)
  {
	for(int i=0;i<n;i++)
	{
	glVertex2f(x[i]+(y[i]*x_shear), y[i]); 
	}
  }
  else
  {
	for(int i=0;i<n;i++)
	{
	glVertex2f(x[i], y[i]+(x[i]*y_shear)); 
	}
  }
 glEnd();


 glFlush();
 
}

void main(int argc , char **argv)
{
 int action;
 printf("Enter the coordinates : ");
 for(int i=0;i<2;i++)
 {
	printf("Enter the value of x %d and y %d : ",i+1,i+1);
 	scanf("%d%d",&x[i],&y[i]);
 }
 printf("Enter the Action to be done : \n1.Translation\n2.Scaling3\n3.Rotation\n4.Reflection\n5.shear\n\n");
 scanf("%d",&action);
 switch(action)
 {
 	case 1:
 		printf("Enter the value of x_shift and y_shift : ");
 		scanf("%d%d",&x_shift,&y_shift);
		glutInit(&argc , argv);
		glutCreateWindow("translation");
		glutInitWindowSize(400,300);
		glutInitWindowPosition(300,300);
		init();
 		glutDisplayFunc(polygonTranslate);
 		glutMainLoop();
		break;
 	case 2:
		printf("Enter the value of x_scale and y_scale : ");
 		scanf("%d%d",&x_scale,&y_scale);
 		glutInit(&argc , argv);
		glutCreateWindow("scale");
		glutInitWindowSize(400,300);
		glutInitWindowPosition(300,300);
		init();
 		glutDisplayFunc(polygonScale);
 		glutMainLoop();
		break;
	case 3:
		printf("Enter the value of rotation angle : ");
 		scanf("%lf",&theta);
 		glutInit(&argc , argv);
		glutCreateWindow("rotation");
		glutInitWindowSize(400,400);
		glutInitWindowPosition(300,300);
		init();
 		glutDisplayFunc(polygonRotate);
 		glutMainLoop();
		break;
	case 4:
		printf("Enter 1 for x_reflection\nEnter 2 for y_reflection\nEnter 3 for x&y relection\n");
		scanf("%d",&choice);
 		glutInit(&argc , argv);
		glutCreateWindow("reflection");
		glutInitWindowSize(400,300);
		glutInitWindowPosition(300,300);
		init();
 		glutDisplayFunc(polygonReflection);
 		glutMainLoop();
		break;
	case 5:
		printf("Enter 1 for x_shear\nEnter 2 for y_shear\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				printf("Enter the value of x_shear : ");
		 		scanf("%d",&x_shear);
				break;
			case 2 :
				printf("Enter the value of y_shear : ");
		 		scanf("%d",&y_shear);
				break;
			default: 
				break;
		}
 		glutInit(&argc , argv);
		glutCreateWindow("shear");
		glutInitWindowSize(400,300);
		glutInitWindowPosition(300,300);
		init();
 		glutDisplayFunc(polygonShear);
 		glutMainLoop();
		break;
	default: 
		break;
 }
}