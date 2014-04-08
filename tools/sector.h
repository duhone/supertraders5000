//---------------------------------------------------------------------------
#ifndef sectorH
#define sectorH
//---------------------------------------------------------------------------

struct object
//object data for a single object
{
  int orbitobj;
  int pallettenumb;
  float xposition;
  float yposition;
  float xorbit;
  float yorbit;
  float gravity;
  float xsize;
  float ysize;
  int rcolor1,rcolor2,rcolor3,rcolor4;
  int gcolor1,gcolor2,gcolor3,gcolor4;
  int bcolor1,bcolor2,bcolor3,bcolor4;
  int acolor1,acolor2,acolor3,acolor4;
  float speed;
  float rotspeed;
};

class sector
//object data for an entire sector
{
 public:
   sector();
   ~sector();
   void addobject();
   void deleteobject(int objnumb);
   float getxposition(int objnumb);
   void setxposition(int objnumb,float newpos);
   float getyposition(int objnumb);
   void setyposition(int objnumb,float newpos);
   float getxorbit(int objnumb);
   void setxorbit(int objnumb,float newpos);
   float getyorbit(int objnumb);
   void setyorbit(int objnumb,float newpos);
   float getxsize(int objnumb);
   void setxsize(int objnumb,float newpos);
   float getysize(int objnumb);
   void setysize(int objnumb,float newpos);
   int getpallete(int objnumb);
   void setpallete(int objnumb,int newpos);
   float getgravity(int objnumb);
   void setgravity(int objnumb,float newpos);
   void setcolor1(int objnumb,int r,int g,int b,int a); 
   void getcolor1(int objnumb,int& r,int& g,int&b,int& a);
   void setcolor2(int objnumb,int r,int g,int b,int a);
   void getcolor2(int objnumb,int& r,int& g,int&b,int& a);
   void setcolor3(int objnumb,int r,int g,int b,int a);
   void getcolor3(int objnumb,int& r,int& g,int&b,int& a);
   void setcolor4(int objnumb,int r,int g,int b,int a);
   void getcolor4(int objnumb,int& r,int& g,int&b,int& a);
   void setspeed(int objnumb,float s);
   float getspeed(int objnumb);
   void setrotspeed(int objnumb,float s);
   float getrotspeed(int objnumb);
   void writeinfo(void* &filepntr);
   void readinfo(void* & filepntr);
   bool getorbitmode(int objnumber);
   void setorbitmode(int objnumb, bool yn);

private:
   TList* objectlist;
   int numobjects;
};


#endif
