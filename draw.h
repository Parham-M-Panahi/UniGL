#pragma once

#include <glut.h>

typedef struct {
	GLint x;
	GLint y;
}
Point;

typedef struct {
	GLfloat r;
	GLfloat g;
	GLfloat b;
}
Color;

Color getPixel(GLint x, GLint y);
void setPixel(GLint x, GLint y, Color color);

void draw_DDA(Point start, Point end);
void draw_Bresenham(Point start, Point end);
void draw_Bres_cir(double rad);

void draw_Circle(Point pC, GLfloat rad);
void flood_Fill(GLint x, GLint y, Color oldColor, Color newColor);

void boundary_Fill(GLint x, GLint y, Color boundaryColor, Color fillColor);
