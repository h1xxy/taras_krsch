#pragma once
#include <gl\glut.h>
#include "figure.h"



class Cube : public Figure
{
public:
	Cube() : Figure() {};
	~Cube();

	void matrixInit();
	void drawSide(int a, int b, int c, int d);
	void draw();

private:
	float dots_[8][3];
};