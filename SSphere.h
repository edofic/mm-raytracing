#ifndef _SSPHERE_H_INCL
#define _SSPHERE_H_INCL

#include "Shape.h"

class SSphere : public Shape
{
public:
	SSphere(const vector3df& c, float r, Material* mat) :
	  Shape(mat), Center(c), Radius(r) {}
	~SSphere() {}

	virtual bool getIntersection(const ray& ray, vector3df& result);
	virtual vector3df getNormal(const vector3df& point);

	vector3df getCenter() { return Center; }
	float getRadius() { return Radius; }

	void setCenter(const vector3df& c) { Center = c; }
	void setRadius(float r) { Radius = r; }

private:
	vector3df Center;
	float Radius;
};

#endif