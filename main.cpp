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

#define W 350
#define H 200

int main()
{
	IrrlichtDevice* device = createDevice(EDT_OPENGL, dimension2d<u32>(W,H));
	ISceneManager* smgr = device->getSceneManager();
	IVideoDriver* driver = device->getVideoDriver();

	ITexture* rtt = driver->addTexture(dimension2d<u32>(W,H), "rtt");
	Camera cam(vector3df(3, 6, 6), vector3df(0,0,0));
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
		driver->draw2DImage(rtt, vector2d<s32>());
		driver->endScene();
	}

	/*ray r;
	r.direction.X = 1;

	SSphere s(vector3df(10,0,0), 2);
	//SPlane s(vector3df(10,0,0), vector3df(-1,1,1));
	core::vector3df light(5,3,5);

	ITexture* rtt = driver->addTexture(dimension2d<u32>(W,H), "rtt");

	SColor col;
	vector3df inter;

	float phi = 0;
	unsigned int counter = 0;
	while (device->run())
	{
		if (device->isWindowActive())
		{
			float dt = device->getTimer()->getSpeed();

			phi += dt * 0.1f;
			light.set(5, 3*sin(phi), 5*cos(phi));
			s.setCenter(vector3df(10+sin(phi*0.5f),
				0.2f*cos(phi*0.4f),
				cos(phi*0.7f)));

			// raytrace
			int* data = (int*)rtt->lock();
			for (int i=0; i<W; i++)
			{
				for (int j=0; j<H; j++)
				{
					r.direction.Y = (i - W/2) * 0.01f;
					r.direction.Z = (j - H/2) * 0.01f;
					bool isInter = s.getIntersection(r, inter);
					if (!isInter)
						col.set(255, 255,255,255);
					else
					{
						float d = s.getNormal(inter).dotProduct((light - inter).normalize());
						if (d < 0)
							d = 0;
						col.set(255, 255*d,127*d,39*d);
					}
					data[i+W*j] = col.color;
				}
			}
			rtt->unlock();

			// render

			driver->beginScene(true, true, SColor(255, 255,255,255));
			smgr->drawAll();
			driver->draw2DImage(rtt, vector2d<s32>());
			driver->endScene();

			stringw caption;
			caption += counter++;
			device->setWindowCaption(caption.c_str());
		}
		else
			device->yield();
	}*/
}