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

void EIGHT_WAY_SYM(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glVertex2f(y, x);
	glVertex2f(-x, y);
	glVertex2f(-y, x);
	glVertex2f(-x, -y);
	glVertex2f(-y, -x);
	glVertex2f(x, -y);
	glVertex2f(y, -x);
	glEnd();
	glFlush();
}

void display()
{
	int  r = 30;
	int x = 0, y = r, p;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 1);
	p = 1 - r;
	EIGHT_WAY_SYM(x, y);
	while (x <= y)
	{
		x++;
		if (p < 0)
			p += (2 * x) + 1;
		else
		{
			y--;
			p +=( 2 * x )+ (2 * y) + 1;
		}
		EIGHT_WAY_SYM(x, y);
	}
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
