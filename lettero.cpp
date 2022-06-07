#include <math.h>
#include <stdlib.h>
#include <glut.h>
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(2);
	float xc = 40, yc = 40, r1 = 10, r2 = 15, x1, y1, x2, y2;
	int t;
	glBegin(GL_QUAD_STRIP); //or glBegin(GL_LINES);
	for (t = 0; t <= 360; t++)
	{
		x1 = xc + r1 * cos(t);
		y1 = yc + r1 * sin(t);
		x2 = xc + r2 * cos(t);
		y2 = yc + r2 * sin(t);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
	}
	glEnd();
	glFlush();

}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("lettero");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
