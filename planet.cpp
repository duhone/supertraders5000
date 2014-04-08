#include "planet.h"

//extern ENGINE engine;
extern int width;
extern int height;
//extern DISPLAY_ENGINE *display;
planet::planet(graphic_object* gobj,int palnumb)
{

//	plan_img = engine.CreateImageObject();
/*	plan_tex = display->CreateTextureObject();
	plan_tex->LoadTexture("star1.png",100,100);
	plan_img = display->CreateSpriteObject();
	plan_img->AttatchTextureObject(plan_tex);
	plan_img->AddFrame(0,0,100,100);
	plan_img->SetFrame(0);
	plan_img->Scale(0.01f,0.01f);
*/		//plan_img->ALoadImage("star1.bmp", 500, 500);
	plan_img = gobj;
	pallettenumber = palnumb;
	x = 3;
	y = 2;
}

planet::~planet()
{
//	engine.DestroyImageObject(plan_img);
}

void planet::moveplanet()
{

}

void planet::drawplanet()
{
	plan_img->scale(pallettenumber,0.15f,0.15f);
	plan_img->translate(pallettenumber,xs,ys);
	plan_img->render(pallettenumber);
//	plan_img->DrawImage(x-250,y-250);;
}

void planet::transformplanet(float xp,float yp)
{
	xs = (x + xp);
	ys = (y + yp);
}
