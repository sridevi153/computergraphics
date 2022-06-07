#include <math.h>
#include <stdlib.h>
#include <glut.h>
int w = 500, h = 500;
float size = 40;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
}

void mouse(int b, int s, int x, int y)
{
	y = h - y;
	float t;
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
	{
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1, 0, 0);
		glFlush();
		t = size / 2.0;
		glBegin(GL_POLYGON);
		glVertex2f(x + t, y + t);
		glVertex2f(x + t, y - t);
		glVertex2f(x - t, y - t);
		glVertex2f(x - t, y + t);
		glEnd();
		glFlush();
	}
	if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
	{
		exit(0);
	}
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);

}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("mouse");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}
