#include "parallelepiped.h"



Parallelepiped::~Parallelepiped()
{

}

void Parallelepiped::matrixInit()
{
	dots_[0][0] = positionX_ - (depth_ / 2); dots_[0][1] = positionY_ - (width_ / 2); dots_[0][2] = positionZ_ + (height_ / 2);
	dots_[1][0] = positionX_ - (depth_ / 2); dots_[1][1] = positionY_ + (width_ / 2); dots_[1][2] = positionZ_ + (height_ / 2);
	dots_[2][0] = positionX_ + (depth_ / 2); dots_[2][1] = positionY_ + (width_ / 2); dots_[2][2] = positionZ_ + (height_ / 2);
	dots_[3][0] = positionX_ + (depth_ / 2); dots_[3][1] = positionY_ - (width_ / 2); dots_[3][2] = positionZ_ + (height_ / 2);
	dots_[4][0] = positionX_ - (depth_ / 2); dots_[4][1] = positionY_ - (width_ / 2); dots_[4][2] = positionZ_ - (height_ / 2);
	dots_[5][0] = positionX_ - (depth_ / 2); dots_[5][1] = positionY_ + (width_ / 2); dots_[5][2] = positionZ_ - (height_ / 2);
	dots_[6][0] = positionX_ + (depth_ / 2); dots_[6][1] = positionY_ + (width_ / 2); dots_[6][2] = positionZ_ - (height_ / 2);
	dots_[7][0] = positionX_ + (depth_ / 2); dots_[7][1] = positionY_ - (width_ / 2); dots_[7][2] = positionZ_ - (height_ / 2);
}

void Parallelepiped::drawSide(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);

	glVertex3fv(dots_[a]);
	glVertex3fv(dots_[b]);
	glVertex3fv(dots_[c]);
	glVertex3fv(dots_[d]);

	glEnd();
}

void Parallelepiped::draw()
{
	matrixInit();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glColor3ub(colorR_, colorG_, colorB_);

	drawSide(0, 3, 2, 1);
	drawSide(2, 3, 7, 6);
	drawSide(0, 4, 7, 3);
	drawSide(1, 2, 6, 5);
	drawSide(4, 5, 6, 7);
	drawSide(0, 1, 5, 4);

	glPopMatrix();
}


