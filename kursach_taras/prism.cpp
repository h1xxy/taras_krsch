#include "prism.h"
#include <iostream>

#define threeSQRT 1.732f



Prism::~Prism()
{

}

void Prism::matrixInit()
{
	dots_[0][0] = positionX_ - ((threeSQRT / 2.0) * length_ * (1.0 / 3.0)); dots_[0][1] = positionY_ - (length_ / 2); dots_[0][2] = positionZ_ - (height_ / 2);
	dots_[1][0] = positionX_ - ((threeSQRT / 2.0) * length_ * (1.0 / 3.0)); dots_[1][1] = positionY_ + (length_ / 2); dots_[1][2] = positionZ_ - (height_ / 2);
	dots_[2][0] = positionX_ + ((threeSQRT / 2.0) * length_ * (2.0 / 3.0)); dots_[2][1] = positionY_;				  dots_[2][2] = positionZ_ - (height_ / 2);
	dots_[3][0] = positionX_ - ((threeSQRT / 2.0) * length_ * (1.0 / 3.0)); dots_[3][1] = positionY_ - (length_ / 2); dots_[3][2] = positionZ_ + (height_ / 2);
	dots_[4][0] = positionX_ - ((threeSQRT / 2.0) * length_ * (1.0 / 3.0)); dots_[4][1] = positionY_ + (length_ / 2); dots_[4][2] = positionZ_ + (height_ / 2);
	dots_[5][0] = positionX_ + ((threeSQRT / 2.0) * length_ * (2.0 / 3.0)); dots_[5][1] = positionY_;				  dots_[5][2] = positionZ_ + (height_ / 2);
}

void Prism::drawQuad(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);

	glVertex3fv(dots_[a]);
	glVertex3fv(dots_[b]);
	glVertex3fv(dots_[c]);
	glVertex3fv(dots_[d]);

	glEnd();
}

void Prism::drawTriangle(int a, int b, int c)
{
	glBegin(GL_TRIANGLES);

	glVertex3fv(dots_[a]);
	glVertex3fv(dots_[b]);
	glVertex3fv(dots_[c]);

	glEnd();
}

void Prism::draw()
{
	matrixInit();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glColor3ub(colorR_, colorG_, colorB_);

	drawQuad(0, 1, 4, 3);
	drawQuad(1, 2, 5, 4);
	drawQuad(0, 2, 5, 3);

	drawTriangle(3, 4, 5);
	drawTriangle(0, 1, 2);

	glPopMatrix();
}