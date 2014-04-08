// orbitniobject.h: interface for the orbitniobject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ORBITNIOBJECT_H__B5D608E2_A706_4695_8FEB_189C8C49B3E7__INCLUDED_)
#define AFX_ORBITNIOBJECT_H__B5D608E2_A706_4695_8FEB_189C8C49B3E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "niobject.h"
#include "MMEngine.h"
#include "graphic_object.h"

class orbitniobject : public niobject  
{
public:
	virtual void setcolor(float r,float g,float b,float a);
	void setgravstrength(float s);
	void setorbitpos(float x,float y,float v);
	void setrotspeed(float sp);
	void setscale(float xs,float ys);
	orbitniobject(graphic_object* gobj,int palnumb,float xp,float yp);
	virtual ~orbitniobject();
	virtual bool collision(float x,float y);
	virtual void getgravity(float x,float y,float &xv,float &yv);
	virtual void cull(float x,float y);
	virtual void draw();
	virtual void viewtransform(float xp,float yp);
	virtual void move();

private:
	float alpha;
	float blue;
	float green;
	float red;
	bool culled;
	float gravstrength;
	float orbittime;
	int pallettenumber;
	float xposition,yposition;
	float xspos,yspos;
	float xsize,ysize;
	float rotspeed;
	float direction;
	float orbitdistance;
	float orbitvelocity;
	float xorbitpos,yorbitpos;
	graphic_object* oni_img;
	void light();

};

#endif // !defined(AFX_ORBITNIOBJECT_H__B5D608E2_A706_4695_8FEB_189C8C49B3E7__INCLUDED_)
