#include "Camera.h"

Camera::Camera(const vector3df& pos, const vector3df& lookat,
		const vector3df& up, float fov, float ratio) :
Position(pos), Lookat(lookat), Up(up), FOV(fov), Ratio(ratio)
{
}