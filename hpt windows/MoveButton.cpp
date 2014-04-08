// MoveButton.cpp: implementation of the MoveButton class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MoveButton.h"

extern void (CALLBACK* command_callback)(int command,int data);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MoveButton::MoveButton(ButtonInfo* arg,Window *pwin)
:Button(arg,pwin)
{

}

MoveButton::~MoveButton()
{

}

bool MoveButton::click(float x,float y)
{
	if(!((x < upper_left_x) || (x > lower_right_x) || (y > upper_left_y)
		|| (y < lower_right_y)))
	{
		clicked = true;
		return true;
	}
	return false;
}

void MoveButton::SetMousePosition(float x,float y)
{
	if(!clicked)
	{
		mouse_x = x;
		mouse_y = y;
	}
	else
	{
		parent_window->MoveWindow(x-mouse_x,y-mouse_y);
		mouse_x = x;
		mouse_y = y;
		upper_left_x = x_location - (50*x_scale)+parent_window->GetXLoc();
		upper_left_y = y_location + (50*y_scale)+parent_window->GetYLoc();
		lower_right_x = x_location + (50*x_scale)+parent_window->GetXLoc();
		lower_right_y = y_location - (50*y_scale)+parent_window->GetYLoc();

	}

}
