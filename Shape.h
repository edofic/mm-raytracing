#ifndef _SHAPE_H_INCL
#define _SHAPE_H_INCL

#include <irrlicht.h>
using namespace irr;
using core::vector3df;

#include "ray.h"

class Shape
{
public:
	Shape() {}
	virtual ~Shape() {}
	virtual bool getIntersection(const ray& ray, vector3df& result) = 0;
	virtual vector3df getNormal(const vector3df& point) = 0;

protected:
	core::matrix4 Transformation;
};

#endif