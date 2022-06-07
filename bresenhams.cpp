#include <math.h>
#include <stdlib.h>
#include <glut.h>
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}
void setpixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}
void bresenhams(int x0, int y0, int xend, int yend)
{
	int dx = xend - x0, dy = yend - y0;
	int p = 2 * dy - dx;
	int twody = 2 * dy, twodyminusdx = 2 * (dy - dx);
	int x=x0, y=y0;

	if (x0 > xend)
	{
		x = xend;
		y = yend;
		yend = y0;
	}
	else
	{
		x = x0;
		y = y0;
	}
	setpixel(x,y);
	while (x < xend)
	{
		x++;
		if (p < 0)
			p += twody;
		else
		{
			y++;
			p += twodyminusdx;
		}
		setpixel(x, y);
	}
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(2);
	bresenhams(40, 40, -20, -20);
	glFlush();

}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("bresenhams");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
