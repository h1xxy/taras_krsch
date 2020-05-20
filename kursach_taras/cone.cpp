#include "cone.h"
#include <math.h>

#define M_PI 3.14159265358979323846
#define ANGLE_STEPSIZE 0.001f



Cone::~Cone()
{

}

void Cone::draw()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	float x = 0.0;
	float y = 0.0;
	float angle;

	glColor3ub(colorR_, colorG_, colorB_);

	glBegin(GL_POLYGON);
	angle = 0.0;
	glVertex3f(positionX_, positionY_, positionZ_ + (height_ / 2));
	while (angle <= 2 * M_PI + 1)
	{
		x = radius_ * cos(angle);
		y = radius_ * sin(angle);
		glVertex3f(x + positionX_, y + positionY_, positionZ_ - (height_ / 2));
		angle = angle + ANGLE_STEPSIZE;
	}
	glEnd();

	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * M_PI)
	{
		x = radius_ * cos(angle);
		y = radius_ * sin(angle);
		glVertex3f(x + positionX_, y + positionY_, positionZ_ - (height_ / 2));
		angle = angle + ANGLE_STEPSIZE;
	}
	glEnd();

	glPopMatrix();
}

