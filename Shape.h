#ifndef _SHAPE_H_INCL
#define _SHAPE_H_INCL

#include <irrlicht.h>
using namespace irr;
using core::vector3df;

#include "ray.h"
#include "Material.h"

class Shape
{
public:
	Shape(Material* mat) : Mat(mat) {}
	virtual ~Shape() {}
	virtual bool getIntersection(const ray& ray, vector3df& result) = 0;
	virtual vector3df getNormal(const vector3df& point) = 0;

	Material* getMaterial() { return Mat; }
	void setMaterial(Material* mat) { Mat = mat; }

protected:
	core::matrix4 Transformation;
	Material* Mat;
};

#endif