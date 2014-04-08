// Window.h: interface for the Window class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDOW_H__BA685B8B_D030_41DC_87BA_ABC5B92EB1BE__INCLUDED_)
#define AFX_WINDOW_H__BA685B8B_D030_41DC_87BA_ABC5B92EB1BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"windowsengine.h"
//#include"minimizebutton.h"

#include"display.h"
#include<list>
using namespace std;

extern DISPLAY_ENGINE *d_engine;

#define WINDOW 0
#define BUTTON 1
#define IMAGE 2
#define LABEL 3
#define RADIOBUTTON 4
#define SLIDER 5
#define TEXTBOX 6

class Window  
{
public:
	virtual void EnableWindow(bool arg);
	float GetUpperY();
	bool IsClosed();
	void Close();
	void MoveWindow(float x,float y);
	virtual void SetMousePosition(float x,float y);
	void ToggleMinimize();
	virtual bool click(float x,float y);
	virtual bool Unclick();
	void AddSubWindow(Window* arg);
	void AddMinimizeWindow(Window* arg);
	virtual void Render();
	Window();
	Window(WindowInfo *arg);
	virtual ~Window();
	inline int GetId() {return id;};
	inline float GetXLoc() {return x_location;};
	inline float GetYLoc() {return y_location;};
	inline float GetXScale() {return x_scale;};
	inline float GetYScale() {return y_scale;};

protected:
	int id;
	int type;
	bool movable_minimizable;
	float y_scale;
	float x_scale;
	float y_location;
	float x_location;
	TEXTURE_OBJECT *back_texture;
	SPRITE_OBJECT *window_sprite;
	TRANSFORM *window_transform;
	float back_color_alpha;
	float back_color_blue;
	float back_color_green;
	float back_color_red;
	int command_id;
	list<Window*> sub_window_list;
	float upper_left_x;
	float upper_left_y;
	float lower_right_x;
	float lower_right_y;
	bool clicked;
	Window *minimize_button;
	bool minimized;
private:
	bool enabled;
	bool closed;
	};

#endif // !defined(AFX_WINDOW_H__BA685B8B_D030_41DC_87BA_ABC5B92EB1BE__INCLUDED_)
