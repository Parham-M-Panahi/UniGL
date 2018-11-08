#include <iostream>
#include <math.h>
#include <glut.h>

#include "draw.h"


void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);


	// Bresenham line generation algorithm
	

	Point start = { 10, 40 };
	Point end = { 250, 200 };
	draw_Bresenham(start, end);

	

	// DDA line generation algorithm
	/*

	Point start1 = { 60, 40 };
	Point end1 = { 310, 200 };
	draw_DDA(start1, end1);

	*/


	//draw_Bres_cir(300);


	// Circle generation algorithm
	/*
	
	Point pt = { 50, 50 };
	GLfloat radius = 30;

	draw_Circle(pt, radius);
	
	*/



	// flood fill algorithm
	/*
	
	Color fillColor = { 1.0f, 0.0f, 0.0f };
	Color boundaryColor = { 0.0f, 0.0f, 0.0f };

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(50, 50);
	glVertex2i(100, 100);
	glVertex2i(150, 50);
	glVertex2i(50, 50);
	glEnd();
	glFlush();

	//boundary_Fill(100, 60, boundaryColor, fillColor);
	flood_Fill(100, 60, { 1.0f,1.0,1.0f }, fillColor);

	*/

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);


	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("UniGL");

	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}