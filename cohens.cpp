#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#define outcode int
enum{top = 0x8, bottom = 0x4, left = 0x1, right = 0x2};
int xmin = 50, ymin = 50, xmax = 100, ymax = 100, xvmin = 200, yvmin = 200, xvmax = 400, yvmax = 400;
float x1, y1, x2, y2, prev_x1, prev_y1, prev_x2, prev_y2;
outcode generateOpcode(int x, int y)
{
	int p = 0;
	if (x < xmin)
		p = p | left;
	if (x > xmax)
		p = p | right;
	if (y < ymin)
		p = p | bottom;
	if (y > ymax)
		p = p | top;
	return p;
}

void sutherland()
{
	float m;
	outcode p1, p2, p;
	int x, y;
	x1 = prev_x1;
	y1 = prev_y1;
	x2 = prev_x2;
	y2 = prev_y2;
	p1 = generateOpcode(x1, y1);
	p2 = generateOpcode(x2, y2);
	bool accept = false;
	bool done = false;
	while (!done)
	{
		if ((p1 | p2) == 0)
		{
			done = true;
			accept = true;
		}
		else if ((p1&p2) != 0)
		{
			done = true;
		}
		else
		{
			m = (y2 - y1) / (x2 - x1);
			p = p1 != 0 ? p1 : p2;
			if ((p & left) != 0)
			{
				x = xmin;
				y = y1 + (xmin - x1) * m;
			}
			if ((p & right) != 0)
			{
				x = xmax;
				y = y1 + (xmax - x1)*m;
			}
			if ((p & top) != 0)
			{
				y = ymax;
				x = x1 + (ymax - y1)/m;
			}
			if ((p & bottom) != 0)
			{
				y = ymin;
				x = x1 + (ymin - y1) / m;
			}
			if (p == p1)
			{
				x1 = x;
				y1 = y;
				p1 = generateOpcode(x1, y1);
			}
			if (p == p2)
			{
				x2 = x;
				y2 = y;
				p2 = generateOpcode(x2, y2);
			}
		}
	}
	if (accept)
	{
		float sx = (xvmax - xvmin) / (xmax - xmin);
		float sy = (yvmax - yvmin) / (ymax - ymin);
		x1 = sx * x1 + xvmin - sx * xmin;
		y1 = sy * y1 + yvmin - sy * ymin;
		x2 = sx * x2 + xvmin - sx * xmin;
		y2 = sy * y2 + yvmin - sy * ymin;

		glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glEnd();
		glFlush();
	}
}
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1200, 0, 1200);
	glMatrixMode(GL_MODELVIEW);
}


void display()
{

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin, ymin);
	glVertex2f(xmin, ymax);
	glVertex2f(xmax, ymax);
	glVertex2f(xmax, ymin);
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xvmin, yvmin);
	glVertex2f(xvmin, yvmax);
	glVertex2f(xvmax, yvmax);
	glVertex2f(xvmax, yvmin);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(prev_x1, prev_y1);
	glVertex2f(prev_x2, prev_y2);
	glEnd();

	glColor3f(0, 0, 0);
	sutherland();
	glFlush();
}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1200, 1200);
	glutCreateWindow("clipping");
	myinit();
	printf("enter the line points : \n");
	scanf_s("%f%f%f%f", &prev_x1, &prev_y1, &prev_x2, &prev_y2);
	glutDisplayFunc(display);
	glutMainLoop();
}
