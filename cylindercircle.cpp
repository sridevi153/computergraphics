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
	int xc = 0, yc = 0, r = 10;
	float x, y;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 1);
	glBegin(GL_POINTS);
	for (xc = 0; xc <= 10; xc += 2)
	{
		for (int i = 0; i <= 360; i += 1)
		{
			x = xc + r * cos(i);
			y = yc + r * sin(i);
			glVertex2f(x, y);
		}
		yc += 2;
	}
	glEnd();
	glFlush();
}

void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("circle");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
