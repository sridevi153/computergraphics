#include <math.h>
#include <stdlib.h>
#include <glut.h>
float a = 90;
int p[9][2] = { {10,0},{10,10},{20,10},{20,0},{15,20},{13,0},{13,5},{17,5},{17,0} };
int p1[9][2];
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}

void draw_house(int p[][2])
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(p[0][0], p[0][1]);
	glVertex2f(p[1][0], p[1][1]);
	glVertex2f(p[2][0], p[2][1]);
	glVertex2f(p[3][0], p[3][1]);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(p[1][0], p[1][1]);
	glVertex2f(p[4][0], p[4][1]);
	glVertex2f(p[2][0], p[2][1]);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(p[5][0], p[5][1]);
	glVertex2f(p[6][0], p[6][1]);
	glVertex2f(p[7][0], p[7][1]);
	glVertex2f(p[8][0], p[8][1]);
	glEnd();
}

void display()
{
	int n=9, xp = 15, yp = 20;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(2);
	draw_house(p);
	for (int i = 0; i < n; i++)
	{
		p1[i][0] = p[i][0] * cos(a) - p[i][1] * sin(a) + xp - xp * cos(a) + yp * sin(a);
		p1[i][1] = p[i][0] * sin(a) + p[i][1] * cos(a) + xp - xp * sin(a) - yp * cos(a);
	}
	draw_house(p1);
	glFlush();
}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("house");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
