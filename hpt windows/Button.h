// Button.h: interface for the Button class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUTTON_H__0783943B_A07D_482A_AA09_96CCDE809487__INCLUDED_)
#define AFX_BUTTON_H__0783943B_A07D_482A_AA09_96CCDE809487__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Window.h"

class Button : public Window  
{
public:
	virtual bool Unclick();
	virtual bool click(float x,float y);
	virtual void Render();
	Button(ButtonInfo* arg,Window *pwin);
	virtual ~Button();
	virtual void SetMousePosition(float x,float y);

protected:
	char *image_name1;
	char *image_name2;
	TRANSFORM *window_transform2;
	SPRITE_OBJECT *window_sprite2;
	TEXTURE_OBJECT *texture2;
	Window *parent_window;
	bool clicked;
	int command;
	int data;

};

#endif // !defined(AFX_BUTTON_H__0783943B_A07D_482A_AA09_96CCDE809487__INCLUDED_)
