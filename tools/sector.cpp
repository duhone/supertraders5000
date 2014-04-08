//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "sector.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

sector::sector()
{
 objectlist = new TList;
 numobjects = 0;
}

sector::~sector()
{
 object* oldobject;
 for(int count = 0;count < objectlist->Count;count++)
 {
    if((object*)objectlist->Items[count] != NULL)
    {
        oldobject = (object*)objectlist->Items[count];
        delete oldobject;
    }
 }
 delete objectlist;
}

void sector::addobject()
{
    object* newobject;
    newobject = new object;
    newobject->orbitobj = true;
    newobject->pallettenumb = 0;
    newobject->xposition = 0;
    newobject->yposition = 0;
    newobject->xorbit = 0;
    newobject->yorbit = 0;
    newobject->gravity = 0;
    newobject->xsize = 0;
    newobject->ysize = 0;
    newobject->speed = 0;
    newobject->rotspeed = 0;
    newobject->rcolor1 = 255;
    newobject->rcolor2 = 255;
    newobject->rcolor3 = 255;
    newobject->rcolor4 = 255;
    newobject->gcolor1 = 255;
    newobject->gcolor2 = 255;
    newobject->gcolor3 = 255;
    newobject->gcolor4 = 255;
    newobject->bcolor1 = 255;
    newobject->bcolor2 = 255;
    newobject->bcolor3 = 255;
    newobject->bcolor4 = 255;
    newobject->acolor1 = 255;
    newobject->acolor2 = 255;
    newobject->acolor3 = 255;
    newobject->acolor4 = 255;
    objectlist->Capacity = objectlist->Count + 1;
    objectlist->Add(newobject);
}

void sector::deleteobject(int objnumb)
{
    if(objnumb <= (objectlist->Count - 1))
    {
        object* oldobject;
        oldobject = (object*)objectlist->Items[objnumb/*(objectlist->Count - 1)*/];
        delete oldobject;
        objectlist->Delete(objnumb/*(objectlist->Count - 1)*/);
    }
}

float sector::getxposition(int objnumb)
{
    float returnnumb = 0;
    if(objnumb <= (objectlist->Count - 1))
    {
        returnnumb = ((object*)objectlist->Items[objnumb])->xposition;
    }
    return returnnumb;
}

void sector::setxposition(int objnumb,float newpos)
{

    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->xposition = newpos;
    }
}

float sector::getyposition(int objnumb)
{
    float returnnumb = 0;
    if(objnumb <= (objectlist->Count - 1))
    {
        returnnumb = ((object*)objectlist->Items[objnumb])->yposition;
    }
    return returnnumb;
}

void sector::setyposition(int objnumb,float newpos)
{

    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->yposition = newpos;
    }
}

float sector::getxorbit(int objnumb)
{
    float returnnumb = 0;
    if(objnumb <= (objectlist->Count - 1))
    {
        returnnumb = ((object*)objectlist->Items[objnumb])->xorbit;
    }
    return returnnumb;
}

void sector::setxorbit(int objnumb,float newpos)
{

    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->xorbit = newpos;
    }
}

float sector::getyorbit(int objnumb)
{
    float returnnumb = 0;
    if(objnumb <= (objectlist->Count - 1))
    {
        returnnumb = ((object*)objectlist->Items[objnumb])->yorbit;
    }
    return returnnumb;
}

void sector::setyorbit(int objnumb,float newpos)
{

    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->yorbit = newpos;
    }
}

float sector::getxsize(int objnumb)
{
    float returnnumb = 0;
    if(objnumb <= (objectlist->Count - 1))
    {
        returnnumb = ((object*)objectlist->Items[objnumb])->xsize;
    }
    return returnnumb;
}

void sector::setxsize(int objnumb,float newpos)
{

    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->xsize = newpos;
    }
}

float sector::getysize(int objnumb)
{
    float returnnumb = 0;
    if(objnumb <= (objectlist->Count - 1))
    {
        returnnumb = ((object*)objectlist->Items[objnumb])->ysize;
    }
    return returnnumb;
}

void sector::setysize(int objnumb,float newpos)
{

    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->ysize = newpos;
    }
}

int sector::getpallete(int objnumb)
{
    int returnnumb = 0;
    if(objnumb <= (objectlist->Count - 1))
    {
        returnnumb = ((object*)objectlist->Items[objnumb])->pallettenumb;
    }
    return returnnumb;
}

void sector::setpallete(int objnumb,int newpos)
{

    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->pallettenumb = newpos;
    }
}

