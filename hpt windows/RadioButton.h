// RadioButton.h: interface for the RadioButton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RADIOBUTTON_H__6747F968_B0CB_427B_8BDA_80266F2E2207__INCLUDED_)
#define AFX_RADIOBUTTON_H__6747F968_B0CB_427B_8BDA_80266F2E2207__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Window.h"
#include "display.h"

class RadioButton : public Window  
{
public:
	RadioButton(RadioButtonInfo* arg,Window *pwin);
	virtual ~RadioButton();
	virtual bool Unclick();
	virtual bool click(float x,float y);
	virtual void Render();
	virtual void SetMousePosition(float x,float y);
private:
	int max_buttons;
	int num_buttons;
	char *image_name1;
	char *image_name2;
	Window *parent_window;
	bool clicked;
	int command;
	int data;
	vector<TRANSFORM*> transforms;
	vector<SPRITE_OBJECT*> sprites;
	TEXTURE_OBJECT *texture1;
	TEXTURE_OBJECT *texture2;
};

#endif // !defined(AFX_RADIOBUTTON_H__6747F968_B0CB_427B_8BDA_80266F2E2207__INCLUDED_)
