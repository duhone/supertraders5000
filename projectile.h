//#include "Engine.h"
#ifndef __projectile_H
#define __projectile_H

#include "MMEngine.h"
#include "graphic_object.h"
class projectile
{

protected:
	TEXTURE_OBJECT *proj_tex;
	//SPRITE_OBJECT *proj_img;
	graphic_object *proj_img;
	int pallettenumber;
	//IMAGE_OBJECT *ship2_basic_img;
	//SPRITE_OBJECT *ship2_basic_spr;
	static float diftime;
public:

	projectile();
	virtual ~projectile();

	bool IS_ACTIVE[50];

	float xvel;
	float yvel;
	float x;
	float y;
	float direct;
	float alpha;
	virtual bool MoveProjectile() = 0;
	virtual void DrawProjectile(float sxp,float syp) = 0;
//	virtual void FireProjectile(float direction,float sxp,float syp,float velocity) = 0;
	void settime(float time);
};

#endif