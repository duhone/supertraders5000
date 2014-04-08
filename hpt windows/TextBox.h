// TextBox.h: interface for the TextBox class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTBOX_H__3798136E_D0A5_40AE_9B22_CDBDDA1CF2FF__INCLUDED_)
#define AFX_TEXTBOX_H__3798136E_D0A5_40AE_9B22_CDBDDA1CF2FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Window.h"
#include"vectorgraphlib.h"
#include"label.h"

class TextBox : public Window  
{
public:
	TextBox(VectorGraphC *arg,Window *pwin);
	virtual ~TextBox();
	virtual bool Unclick();
	virtual bool click(float x,float y);
	virtual void Render();
	virtual void SetMousePosition(float x,float y);
private:
	Label *text;
	vector<Label*> responses;
	VectorGraphC nodes;
	Window *parent_window;
	LabelInfo text_info;
};

#endif // !defined(AFX_TEXTBOX_H__3798136E_D0A5_40AE_9B22_CDBDDA1CF2FF__INCLUDED_)
