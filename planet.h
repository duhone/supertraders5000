//#include"engine.h"
#include "MMEngine.h"
#include "graphic_object.h"

class planet
{

private:
	//IMAGE_OBJECT *plan_img;
//	TEXTURE_OBJECT *plan_tex;
//	SPRITE_OBJECT *plan_img;
	graphic_object* plan_img;
	int pallettenumber;
public:

	planet(graphic_object* gobj,int palnumb);
	~planet();


	float x;
	float y;
	float xs,ys;
	void moveplanet();
	void transformplanet(float xp,float yp);
	void drawplanet();
};