#pragma once
#include <gl\glut.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <map>
#include <vector>
#include <functional>
#include "cube.h"
#include "sphere.h"
#include "cylinder.h"
#include "pyramid.h"
#include "cone.h"
#include "parallelepiped.h"
#include "prism.h"
#include "figureQueue.h"

class Parser
{
public:
	Parser();
	~Parser();

	void run(int*, char**);

private:
	FigureQueue figureQueue;

	std::shared_ptr<Cube> cube;
	std::shared_ptr<Sphere> sphere;
	std::shared_ptr<Cylinder> cylinder;
	std::shared_ptr<Pyramid> pyramid;
	std::shared_ptr<Cone> cone;
	std::shared_ptr<Parallelepiped> parallelepiped;
	std::shared_ptr<Prism> prism;
	
	std::vector<std::string> getString(std::string line, int num);
};