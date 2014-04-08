// Slider.h: interface for the Slider class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SLIDER_H__F97F52B1_E724_461C_BA17_E80DF71025F1__INCLUDED_)
#define AFX_SLIDER_H__F97F52B1_E724_461C_BA17_E80DF71025F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Window.h"

class Slider : public Window  
{
public:
	Slider(SliderInfo* arg,Window *pwin);
	virtual ~Slider();
	virtual bool click(float x,float y);
	virtual void SetMousePosition(float x,float y);
	virtual bool Unclick();
	virtual void Render();
	inline virtual int* GetData() {return &data;};
private:
	char *image_name1;
	char *image_name2;
	float mouse_y;
	float mouse_x;
	Window *parent_window;
	bool clicked;
	int command;
	int data;
	int max_value;
	int min_value;
	TRANSFORM *slider_transform1;
	SPRITE_OBJECT *slider_sprite1;
	TEXTURE_OBJECT *texture1;
	TRANSFORM *slider_transform2;
	SPRITE_OBJECT *slider_sprite2;
	TEXTURE_OBJECT *texture2;


};

#endif // !defined(AFX_SLIDER_H__F97F52B1_E724_461C_BA17_E80DF71025F1__INCLUDED_)
