// cursor_class.h: interface for the cursor_class class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CURSOR_CLASS_H__B7ABBD20_901B_11D5_A7F7_EA749816DD4F__INCLUDED_)
#define AFX_CURSOR_CLASS_H__B7ABBD20_901B_11D5_A7F7_EA749816DD4F__INCLUDED_

#include "graphic_object.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class cursor_class  
{
public:
	void modify_speed(float new_speed);
	void enable_cursor(bool enabled);
	void move_cursor(float x,float y);
	cursor_class(graphic_object *graphobj,int objnumber);
	virtual ~cursor_class();
	void draw_cursor();

private:
	float cursor_speed;
	int pallette_number;
	bool cur_enabled;
	float yposition;
	float xposition;
	graphic_object* cur_img;
};

#endif // !defined(AFX_CURSOR_CLASS_H__B7ABBD20_901B_11D5_A7F7_EA749816DD4F__INCLUDED_)
