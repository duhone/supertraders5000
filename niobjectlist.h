// niobjectlist.h: interface for the niobjectlist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NIOBJECTLIST_H__F8813F69_F409_49FE_930F_9C9616CF6D2C__INCLUDED_)
#define AFX_NIOBJECTLIST_H__F8813F69_F409_49FE_930F_9C9616CF6D2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include "niobject.h"

using namespace std;

class niobjectlist  
{
public:
	void settime(float t);
	void getgravity(float x,float y,float &xv,float &yv);
	void cull(float x,float y);
	void draw();
	void viewtans(float xp,float yp);
	void movobjs();
	void remall();
	void remove();
	void add(niobject* arg);
	niobjectlist();
	virtual ~niobjectlist();
private:
	vector<niobject*> *objectlist;

};

#endif // !defined(AFX_NIOBJECTLIST_H__F8813F69_F409_49FE_930F_9C9616CF6D2C__INCLUDED_)
