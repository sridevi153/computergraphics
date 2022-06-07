#include<glut.h>
int size = 2;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-10 * size, -10 * size);
	glVertex2f(10 * size, -10 * size);
	glVertex2f(10 * size, 10 * size);
	glVertex2f(-10 * size, 10 * size);
	glEnd();
	glFlush();
}

void demo(int id)
{
	switch (id)
	{
	case 1: size = size * 2;
		break;
	case 2: size = size / 2;
		break;
	case 3: exit(0);
	}
	glutPostRedisplay();
}

void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("menu");
	myinit();
	glutCreateMenu(demo);
	glutAddMenuEntry("inc size", 1);
	glutAddMenuEntry("dec size", 2);
	glutAddMenuEntry("quit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);
	glutMainLoop();
}
