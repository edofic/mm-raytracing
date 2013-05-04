#include "SPlane.h"

SPlane::SPlane(const core::vector3df& orig, const core::vector3df& norm, Material* mat) :
Shape(mat), Origin(orig), Normal(norm)
{
	Normal = Normal.normalize();
}

bool SPlane::getIntersection(const ray& ray, core::vector3df& result)
{
	float lambda = (Origin - ray.direction).dotProduct(Normal) / ray.direction.dotProduct(Normal);
	result = ray.start + lambda * ray.direction;
	return true;
}