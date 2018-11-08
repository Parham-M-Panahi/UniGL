#include <glut.h>

GLsizei winWidth = 400, winHeight = 400;

typedef struct { float x, y; } wcPt2D;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, (GLdouble)winWidth, 0.0, (GLdouble)winHeight);
}

void winReshapeFunc(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);

	glClear(GL_COLOR_BUFFER_BIT);
}

void linePlot(wcPt2D dataPts[5])
{
	glShadeModel(GL_SMOOTH);

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
	for (int k = 0; k < 5; k++)
	{
		glVertex2f(dataPts[k].x, dataPts[k].y);
		glColor3f(0.0 + ((double)(k + 1) / 5.0), 0.0, 1.0 - ((double)(k + 1) / 5.0));
	}

	glFlush();

	glEnd();
}



void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_LINE_STIPPLE);

	wcPt2D dataPts0[5] = { { 50, 100 } ,{ 100, 150 } ,{ 150, 340 },{ 200, 380 },{ 250, 340 } };
	glLineStipple(1, 0x1C47);
	glLineWidth(2.0);
	linePlot(dataPts0);

	wcPt2D dataPts1[5] = { { 50, 200 } ,{ 100, 250 } ,{ 150, 140 },{ 200, 180 },{ 250, 140 } };
	glLineStipple(1, 0x00FF);
	glLineWidth(4.0);
	linePlot(dataPts1);

	wcPt2D dataPts2[5] = { { 50, 300 } ,{ 100, 350 } ,{ 150, 290 },{ 200, 330 },{ 250, 290 } };
	glLineStipple(1, 0x0101);
	glLineWidth(8.0);
	linePlot(dataPts2);

	glDisable(GL_LINE_STIPPLE);

	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("OpenGL line-style");

	init();

	glutDisplayFunc(draw);
	glutReshapeFunc(winReshapeFunc);

	glutMainLoop();
	return 0;
}