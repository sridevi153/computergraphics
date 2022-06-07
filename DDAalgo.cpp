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
void DDA(float x0, float y0, float xend, float yend)
{
	float dx = xend - x0, dy = yend - y0, steps;
	int k;
	float xinc, yinc, x = x0, y = y0;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xinc = dx/ steps;
	yinc = dy / steps;
	setpixel(round(x), round(y));
	for (k = 0; k < steps; k++)
	{
		x += xinc;
		y += yinc;
		setpixel(round(x), round(y));
	}
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(2);
	DDA(30, 30, 40, 60);
	glFlush();

}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("DDA");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
