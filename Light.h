#ifndef _LIGHT_H_INCL
#define _LIGHT_H_INCL

#include <irrlicht.h>
using namespace irr;
using core::vector3df;
using video::SColorf;

struct Light
{
	Light(const vector3df& position,
		const vector3df& attenuation = vector3df(1,0,0),
		const SColorf& color = SColorf(1.f,1.f,1.f,1.f)) :
	Position(position), Attenuation(attenuation), Color(color)
	{
	}

	float getIntensity(const vector3df& p);

	vector3df Position;
	vector3df Attenuation;
	SColorf Color;
};

#endif