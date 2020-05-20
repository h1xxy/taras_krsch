#pragma once
#include <gl\glut.h>
#include "figure.h"



class Pyramid : public Figure
{
public:
	Pyramid() : Figure() {};
	~Pyramid();

	void matrixInit();
	void drawQuad(int a, int b, int c, int d);
	void drawTriangle(int a, int b, int c);
	void draw();

private:
	float dots_[5][3];
};