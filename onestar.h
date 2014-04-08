class onestar
{
private:
	float x,y,v;
	int xs,ys;
	int r,g,b;
	static float diftime;
	//PIXEL_OBJECT* pixel;
protected:
public:
	onestar();
	~onestar();
	void settime(float time);
	void createnewstar();
	void movestar(float xc,float yc);
	float getxp() {	return x;}
	float getyp(){	return y;}
	int getr();
	int getb();
	int getg();
//	void drawstar();
};
