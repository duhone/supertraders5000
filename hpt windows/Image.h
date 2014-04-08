// Image.h: interface for the Image class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGE_H__B146EC85_7C97_4191_9103_7E4903C8C52E__INCLUDED_)
#define AFX_IMAGE_H__B146EC85_7C97_4191_9103_7E4903C8C52E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Window.h"

class Image : public Window  
{
public:
	virtual void Render();
	Image(ImageInfo* arg,Window *pwin);
	virtual ~Image();
	virtual bool click(float x,float y) {return false;};
	virtual bool Unclick() {return false;};
	virtual void SetMousePosition(float x,float y) {};

private:
	char *image_name;
	Window *parent_window;
};

#endif // !defined(AFX_IMAGE_H__B146EC85_7C97_4191_9103_7E4903C8C52E__INCLUDED_)
