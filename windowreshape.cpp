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

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float t1 = (float)w / (float)h;
	float t2 = (float)h / (float)w;
	if(w>h)
		gluOrtho2D(-100 * t1, 100 * t1, -100, 100);
	else
		gluOrtho2D(-100, 100, -100 * t2, 100 * t2);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(2);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 10);
	glVertex2f(-10, -10);
	glVertex2f(10, -10);
	glVertex2f(10, 10);
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
	glutReshapeFunc(reshape);
	glutMainLoop();
}
