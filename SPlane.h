#ifndef _SPLANE_H_INCL
#define _SPLANE_H_INCL

#include "Shape.h"

class SPlane : public Shape
{
public:
	SPlane(const vector3df& orig, const vector3df& norm);
	~SPlane() {}

	virtual bool getIntersection(const ray& ray, vector3df& result);
	virtual vector3df getNormal(const vector3df& point) { return Normal; }

	vector3df getOrigin() { return Origin; }

	void setNormal(const vector3df& norm) { Normal = norm; }
	void setOrigin(const vector3df& orig) { Origin = orig; }

private:
	vector3df Normal;
	vector3df Origin;
};

#endif