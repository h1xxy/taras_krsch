#include "figure.h"
#include <memory>

Figure::Figure()
{
	length_ = 0.5f;
	height_ = 0.5f;
	width_ = 0.5f;
	depth_ = 0.5f;
	radius_ = 0.5;

	colorR_ = 100;
	colorR_ = 100;
	colorR_ = 100;

	positionX_ = 0.0f;
	positionY_ = 0.0f;
	positionZ_ = 0.0f;
}

Figure::~Figure()
{

}

void Figure::rotate(int x, int y, int z)
{
	glRotatef(x, 1.0, 0.0, 0.0);
	glRotatef(y, 0.0, 1.0, 0.0);
	glRotatef(z, 0.0, 0.0, 1.0);
	glutPostRedisplay();
}

void Figure::scale(float x, float y, float z)
{
	glScalef(x, y, z);
	glutPostRedisplay();
}

void Figure::translate(float x, float y, float z)
{
	glTranslatef(x, y, z);
	glutPostRedisplay();
}

void Figure::setLength(float length)
{
	length_ = length;
}

void Figure::setHeight(float height)
{
	height_ = height;
}

void Figure::setWidth(float width)
{
	width_ = width;
}

void Figure::setDepth(float depth)
{
	depth_ = depth;
}

void Figure::setRadius(float radius)
{
	radius_ = radius;
}

void Figure::setColorR(GLubyte colorR)
{
	colorR_ = colorR;
}

void Figure::setColorG(GLubyte colorG)
{
	colorG_ = colorG;
}

void Figure::setColorB(GLubyte colorB)
{
	colorB_ = colorB;
}

void Figure::setPositionX(float positionX)
{
	positionX_ = positionX;
}

void Figure::setPositionY(float positionY)
{
	positionY_ = positionY;
}

void Figure::setPositionZ(float positionZ)
{
	positionZ_ = positionZ;
}