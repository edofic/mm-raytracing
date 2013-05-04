#include <irrlicht.h>
#pragma comment(lib, "irrlicht.lib")

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

#include "SSphere.h"
#include "SPlane.h"
#include "ray.h"
#include "Scene.h"
#include "Camera.h"
#include "Renderer.h"

#define W 200
#define H 200

int main()
{
	IrrlichtDevice* device = createDevice(EDT_OPENGL, dimension2d<u32>(W,H));
	ISceneManager* smgr = device->getSceneManager();
	IVideoDriver* driver = device->getVideoDriver();

	ITexture* rtt = driver->addTexture(dimension2d<u32>(W,H), "rtt");
	Camera cam(vector3df(3, 6, 6), vector3df(0,0,0));
	ICameraSceneNode* irrCam = smgr->addCameraSceneNodeFPS();
	irrCam->setTarget(cam.getLookat());
	irrCam->setUpVector(cam.getUpVector());
	irrCam->setPosition(cam.getPosition());
	Renderer r(rtt, &cam);

	Material* basicMat = new Material(0.3f, 0.f,
		SColor(255, 255,0,0));
	Material* floorMat = new Material(0.8f, 0.f,
		SColor(255, 200,200,200));

	Scene scn;
	for (float i=0; i<1.5f*PI; i+=PI/8)
	{
		SSphere* sph = new SSphere(
			vector3df(i*cos(i), i*sin(i), i*0.2f),
			i*0.2f,
			basicMat);
		scn.addShape(sph);
	}

	scn.addShape(new SPlane(vector3df(0,0,-10),
		vector3df(0,0,1),
		floorMat));

	scn.addLight(new Light(
		vector3df(0,0,5),
		vector3df(1,0.01f,0.01f),
		SColorf(1.f,1.f,1.f)));

	float phi = 0;
	while (device->run())
	{
		r.renderScene(&scn);

		driver->beginScene();
		cam.setPosition(irrCam->getPosition());
    cam.setLookat(irrCam->getTarget()); 
		driver->draw2DImage(rtt, vector2d<s32>());
		smgr->drawAll();
		driver->endScene();
	}
}
