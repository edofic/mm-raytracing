#ifndef _RENDERER_H_INCL
#define _RENDERER_H_INCL

#include <irrlicht.h>
using namespace irr;
using namespace video;
using core::vector3df;

#include "Scene.h"
#include "Camera.h"

class Renderer
{
public:
	Renderer(ITexture* rtt, Camera* cam, int maxDepth = 5,
		const SColor& back = SColor(255, 50,50,50));

	void renderScene(Scene* scn);
	SColor raytrace(Scene* scn, ray& r, int depth);

private:
	ITexture* Texture; // RTT texture
	Camera* Cam; // active camera
	int MaxDepth;
	SColor Background;
};

#endif