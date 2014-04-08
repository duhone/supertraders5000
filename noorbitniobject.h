// noorbitniobject.h: interface for the noorbitniobject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOORBITNIOBJECT_H__7CE3AC68_0977_424B_98E8_15AA76117EE0__INCLUDED_)
#define AFX_NOORBITNIOBJECT_H__7CE3AC68_0977_424B_98E8_15AA76117EE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "niobject.h"

class noorbitniobject : public niobject  
{
public:
	noorbitniobject();
	virtual ~noorbitniobject();
	virtual bool collision(float x,float y);
	virtual float getgravity(float x,float y);
	virtual void cull();
	virtual void draw();
	virtual void viewtransform(float xp,float yp);
	virtual void move();

};

#endif // !defined(AFX_NOORBITNIOBJECT_H__7CE3AC68_0977_424B_98E8_15AA76117EE0__INCLUDED_)
