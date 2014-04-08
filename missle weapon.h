//#include "Engine.h"
#ifndef __missle_weapon_H
#define __missle_weapon_H

#include "MMEngine.h"
#include "projectile.h"

class missle_weapon : public projectile
{

private:
//	TEXTURE_OBJECT *proj_tex;
//	SPRITE_OBJECT *proj_img;
	//IMAGE_OBJECT *ship2_basic_img;
	//SPRITE_OBJECT *ship2_basic_spr;

public:

	missle_weapon(float direction,float sxp,float syp,float xv,float yv,graphic_object *graphobj,int objnumber);
	virtual ~missle_weapon();

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