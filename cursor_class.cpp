// cursor_class.cpp: implementation of the cursor_class class.
//
//////////////////////////////////////////////////////////////////////

#include "cursor_class.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cursor_class::cursor_class(graphic_object *graphobj,int objnumber)
{
	cur_img = graphobj;
	pallette_number = objnumber;
	xposition = 0;
	yposition = 0;
	cursor_speed = 0.01f;
	cur_enabled = true;
}

cursor_class::~cursor_class()
{

}

void cursor_class::move_cursor(float x, float y)
{
	if(cur_enabled)
	{
		xposition += x * cursor_speed;
		if(xposition < -2.0f) xposition = -2.0f;
		if(yposition < -1.5f) yposition = -1.5f;
		if(xposition > 2.0f) xposition = 2.0f;
		if(yposition > 1.5f) yposition = 1.5f;
		yposition += y * cursor_speed;
	}
}

void cursor_class::draw_cursor()
{
	if(cur_enabled)
	{
		cur_img->translate(pallette_number,xposition,yposition);
		cur_img->scale(pallette_number,0.001f,0.001f);
		cur_img->render(pallette_number);
	}

}

void cursor_class::enable_cursor(bool enabled)
{
	cur_enabled = enabled;
}

void cursor_class::modify_speed(float new_speed)
{
	cursor_speed = new_speed;

}
