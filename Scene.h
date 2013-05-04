#ifndef _SCENE_H_INCL
#define _SCENE_H_INCL

#include <irrlicht.h>
using namespace irr;

#include "Shape.h"
#include "Light.h"
#include "ray.h"

class Scene
{
public:
	Scene() {}
	~Scene() {}

	Shape* getNearestIntersection(ray& ray, vector3df& inter);
	SColor getDiffuse(const vector3df& point, const vector3df& normal, const Material* mat);

	void addLight(Light* light)
	{
		lights.push_back(light);
	}

	void addShape(Shape* shape)
	{
		shapes.push_back(shape);
	}

private:
	core::list<Light*> lights;
	core::list<Shape*> shapes;
};

#endif