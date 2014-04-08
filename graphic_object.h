// graphic_object.h: interface for the graphic_object class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHIC_OBJECT_H__652F5820_8DBB_11D5_A7F7_A6C5B16D9043__INCLUDED_)
#define AFX_GRAPHIC_OBJECT_H__652F5820_8DBB_11D5_A7F7_A6C5B16D9043__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MMEngine.h"

#define frames1 0
#define frames4 1
#define frames16 2
#define frames64 3
#define frames256 4

class graphic_object  
{
public:
	void settime(float newtime);
	virtual void  vertexcolor(int objnumb,int vertnumb,int r,int g,int b,int a);
	virtual void render(int objnumer);
	virtual void scale(int objnumber,float x,float y);
	virtual void rotate(int objnumber,float theta);
	virtual void translate(int objnumber,float x,float y);
	graphic_object();
	virtual ~graphic_object();
	virtual void loadobject(int objnumber,const char* filename,int numframes);
private:
	float curfliptime[512];
	float fliptime[512];
	float diftime;
	graphic_object(const graphic_object& arg) {};
	TEXTURE_OBJECT *tex_obj[512];
	SPRITE_OBJECT *sprite_obj[512];
	TRANSFORM *trans_obj[512];
	graphic_object& operator=(const graphic_object& arg) {};
};

#endif // !defined(AFX_GRAPHIC_OBJECT_H__652F5820_8DBB_11D5_A7F7_A6C5B16D9043__INCLUDED_)
