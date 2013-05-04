#include "Light.h"

float Light::getIntensity(const vector3df& p)
{
	float r = p.getDistanceFrom(Position);
	float intensity = Attenuation.X
		- r * Attenuation.Y
		- r * r * Attenuation.Z;
	intensity = core::clamp<float>(intensity, 0.f, 1.f);
	return intensity;
}