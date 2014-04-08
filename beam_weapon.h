//#include "Engine.h"
#ifndef __beam_weapon_H
#define __beam_weapon_H

#include "MMEngine.h"
#include "projectile.h"
#include "graphic_object.h"

class beam_weapon : public projectile
{

private:
//	TEXTURE_OBJECT *proj_tex;
//	SPRITE_OBJECT *proj_img;
	//IMAGE_OBJECT *ship2_basic_img;
	//SPRITE_OBJECT *ship2_basic_spr;

public:

	beam_weapon(float direction,float sxp,float syp,float velocity,graphic_object *graphobj,int objnumber);
	virtual ~beam_weapon();

//	bool IS_ACTIVE[50];

/*	float xvel;
	float yvel;
	float x;
	float y;
	float direct;
*/	virtual bool MoveProjectile();
	virtual void DrawProjectile(float sxp,float syp);
//	virtual void FireProjectile(float direction,float sxp,float syp,float velocity);
};

#endif