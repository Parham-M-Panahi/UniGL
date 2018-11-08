#include <iostream>
#include <math.h>

#include "draw.h"

Color getPixel(GLint x, GLint y)
{
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixel(GLint x, GLint y, Color color)
{
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void draw_DDA(Point start, Point end)
{
	double slope = (double)(end.y - start.y) / (double)(end.x - start.x);
	double xi = start.x;
	double yi = start.y;

	Color color = { 0.0f, 0.0f, 0.0f };

	setPixel(xi, yi, color);
	while (xi <= end.x)
	{
		if (fabs(slope) <= 1)
		{
			xi += 1;
			yi += slope;
		}
		else
		{
			xi += (1 / slope);
			yi += 1;
		}
		setPixel(round(xi), round(yi), color);
	}
}

void draw_Bresenham(Point start, Point end)
{
	double deltax = end.x - start.x;
	double deltay = end.y - start.y;

	double slope = (deltay) / (deltax);
	if (slope > 1 || slope < 0)
	{
		std::cout << "slope is: " << slope << " Cant use Bresenham's line algorithm" << std::endl;
		return;
	}

	int xi = round(start.x);
	int yi = round(start.y);

	double di = 2 * deltay - deltax;

	Color color = { 0.0f, 0.0f, 0.0f };

	while (xi <= end.x)
	{
		setPixel(xi, yi, color);

		if (di < 0)
		{
			di += 2 * deltay;

			xi += 1;

		}
		else
		{
			di += 2 * (deltay - deltax);

			xi += 1;
			yi += 1;
		}
	}
}

void draw_Bres_cir(double rad)
{
	int xi = 0;
	int yi = round(rad);

	double di = 3 - (2 * rad);

	Color color = { 0.0f, 0.0f, 0.0f };

	while (xi <= rad * (sqrt(2) / 2))
	{
		setPixel(round(xi), round(yi), color);

		if (di < 0)
		{
			di += (4 * xi) + 6;

			xi += 1;
		}
		else
		{
			di += (4 * (xi - yi)) + 10;

			xi += 1;
			yi -= 1;
		}
	}
}

void draw_Circle(Point pC, GLfloat rad)
{
	GLfloat step = 1 / rad;
	GLfloat x, y;

	Color color = { 0.0f, 0.0f, 0.0f };

	for (GLfloat theta = 0; theta <= 360; theta += step) {
		x = pC.x + (rad * cos(theta));
		y = pC.y + (rad * sin(theta));
		setPixel(round(x), round(y), color);
	}
}

void flood_Fill(GLint x, GLint y, Color oldColor, Color newColor)
{

	Color color;
	color = getPixel(x, y);

	if (color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	{
		setPixel(x, y, newColor);
		flood_Fill(x + 1, y, oldColor, newColor);
		flood_Fill(x, y + 1, oldColor, newColor);
		flood_Fill(x - 1, y, oldColor, newColor);
		flood_Fill(x, y - 1, oldColor, newColor);
	}
	return;
}

void boundary_Fill(GLint x, GLint y, Color boundaryColor, Color fillColor)
{

	Color color;
	color = getPixel(x, y);

	if (color.r != boundaryColor.r || color.g != boundaryColor.g || color.b != boundaryColor.b)
	{
		setPixel(x, y, fillColor);
		boundary_Fill(x + 1, y, boundaryColor, fillColor);
		boundary_Fill(x, y + 1, boundaryColor, fillColor);
		boundary_Fill(x - 1, y, boundaryColor, fillColor);
		boundary_Fill(x, y - 1, boundaryColor, fillColor);
	}
	return;
}