float sector::getgravity(int objnumb)
{
    int returnnumb = 0;
    if(objnumb <= (objectlist->Count - 1))
    {
        returnnumb = ((object*)objectlist->Items[objnumb])->gravity;
    }
    return returnnumb;
}

void sector::setgravity(int objnumb,float newpos)
{

    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->gravity = newpos;
    }
}

void sector::setcolor1(int objnumb,int r,int g,int b,int a)
{

    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->rcolor1 = r;
        ((object*)objectlist->Items[objnumb])->gcolor1 = g;
        ((object*)objectlist->Items[objnumb])->bcolor1 = b;
        ((object*)objectlist->Items[objnumb])->acolor1 = a;

    }
}

void sector::getcolor1(int objnumb,int& r,int& g,int& b,int& a)
{
    if(objnumb <= (objectlist->Count - 1))
    {
        r = ((object*)objectlist->Items[objnumb])->rcolor1;
        g = ((object*)objectlist->Items[objnumb])->gcolor1;
        b = ((object*)objectlist->Items[objnumb])->bcolor1;
        a = ((object*)objectlist->Items[objnumb])->acolor1;
    }
}

void sector::setcolor2(int objnumb,int r,int g,int b,int a)
{

    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->rcolor2 = r;
        ((object*)objectlist->Items[objnumb])->gcolor2 = g;
        ((object*)objectlist->Items[objnumb])->bcolor2 = b;
        ((object*)objectlist->Items[objnumb])->acolor2 = a;

    }
}

void sector::getcolor2(int objnumb,int& r,int& g,int& b,int& a)
{
    if(objnumb <= (objectlist->Count - 1))
    {
        r = ((object*)objectlist->Items[objnumb])->rcolor2;
        g = ((object*)objectlist->Items[objnumb])->gcolor2;
        b = ((object*)objectlist->Items[objnumb])->bcolor2;
        a = ((object*)objectlist->Items[objnumb])->acolor2;
    }
}

void sector::setcolor3(int objnumb,int r,int g,int b,int a)
{

    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->rcolor3 = r;
        ((object*)objectlist->Items[objnumb])->gcolor3 = g;
        ((object*)objectlist->Items[objnumb])->bcolor3 = b;
        ((object*)objectlist->Items[objnumb])->acolor3 = a;

    }
}

void sector::getcolor3(int objnumb,int& r,int& g,int& b,int& a)
{
    if(objnumb <= (objectlist->Count - 1))
    {
        r = ((object*)objectlist->Items[objnumb])->rcolor3;
        g = ((object*)objectlist->Items[objnumb])->gcolor3;
        b = ((object*)objectlist->Items[objnumb])->bcolor3;
        a = ((object*)objectlist->Items[objnumb])->acolor3;
    }
}

void sector::setcolor4(int objnumb,int r,int g,int b,int a)
{

    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->rcolor4 = r;
        ((object*)objectlist->Items[objnumb])->gcolor4 = g;
        ((object*)objectlist->Items[objnumb])->bcolor4 = b;
        ((object*)objectlist->Items[objnumb])->acolor4 = a;

    }
}

void sector::getcolor4(int objnumb,int& r,int& g,int& b,int& a)
{
    if(objnumb <= (objectlist->Count - 1))
    {
        r = ((object*)objectlist->Items[objnumb])->rcolor4;
        g = ((object*)objectlist->Items[objnumb])->gcolor4;
        b = ((object*)objectlist->Items[objnumb])->bcolor4;
        a = ((object*)objectlist->Items[objnumb])->acolor4;
    }
}

float sector::getspeed(int objnumb)
{
    float returnval;
    if(objnumb <= (objectlist->Count - 1))
    {
        returnval = ((object*)objectlist->Items[objnumb])->speed;
    }
    return returnval;
}

void sector::setspeed(int objnumb,float s)
{
    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->speed = s;
    }
}

float sector::getrotspeed(int objnumb)
{
    float returnval;
    if(objnumb <= (objectlist->Count - 1))
    {
        returnval = ((object*)objectlist->Items[objnumb])->rotspeed;
    }
    return returnval;
}

void sector::setrotspeed(int objnumb,float s)
{
    if(objnumb <= (objectlist->Count - 1))
    {
        ((object*)objectlist->Items[objnumb])->rotspeed = s;
    }
}

