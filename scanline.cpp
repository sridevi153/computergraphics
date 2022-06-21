#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
int np = 4;
float et[4][4] = { {100,200,250,-1},{100,200,250,1},{200,300,150,1},{200,300,350,-1} };
float ae[4][3];
float js = et[0][0];
int iaet = 0;
int ymax = 0;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}

void addaet()
{
	int i;
	for (i = 0; i < np; i++)
	{
		if (js == et[i][0])
		{
			ae[iaet][0] = et[i][1];
			ae[iaet][1] = et[i][2];
			ae[iaet][2] = et[i][3];
			if (ae[iaet][0] > ymax)
				ymax = ae[iaet][0];
			iaet++;
		}
	}
}

void upaet()
{
	int i;
	for (i = 0; i < iaet; i++)
		ae[i][1] = ae[i][1] + ae[i][2];
}

void draw_pixel(float x1, float x2)
{
	float n;
	for (n = x1; n < x2; n++)
	{
		glColor3f(1, 1, 0);
		glBegin(GL_POINTS);
		glVertex2f(n, js);
		glEnd();
		glFlush();
	}
}

void fill()
{
	float x[2] = { 0,0 };
	int i;
	do {
		i = 0;
		addaet();
		if (ae[0][0] > js)
		{
			x[i] = ae[0][1]; i++;
		}
		if (ae[1][0] > js)
		{
			x[i] = ae[1][1]; i++;
		}
		if (ae[2][0] > js)
		{
			x[i] = ae[2][1]; i++;
		}
		if (ae[3][0] > js)
		{
			x[i] = ae[3][1]; i++;
		}
		draw_pixel(x[0], x[1]);
		upaet();
		js++;
	} while (js <= ymax);
}

void display()
{

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	fill();
}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("scan");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
