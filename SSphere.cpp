#include "SSphere.h"

bool SSphere::getIntersection(const ray& ray, core::vector3df& result)
{
	core::list<core::vector3df> points;
	core::vector3df oc = ray.start - Center;
	float a = ray.direction.dotProduct(ray.direction);
	float b = 2 * oc.dotProduct(ray.direction);
	float c = oc.dotProduct(oc) - Radius * Radius;
	float D = b * b - 4 * a * c;
	if (D < 0)
		return false;

	float sqD = sqrt(D);
	float t0 = (-b + sqD) / (2.f * a);
	float t1 = (-b - sqD) / (2.f * a);

	if (t0 > t1)
	{
		float T = t0;
		t0 = t1;
		t1 = T;
	}

	if (t1 < 0)
		return false;
	if (t0 < 0)
		result = ray.start + t1 * ray.direction;
	else
		result = ray.start + t0 * ray.direction;
	return true;
}

core::vector3df SSphere::getNormal(const core::vector3df& point)
{
	return (point - Center).normalize();
}

