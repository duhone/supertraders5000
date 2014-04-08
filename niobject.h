// niobject.h: interface for the niobject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NIOBJECT_H__E7C2D2C1_0C8B_4E2A_B832_BD57E9FCA19D__INCLUDED_)
#define AFX_NIOBJECT_H__E7C2D2C1_0C8B_4E2A_B832_BD57E9FCA19D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class niobject  
{
public:
	virtual void setcolor(float r,float g,float b,float a);
	static void settime(float t);
	virtual bool collision(float x,float y) = 0;
	virtual void getgravity(float x,float y,float &xv,float &yv) = 0;
	virtual void cull(float x,float y) = 0;
	virtual void draw() = 0;
	virtual void viewtransform(float xp,float yp) = 0;
	virtual void move() = 0;
	virtual void setgravstrength(float s) = 0;
	virtual void setorbitpos(float x,float y,float v) = 0;
	virtual void setrotspeed(float sp) = 0;
	virtual void setscale(float xs,float ys) = 0;
	niobject();
	virtual ~niobject();
protected:
	static float diftime;

};

#endif // !defined(AFX_NIOBJECT_H__E7C2D2C1_0C8B_4E2A_B832_BD57E9FCA19D__INCLUDED_)
