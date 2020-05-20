#pragma once
#include <gl\glut.h>
#include "figure.h"



class Parallelepiped : public Figure
{
public:
	Parallelepiped() : Figure() {};
	~Parallelepiped();

	void matrixInit();
	void drawSide(int a, int b, int c, int d);
	void draw();

private:
	float dots_[8][3];
};