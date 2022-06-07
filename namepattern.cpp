#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <glut.h>
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void output(char* string)
{
	int len, i;
	glRasterPos2f(10, 50);
	len = strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	int x = 5;
	for (i = 1; i < len; i++)
	{
		glRasterPos2f(10, 50 - (x*i));
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
	for (i = 1; i < len; i++)
	{
		glRasterPos2f(10 + (x*i), 50 + (x*i));
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	char string[8] = "SRIDEVI";
	output(string);
	glFlush();

}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("name");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
