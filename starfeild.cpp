#include"starfield.h"
#include<stdlib.h>

//extern ENGINE engine;
extern DISPLAY_ENGINE *display;

float starfield::diftime = 0.0f;

starfield::starfield()
{
	//pixel = engine.CreatePixelObject();
//	createnewstar();
}

starfield::~starfield()
{
	//engine.DestroyPixelObject(pixel);
}

void starfield::createnewstar()
{
	for(int count = 0;count < 400; count++)
	{
		stars[count].createnewstar();
	}
	starlist = display->CreatePointObject();
	starlist->SetBufferSize(400);
	for(count = 0;count < 400;count++)
	{
		starlist->SetParticle(count,400,300,stars[count].getr(),stars[count].getg(),stars[count].getb(),255);
	//	starlist->SetParticleColor(count,255,255,255,255);
	}
	//starlist->RotateAll(0);
	//starlist->ScaleAll(1,1);
	//starlist->TranslateAll(0,0);
	starlist->SetClipMode(AUTO_WRAP);
	/*
	x = (float(rand() % 10240)+1.0f) / 10.0f;
	y = (float(rand() % 7680)+1.0f) / 10.0f;
	v = (float(rand() % 100)+1.0f) / 100.0f;
	r = int(128*v)+127;
	g = int(128*v)+127;
	b = int(128*v)+127;
	*/
}

void starfield::movestar(float xc,float yc)
{
	for(int count = 0;count < 400; count++)
	{
		stars[count].movestar(xc,yc);
		starlist->SetParticle(count,stars[count].getxp(),stars[count].getyp());
	}
//	for(count = 0;count < 400;count++)
//	{
//	}
	/*
	x += xc*v*diftime;
	y += yc*v*diftime;
	if(x > 1023.0f) x = 0.0f;
	if(x < 0.0f) x = 1023.0f;
	if(y > 755.0f) y = 0.0f;
	if( y < 0.0f) y = 755.0f;
	*/
}

void starfield::drawstar()
{
	starlist->RenderBuffer();
	//pixel->DrawPixel(int(x),int(y),r,g,b);
}

void starfield::settime(float time)
{
	diftime = time;
	stars[0].settime(time);
}
