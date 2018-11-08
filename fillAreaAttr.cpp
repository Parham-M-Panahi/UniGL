#include <glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}


void interpolationPattern(void)
{
	glShadeModel(GL_SMOOTH);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(100, 100);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(400, 100);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(250, 250);
	glEnd();

	glFlush();
}

void maskPattern(void)
{
	GLubyte fillPattern[] = {	0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA ,
								0XAA, 0XAA, 0XAA, 0XAA
							};

	glPolygonStipple(fillPattern);

	glEnable(GL_POLYGON_STIPPLE);

	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	glVertex2i(100, 100);
	glVertex2i(400, 100);
	glVertex2i(250, 250);
	glEnd();

	glFlush();

	glDisable(GL_POLYGON_STIPPLE);
}

void wireFrame(void)
{

	glPolygonMode(GL_FRONT, GL_LINE);
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	glVertex2i(100, 100);
	glVertex2i(400, 100);
	glVertex2i(250, 250);
	glEnd();

	glFlush();
}

void stitching(void)
{
	glPolygonMode(GL_FRONT, GL_LINE);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(100, 100, 0.25);
	glVertex3f(400, 100, 0.5);
	glVertex3f(250, 250, 0.75);
	glEnd();

	glFlush();


	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_POLYGON);
	glVertex3f(100, 100, 0.25);
	glVertex3f(400, 100, 0.5);
	glVertex3f(250, 250, 0.75);
	glEnd();

	glFlush();
}

void edgeFlag(void)
{
	glPolygonMode(GL_FRONT, GL_LINE);
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(100, 100);
	glEdgeFlag(GL_FALSE);
	glVertex2f(400, 100);
	glEdgeFlag(GL_TRUE);
	glVertex2f(250, 250);
	glEnd();

	glFlush();
}

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	interpolationPattern();

	//maskPattern();

	//wireFrame();

	//stitching();

	//edgeFlag();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Fill Area Attr");

	init();

	glutDisplayFunc(draw);
	glutMainLoop();


	return 0;
}