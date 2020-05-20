#pragma once
#include <gl\glut.h>
#include "figure.h"



class Cylinder : public Figure
{
public:
	Cylinder() : Figure() {};
	~Cylinder();

	void draw();
};