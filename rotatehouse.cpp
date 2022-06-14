#include <math.h>
#include <stdlib.h>
#include <glut.h>
float a = 90;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}

void draw_house()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(10,0);
	glVertex2f(10,10);
	glVertex2f(20,10);
	glVertex2f(20,0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(10,10);
	glVertex2f(15,20);
	glVertex2f(20,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(13,0);
	glVertex2f(13,5);
	glVertex2f(17,5);
	glVertex2f(17,0);
	glEnd();
}

void display()
{
	int xp = 15, yp = 20;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(2);
	draw_house();
	glFlush();
	glColor3f(0, 0, 1);
	glLoadIdentity();
	glTranslatef(xp, yp, 0);
	glRotatef(a, 0, 0, 1);
	glTranslatef(-xp, -yp, 0);
	draw_house();
	glFlush();
}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("house");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
