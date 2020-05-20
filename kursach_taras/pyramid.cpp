#include "pyramid.h"



Pyramid::~Pyramid()
{

}

void Pyramid::matrixInit()
{
	dots_[0][0] = positionX_ - (length_ / 2); dots_[0][1] = positionY_ - (length_ / 2); dots_[0][2] = positionZ_ - (length_ / 2);
	dots_[1][0] = positionX_ - (length_ / 2); dots_[1][1] = positionY_ + (length_ / 2); dots_[1][2] = positionZ_ - (length_ / 2);
	dots_[2][0] = positionX_ + (length_ / 2); dots_[2][1] = positionY_ + (length_ / 2); dots_[2][2] = positionZ_ - (length_ / 2);
	dots_[3][0] = positionX_ + (length_ / 2); dots_[3][1] = positionY_ - (length_ / 2); dots_[3][2] = positionZ_ - (length_ / 2);
	dots_[4][0] = positionX_;                 dots_[4][1] = positionY_;                 dots_[4][2] = positionZ_ + (length_ / 2);

}

void Pyramid::drawQuad(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);

	glVertex3fv(dots_[a]);
	glVertex3fv(dots_[b]);
	glVertex3fv(dots_[c]);
	glVertex3fv(dots_[d]);

	glEnd();
}

void Pyramid::drawTriangle(int a, int b, int c)
{
	glBegin(GL_TRIANGLES);

	glVertex3fv(dots_[a]);
	glVertex3fv(dots_[b]);
	glVertex3fv(dots_[c]);

	glEnd();
}

void Pyramid::draw()
{
	matrixInit();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glColor3ub(colorR_, colorG_, colorB_);

	drawQuad(0, 1, 2, 3);

	drawTriangle(0, 1, 4);
	drawTriangle(1, 2, 4);
	drawTriangle(2, 3, 4);
	drawTriangle(0, 3, 4);

	glPopMatrix();
}


