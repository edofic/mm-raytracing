#include "Renderer.h"

Renderer::Renderer(ITexture* rtt, Camera* cam, int maxDepth, const SColor& back) :
	Texture(rtt), Cam(cam), MaxDepth(maxDepth), Background(back)
{
}

void Renderer::renderScene(Scene* scn)
{
	ray r;
	r.start = Cam->getPosition();

	core::dimension2d<u32> size = Texture->getSize();

	vector3df z = (Cam->getLookat() - Cam->getPosition()).normalize();
	vector3df y = Cam->getUpVector().normalize() * Cam->getRatio() * Cam->getFOV() / (float)size.Width;
	vector3df x = Cam->getUpVector().crossProduct(z).normalize() * Cam->getFOV() / (float)size.Height;

	SColor col(255, 0,0,0);

	r.direction = z;
	int* data = (int*)Texture->lock();
  u32 i;
  #pragma omp parallel for private(i) num_threads(10)
  for (i=0; i<size.Width; i++)
  {
	  for (u32 j=0; j<size.Height; j++)
	  {
		  r.direction = z +
			  ((float)size.Width / 2 - i) * x +
			  ((float)size.Height / 2 - j) * y;
		  col = raytrace(scn, r, 0);
		  data[i + j * size.Width] = col.color;
	  }
  }
  
  #pragma omp barrier
	Texture->unlock();
}

SColor Renderer::raytrace(Scene* scn, ray& r, int depth)
{
	vector3df inter;
	vector3df norm;
	Shape* shape = scn->getNearestIntersection(r, inter);

	if (shape)
	{
		//SColor retcol(255, 0,0,0);
		norm = shape->getNormal(inter);
		//for each light add to col..
		ray reflected;
		reflected.start = inter + 0.00001f*norm; // avoid intersection with current intersection
		reflected.direction = r.direction - 2 * r.direction.dotProduct(norm)*norm;
		SColor c(Background);
		if (depth < MaxDepth)
			c = raytrace(scn, reflected, depth+1);
		return c.getInterpolated(scn->getDiffuse(inter, norm, shape->getMaterial()), shape->getMaterial()->getReflectivity());
	}
	else
		return Background;
}
