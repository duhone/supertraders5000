// MinimizeButton.cpp: implementation of the MinimizeButton class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MinimizeButton.h"

extern void (CALLBACK* command_callback)(int command,int data);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MinimizeButton::MinimizeButton(ButtonInfo* arg,Window *pwin)
:Button(arg,pwin)
{

}

MinimizeButton::~MinimizeButton()
{

}

bool MinimizeButton::click(float x,float y)
{
	if(!((x < upper_left_x) || (x > lower_right_x) || (y > upper_left_y)
		|| (y < lower_right_y)))
	{
		clicked = !clicked;
		command_callback(command,clicked);
		parent_window->ToggleMinimize();
		return true;
	}
	return false;
}



void MinimizeButton::EnableWindow(bool arg)
{
	clicked = arg;
}
