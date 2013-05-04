#include "Scene.h"

// this is a SIMPLE & SLOW implementation!
// you should upgrade it with efficiency structures
Shape* Scene::getNearestIntersection(ray& ray, vector3df& inter)
{
	float currentdist = 10e20;
	float dist;

	Shape* result = 0;
	vector3df intersection;

	core::list<Shape*>::Iterator it;
	for (it = shapes.begin(); it != shapes.end(); it++)
	{
		if (!(*it)->getIntersection(ray, intersection))
			continue;

		dist = ray.start.getDistanceFromSQ(intersection);
		if (!result || dist < currentdist)
		{
			currentdist = dist;
			result = *it;
			inter = intersection;
		}
	}

	return result;
}

SColor Scene::getDiffuse(const vector3df& point, const vector3df& normal)
{
	SColor ret(255, 0,0,0);
	core::list<Light*>::Iterator it;
	for (it = lights.begin(); it != lights.end(); it++)
	{
		float dot = ((*it)->Position - point).normalize().dotProduct(normal);
		if (dot < 0)
			continue;
		ret = ret + (*it)->Color.getInterpolated(SColor(255,0,0,0),dot);
	}
	return ret;
}