// niobjectlist.cpp: implementation of the niobjectlist class.
//
//////////////////////////////////////////////////////////////////////

#include "niobjectlist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include <vector>
niobjectlist::niobjectlist()
{
	objectlist = new vector<niobject*>;
}

niobjectlist::~niobjectlist()
{
	niobject* temp = NULL;
	for(int count = 0;count < objectlist->size();count++)
	{
		temp = objectlist->at(count);
		delete temp;
	}

	delete objectlist;
}

void niobjectlist::add(niobject* arg)
{
	objectlist->push_back(arg);	
}

void niobjectlist::remove()
{

}

void niobjectlist::remall()
{

}

void niobjectlist::movobjs()
{
	for(int count = 0;count < objectlist->size();count++)
	{
		objectlist->at(count)->move();
	}

}

void niobjectlist::viewtans(float xp,float yp)
{
	for(int count = 0;count < objectlist->size();count++)
	{
		objectlist->at(count)->viewtransform(xp,yp);
	}

}

void niobjectlist::draw()
{
	for(int count = 0;count < objectlist->size();count++)
	{
		objectlist->at(count)->draw();
	}
}

void niobjectlist::cull(float x,float y)
{
	for(int count = 0;count < objectlist->size();count++)
	{
		objectlist->at(count)->cull(x,y);
	}
}

void niobjectlist::getgravity(float x,float y,float &xv,float &yv)
{
	float xt,yt;
	xt = yt = 0;
	for(int count = 0;count < objectlist->size();count++)
	{
		objectlist->at(count)->getgravity(x,y,xt,yt);
	}
	xv = xt;
	yv = yt;

}

void niobjectlist::settime(float t)
{
		if(objectlist->size() != 0)
			objectlist->at(0)->settime(t);

}
