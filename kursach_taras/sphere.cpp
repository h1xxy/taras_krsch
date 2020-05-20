#include "sphere.h"

#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define RINGS 20.0f
#define SECTORS 32.0f



Sphere::~Sphere()
{

}

void Sphere::draw()
{
	const float R = 1.0f / (RINGS - 1.0f);
	const float S = 1.0f / (SECTORS - 1.0f);
	int r, s;

	vertices_.resize(RINGS * SECTORS * 3);
	normals_.resize(RINGS * SECTORS * 3);
	texcoords_.resize(RINGS * SECTORS * 2);

	std::vector<float>::iterator v = vertices_.begin();
	std::vector<float>::iterator n = normals_.begin();
	std::vector<float>::iterator t = texcoords_.begin();

	for (r = 0; r < RINGS; r++)
		for (s = 0; s < SECTORS; s++)
		{
			const float y = sin(-M_PI_2 + M_PI * r * R);
			const float x = cos(2 * M_PI * s * S) * sin(M_PI * r * R);
			const float z = sin(2 * M_PI * s * S) * sin(M_PI * r * R);

			*t++ = s * S;
			*t++ = r * R;
			 
			*v++ = x * radius_;
			*v++ = y * radius_;
			*v++ = z * radius_;

			*n++ = x;
			*n++ = y;
			*n++ = z;
		}

	indices_.resize(RINGS * SECTORS * 4);
	std::vector<short>::iterator i = indices_.begin();
	for (r = 0; r < RINGS - 1; r++)
		for (s = 0; s < SECTORS - 1; s++)
		{
			*i++ = r * SECTORS + s;
			*i++ = r * SECTORS + (s + 1);
			*i++ = (r + 1) * SECTORS + (s + 1);
			*i++ = (r + 1) * SECTORS + s;
		}

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(positionX_, positionY_, positionZ_);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glColor3ub(colorR_, colorG_, colorB_);

	glVertexPointer(3, GL_FLOAT, 0, &vertices_[0]);
	glNormalPointer(GL_FLOAT, 0, &normals_[0]);
	glTexCoordPointer(2, GL_FLOAT, 0, &texcoords_[0]);
	glDrawElements(GL_QUADS, indices_.size(), GL_UNSIGNED_SHORT, &indices_[0]);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glPopMatrix();
}