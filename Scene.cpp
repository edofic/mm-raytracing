#include "Scene.h"

// this is a SIMPLE & SLOW implementation!
// you should upgrade it with efficiency structures
Shape* Scene::getNearestIntersection(ray& ray, vector3df& inter)
{
	float currentdist = 10e20f;
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

SColor Scene::getDiffuse(const vector3df& point, const vector3df& normal, const Material* mat)
{
	SColor ret = mat->getColor();

	SColorf light(0,0,0);
	core::list<Light*>::Iterator it;
	for (it = lights.begin(); it != lights.end(); it++)
	{
		float dot = ((*it)->Position - point).normalize().dotProduct(normal);
		if (dot < 0)
			continue;
		SColorf& lightcol = (*it)->Color;
		float coef = dot * (*it)->getIntensity(point);
		light.r += lightcol.r * coef;
		light.g += lightcol.g * coef;
		light.b += lightcol.b * coef;
	}

	ret.set(255,
		(u32)(ret.getRed() * light.r),
		(u32)(ret.getGreen() * light.g),
		(u32)(ret.getBlue() * light.b));
	return ret;
}