#include <math.h>
#include <stdlib.h>
#include <glut.h>
int id1, id2;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void display1()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(10, 10);
	glVertex2f(10, 20);
	glVertex2f(20, 20);
	glVertex2f(20, 10);
	glEnd();
	glFlush();
}

void display2()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(10, 10);
	glVertex2f(10, 30);
	glVertex2f(30, 30);
	glVertex2f(30, 10);
	glEnd();
	glFlush();
}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(40, 40);
	glutInitWindowSize(400, 400);
	id1 = glutCreateWindow("sq1");
	glutSetWindow(id1);
	myinit();
	glutDisplayFunc(display1);
	glutInitWindowPosition(60, 60);
	glutInitWindowSize(500, 500);
	id2 = glutCreateWindow("sq2");
	glutSetWindow(id2);
	myinit();
	glutDisplayFunc(display2);
	glutMainLoop();
}
