#include <glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);

	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_BLEND);
}


void triangle(void)
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4f(1.0, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(100, 100);
	glVertex2i(400, 100);
	glVertex2i(250, 250);
	glEnd();

	glFlush();
}


void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	triangle();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Anti-Aliasing");

	init();

	glutDisplayFunc(draw);
	glutMainLoop();


	return 0;
}