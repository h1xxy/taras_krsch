#pragma once
#include <gl\glut.h>
#include <vector>
#include "figure.h"



class Sphere : public Figure
{
public:
	Sphere() : Figure() {};
	~Sphere();

	void draw();

private:
	std::vector<float> vertices_;
	std::vector<float> normals_;
	std::vector<float> texcoords_;
	std::vector<short> indices_;
};