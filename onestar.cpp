#include"onestar.h"
#include<stdlib.h>

//extern ENGINE engine;

float onestar::diftime = 0.0f;

onestar::onestar()
{
	//pixel = engine.CreatePixelObject();
	createnewstar();
}

onestar::~onestar()
{
	//engine.DestroyPixelObject(pixel);
}

void onestar::createnewstar()
{
	x = (float(rand() % 40)-20.0f) / 10.0f;
	y = (float(rand() % 30)-15.0f) / 10.0f;
	v = (float(rand() % 100)+1.0f) / 100.0f;
	r = int(254*v)+1;
	g = int(254*v)+1;
	b = int(254*v)+1;
	
}

void onestar::movestar(float xc,float yc)
{
	x += -xc*v*diftime*0.01f;
	y += -yc*v*diftime*0.01f;
	if(x > 2.0f) x = -2.0f;
	if(x < -2.0f) x = 2.0f;
	if(y > 1.5f) y = -1.5f;
	if( y < -1.5f) y = 1.5f;
//	x= 400;
//  y = 300;
}

/*void starfield::drawstar()
{
	//pixel->DrawPixel(int(x),int(y),r,g,b);
}
*/

void onestar::settime(float time)
{
	diftime = time;
}

int onestar::getb()
{
	return b;
}

int onestar::getg()
{
	return g;
}

int onestar::getr()
{
	return r;
}

/*float onestar::getxp()
{
	return x;
}

float onestar::getyp()
{
	return y;
}
*/