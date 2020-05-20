#pragma once
#include <gl\glut.h>
#include "figure.h"



class Cone : public Figure
{
public:
	Cone() : Figure() {};
	~Cone();
	void draw();
};