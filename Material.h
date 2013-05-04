#ifndef _MATERIAL_H_INCL
#define _MATERIAL_H_INCL

#include <irrlicht.h>
using namespace irr;
using video::SColor;

class Material
{
public:
	Material(float ref, float trans, const SColor& col) :
	  Reflectivity(ref), Translucency(trans), Color(col) {}

	float getReflectivity() const { return Reflectivity; }
	float getTranslucency() const { return Translucency; }
	SColor getColor() const { return Color; }

	void setReflectivity(float ref) { Reflectivity = ref; }
	void setTranslucency(float trans) { Translucency = trans; }
	SColor setColor(const SColor& col) { Color = col; }

private:
	float Reflectivity;
	float Translucency;
	SColor Color;
};

#endif