// MinimizeButton.h: interface for the MinimizeButton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MINIMIZEBUTTON_H__06BE1007_1512_4B7D_BD07_1873231A7CFE__INCLUDED_)
#define AFX_MINIMIZEBUTTON_H__06BE1007_1512_4B7D_BD07_1873231A7CFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Button.h"

class MinimizeButton : public Button  
{
public:
	virtual void EnableWindow(bool arg);
	MinimizeButton(ButtonInfo* arg,Window *pwin);
	virtual ~MinimizeButton();
	virtual bool click(float x,float y);
	virtual void SetMousePosition(float x,float y) {};

};

#endif // !defined(AFX_MINIMIZEBUTTON_H__06BE1007_1512_4B7D_BD07_1873231A7CFE__INCLUDED_)