void sector::writeinfo(void* &filepntr)
{
  float* floatpntr;
  int* intpntr;
  floatpntr = (float*)filepntr;
  intpntr = (int*)filepntr;

  object* oldobject;
   *intpntr = objectlist->Count;
    intpntr += 1;
    floatpntr += 1;
    (int*)filepntr += 1;

  for(int count = 0;count < objectlist->Count;count++)
  {

    if((object*)objectlist->Items[count] != NULL)
    {
        oldobject = (object*)objectlist->Items[count];
        *(intpntr) = oldobject->pallettenumb;
        *(intpntr+1) = oldobject->orbitobj;
        *(floatpntr+2) = oldobject->xposition;
        *(floatpntr+3) = oldobject->yposition;
        *(floatpntr+4) = oldobject->xorbit;
        *(floatpntr+5) = oldobject->yorbit;
        *(floatpntr+6) = oldobject->gravity;
        *(floatpntr+7) = oldobject->xsize;
        *(floatpntr+8) = oldobject->ysize;
        *(intpntr+9) = oldobject->rcolor1;
        *(intpntr+10) = oldobject->rcolor2;
        *(intpntr+11) = oldobject->rcolor3;
        *(intpntr+12) = oldobject->rcolor4;
        *(intpntr+13) = oldobject->gcolor1;
        *(intpntr+14) = oldobject->gcolor2;
        *(intpntr+15) = oldobject->gcolor3;
        *(intpntr+16) = oldobject->gcolor4;
        *(intpntr+17) = oldobject->bcolor1;
        *(intpntr+18) = oldobject->bcolor2;
        *(intpntr+19) = oldobject->bcolor3;
        *(intpntr+20) = oldobject->bcolor4;
        *(intpntr+21) = oldobject->acolor1;
        *(intpntr+22) = oldobject->acolor2;
        *(intpntr+23) = oldobject->acolor3;
        *(intpntr+24) = oldobject->acolor4;
        *(floatpntr+25) = oldobject->speed;
        *(floatpntr+26) = oldobject->rotspeed;
        intpntr += 27;
        floatpntr += 27;
        (int*)filepntr += 27;
    }
  }

}


void sector::readinfo(void* &filepntr)
{
  float* floatpntr;
  int* intpntr;
  floatpntr = (float*)filepntr;
  intpntr = (int*)filepntr;

  object* newobject;
  objectlist->Capacity = (*intpntr) + 1;
  int loopcount = *intpntr;
  intpntr += 1;
  floatpntr += 1;
  (int*)filepntr += 1;

  for(int count = 0;count < loopcount;count++)
  {

        newobject = new object();
        newobject->pallettenumb = *(intpntr);
        newobject->orbitobj =  *(intpntr+1) ;
        newobject->xposition =  *(floatpntr+2);
        newobject->yposition =  *(floatpntr+3);
        newobject->xorbit =  *(floatpntr+4);
        newobject->yorbit =  *(floatpntr+5);
        newobject->gravity =  *(floatpntr+6);
        newobject->xsize =  *(floatpntr+7);
        newobject->ysize =  *(floatpntr+8);
        newobject->rcolor1 =  *(intpntr+9);
        newobject->rcolor2 =  *(intpntr+10);
        newobject->rcolor3 =  *(intpntr+11);
        newobject->rcolor4 =  *(intpntr+12);
        newobject->gcolor1 =  *(intpntr+13);
        newobject->gcolor2 =  *(intpntr+14);
        newobject->gcolor3 =  *(intpntr+15);
        newobject->gcolor4 =  *(intpntr+16);
        newobject->bcolor1 =  *(intpntr+17);
        newobject->bcolor2 =  *(intpntr+18);
        newobject->bcolor3 =  *(intpntr+19);
        newobject->bcolor4 =  *(intpntr+20);
        newobject->acolor1 =  *(intpntr+21);
        newobject->acolor2 =  *(intpntr+22);
        newobject->acolor3 =  *(intpntr+23);
        newobject->acolor4 =  *(intpntr+24);
        newobject->speed =  *(floatpntr+25);
        newobject->rotspeed =  *(floatpntr+26);
        objectlist->Add(newobject);
        intpntr += 27;
        floatpntr += 27;
        (int*)filepntr += 27;

  }


}


bool sector::getorbitmode(int objnumber)
{
if(objnumber <= (objectlist->Count - 1))
{
        return ((object*)objectlist->Items[objnumber])->orbitobj;
}
else return true;
}

void sector::setorbitmode(int objnumb, bool yn)
{
if(objnumb <= (objectlist->Count - 1))
{
        ((object*)objectlist->Items[objnumb])->orbitobj = yn;
}


}
