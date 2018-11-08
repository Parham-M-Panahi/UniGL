#include <iostream>

#include <glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);

	glColor3f(0.0, 0.0, 0.0);
	glPushAttrib(GL_ALL_ATTRIB_BITS);
}

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 0.8, 0.6);

	glBegin(GL_POLYGON);
	glVertex2i(100, 100);
	glVertex2i(400, 100);
	glVertex2i(250, 250);
	glEnd();

	glPopAttrib();

	glBegin(GL_POLYGON);
	glVertex2i(100, 250);
	glVertex2i(400, 250);
	glVertex2i(250, 400);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL - AttribGroup");


	init();

	glutDisplayFunc(draw);
	glutMainLoop();


	return 0;
}