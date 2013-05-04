#ifndef _CAMERA_H_INCL
#define _CAMERA_H_INCL

#include <irrlicht.h>
using namespace irr;
using core::vector3df;

class Camera
{
public:
	Camera(const vector3df& pos, const vector3df& lookat,
		const vector3df& up = vector3df(0,0,1),
		float fov = 1.f, float ratio = 1.77f);

	vector3df getPosition() { return Position; }
	vector3df getLookat() { return Lookat; }
	vector3df getUpVector() { return Up; }
	float getFOV() { return FOV; }
	float getRatio() { return Ratio; }

	void setPosition(const vector3df& pos) { Position = pos; }
	void setLookat(const vector3df& lookat) { Lookat = lookat; }
	void setUpVector(const vector3df& up) { Up = up; }
	void setFOV(float fov) { FOV = fov; }
	void setRatio(float ratio) { Ratio = ratio; }

private:
	vector3df Position;
	vector3df Lookat;
	vector3df Up;
	float FOV;
	float Ratio;
};

#endif