#include<math.h>
#include<stdlib.h>
#include<glut.h>
float a = 0;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	int  r = 30;
	float x, y;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	x = r * cos(a);
	y = r * sin(a);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(-y, x);
	glVertex2f(-x, -y);
	glVertex2f(y, -x);
	glEnd();
	glFlush();
}
void idle(int v)
{
	a += 5;
	if (a >= 360)
		a = 0;
	glutTimerFunc(30, idle, 60);
	glutPostRedisplay();
}

void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("rotate");
	myinit();
	glutDisplayFunc(display);
	glutTimerFunc(30, idle, 60);
	glutMainLoop();
}
