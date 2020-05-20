#pragma once
#include <gl\glut.h>
#include "figureQueue.h"
#include <memory>
#include "parser.h"


class Browser
{
public:
	Browser(int*, char**);
	~Browser();

	void run();
	void initializeScreen();

private:
	Parser parser;
};



