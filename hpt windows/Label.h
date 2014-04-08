// Label.h: interface for the Label class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LABEL_H__BF165ABB_7AA0_4B7C_910A_BA4D174B2169__INCLUDED_)
#define AFX_LABEL_H__BF165ABB_7AA0_4B7C_910A_BA4D174B2169__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Window.h"

class Label : public Window  
{
public:
	virtual void Render();
	Label(LabelInfo* arg,Window *pwin);
	virtual ~Label();
	virtual bool click(float x,float y) {return false;};
	virtual bool Unclick() {return false;};
	virtual void SetMousePosition(float x,float y) {};

private:
	Window * parent_window;
	char * label_name;
	TEXT_OBJECT *text;
	float char_x_scale;
	float char_y_scale;

};

#endif // !defined(AFX_LABEL_H__BF165ABB_7AA0_4B7C_910A_BA4D174B2169__INCLUDED_)
