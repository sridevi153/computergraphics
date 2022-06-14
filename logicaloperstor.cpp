#include<math.h>
#include<stdlib.h>
#include<glut.h>
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glEnable(GL_COLOR_LOGIC_OP);
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);

	glLogicOp(GL_XOR);
	glBegin(GL_LINES);
	glVertex2f(10, 10);
	glVertex2f(20, 20);
	glEnd();
	glFlush();
	glBegin(GL_LINES);
	glVertex2f(10, 10);
	glVertex2f(20, 20);
	glEnd();
	glFlush();
}

void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("line");
	myinit();

	glutDisplayFunc(display);
	glutMainLoop();
}
