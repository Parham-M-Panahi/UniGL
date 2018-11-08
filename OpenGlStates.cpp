#include <iostream>

#include <glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void printColorValues()
{
	GLfloat colorValues[4];
	glGetFloatv(GL_CURRENT_COLOR, colorValues);


	std::cout << " Red Value: " << colorValues[0] << std::endl;
	std::cout << " Green Value: " << colorValues[1] << std::endl;
	std::cout << " BlueValue: " << colorValues[2] << std::endl;
	std::cout << " Alpha Value: " << colorValues[3] << std::endl;
	std::cout << std::endl << std::endl;
}


void draw(void)
{
	printColorValues();

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 0.8, 0.6);

	printColorValues();

	glBegin(GL_POLYGON);
	glVertex2i(100, 100);
	glVertex2i(400, 100);
	glVertex2i(250, 250);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL - States");

	GLint redBitSize;
	glGetIntegerv(GL_RED_BITS, &redBitSize);
	std::cout << "Size of red bits in frame buffer: " << redBitSize << std::endl << std::endl;



	init();

	glutDisplayFunc(draw);
	glutMainLoop();


	return 0;
}