//#include "engine.h"
#include "MMEngine.h"

#include "onestar.h"

class starfield
{
private:
	float x,y,v;
	int xs,ys;
	int r,g,b;
	static float diftime;
	onestar stars[400];
	PARTICLE_OBJECT *starlist;
	//PIXEL_OBJECT* pixel;
protected:
public:
	starfield();
	~starfield();
	void settime(float time);
	void createnewstar();
	void movestar(float xc,float yc);
	void drawstar();
};
