#pragma once
#include <gl\glut.h>

class Figure
{
public:
	Figure();
	~Figure();

	virtual void draw() = 0;
	void rotate(int x, int y, int z);
	void scale(float x, float y, float z);
	void translate(float x, float y, float z);

	void setLength(float sideSize);
	void setHeight(float height);
	void setWidth(float width);
	void setDepth(float depth);
	void setRadius(float radius);

	void setPositionX(float positionX);
	void setPositionY(float positionY);
	void setPositionZ(float positionZ);

	void setColorR(GLubyte colorR);
	void setColorG(GLubyte colorG);
	void setColorB(GLubyte colorB);

protected:
	float length_;
	float height_;
	float width_;
	float depth_;
	float radius_;

	float positionX_;
	float positionY_;
	float positionZ_;

	GLubyte colorR_;
	GLubyte colorG_;
	GLubyte colorB_;
};