// orbitniobject.cpp: implementation of the orbitniobject class.
//
//////////////////////////////////////////////////////////////////////

#include "orbitniobject.h"
#include<math.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

orbitniobject::orbitniobject(graphic_object* gobj,int palnumb,float xp,float yp)
{
	oni_img = gobj;
	pallettenumber = palnumb;
	xposition = xp;
	yposition = yp;
	xsize = 100;
	ysize = 100;
	rotspeed = 0;
	direction = 0;
	orbittime = 0;
	culled = false;
}

orbitniobject::~orbitniobject()
{

}

void orbitniobject::light()
{
	float cost,sint;
	cost = (float)cos(direction);
	sint = (float)sin(direction);
	cost = 0.7071068f*cost;
	sint = 0.7071068f*sint;
	
	float mag,v2x,v2y;
	v2x = xorbitpos - xposition;
	v2y = yorbitpos - yposition;
	mag = (float)sqrt((v2x*v2x + v2y*v2y));
	if(mag != 0)
	{
		v2x /= mag;
		v2y /= mag;
		
		float v1x,v1y;
		float dot;
		int inten;
		v1x = -cost - sint;
		v1y = -sint + cost;
		dot = v1x*v2x + v1y*v2y;
		//if(dot < 0) dot = 0;
		inten = (int)(dot*127.0f) + 128;
		oni_img->vertexcolor(pallettenumber,0,inten,inten,inten,255);

		v1x = cost - sint;
		v1y = sint + cost;
		dot = v1x*v2x + v1y*v2y;
		//if(dot < 0) dot = 0;
		inten = (int)(dot*127.0f) + 128;
	//	inten = 0;
		oni_img->vertexcolor(pallettenumber,1,inten,inten,inten,255);

		v1x = cost + sint;
		v1y = sint - cost;
		dot = v1x*v2x + v1y*v2y;
		//if(dot < 0) dot = 0;
		inten = (int)(dot*127.0f) + 128;
	//	inten = 0;
		oni_img->vertexcolor(pallettenumber,2,inten,inten,inten,255);

		v1x = -cost + sint;
		v1y = -sint - cost;
		dot = v1x*v2x + v1y*v2y;
		//if(dot < 0) dot = 0;
		inten = (int)(dot*127.0f) + 128;
	//	inten = 0;
		oni_img->vertexcolor(pallettenumber,3,inten,inten,inten,255);

	}
	
}

bool orbitniobject::collision(float x,float y)
{

	return false;
}

void orbitniobject::getgravity(float x,float y,float &xv,float &yv)
{
	float magnitude,xt,yt;
	magnitude = (float)sqrt(((x-xposition) * (x-xposition)) + ((y-yposition) * (y-yposition)));
	if((magnitude < xsize/20.0f) && (magnitude > -xsize/20.0f))
	{
		magnitude = xsize/20.0f;
		xt = (xposition-x)/magnitude;
		yt = (yposition-y)/magnitude;
		xt /= (magnitude*magnitude);
		yt /= (magnitude*magnitude);

	//	xv = yv = 0;
	//	return;
	}
	else
	{

		xt = (xposition-x)/magnitude;
		yt = (yposition-y)/magnitude;
		xt /= (magnitude*magnitude);
		yt /= (magnitude*magnitude);
	}
	xv += xt * gravstrength;
	yv += yt * gravstrength;
}

void orbitniobject::cull(float x,float y)
{
	float magnitude;
	magnitude = (float)sqrt(((x-xposition) * (x-xposition)) + ((y-yposition) * (y-yposition)));
	if(magnitude > ((xsize/20.0f) + 2.0f)) culled = true;
	else culled = false;
}

void orbitniobject::draw()
{
	if(!culled)
	{
		light();
		oni_img->rotate(pallettenumber,direction);
		oni_img->scale(pallettenumber,xsize/1000.0f,ysize/1000.0f);
		oni_img->translate(pallettenumber,xspos,yspos);
		oni_img->render(pallettenumber);
	}
}

void orbitniobject::viewtransform(float xp,float yp)
{
	xspos = xposition - xp;
	yspos = yposition - yp;
}

void orbitniobject::move()
{
	direction += (rotspeed / 500) * diftime;
	if(direction > (2*3.14f)) direction -= (2*3.14f);
	orbittime += diftime;
	if(orbittime >= 100000.0f) orbittime -= 100000;
	xposition = orbitdistance * (float)cos((2*3.14*orbitvelocity*orbittime)/10000.0f) + xorbitpos;
	yposition = orbitdistance * (float)sin((2*3.14*orbitvelocity*orbittime)/10000.0f) + yorbitpos;

}

void orbitniobject::setscale(float xs, float ys)
{
	xsize = xs;
	ysize = ys;
}

void orbitniobject::setrotspeed(float sp)
{
	rotspeed = sp;
}

void orbitniobject::setorbitpos(float x, float y,float v)
{
	xorbitpos = x;
	yorbitpos = y;
	orbitvelocity = v;
	orbitdistance = (float)sqrt(((xposition - xorbitpos) * (xposition - xorbitpos))
			+ ((yposition - yorbitpos) * (yposition - yorbitpos)));
	
	float temp1,temp2;
	if(orbitdistance != 0)
	{
		temp1 = (float)acos((xposition - xorbitpos) / orbitdistance);
		temp2 = (float)asin((yposition - yorbitpos) / orbitdistance);
	}
	if(temp2 < 0.0f) temp1 = 2*(3.14f) - temp1;
	if(orbitvelocity != 0) orbittime = (temp1*10000) / (2*3.14f*orbitvelocity);
}

void orbitniobject::setgravstrength(float s)
{
	gravstrength = s/10;
}

void orbitniobject::setcolor(float r, float g, float b, float a)
{
	red = r;
	green = g;
	blue = b;
	alpha = a;

}
