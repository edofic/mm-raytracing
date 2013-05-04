#ifndef _RAY_H_INCL
#define _RAY_H_INCL

#include <irrlicht.h>
using namespace irr;

struct ray
{
	core::vector3df start;
	core::vector3df direction;
};

#endif