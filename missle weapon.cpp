#include "missle weapon.h"
extern DISPLAY_ENGINE *display;

//extern ENGINE engine;
#include "math.h"
missle_weapon::missle_weapon(float direction,float sxp,float syp,float xv,float yv,graphic_object *graphobj,int objnumber)
{
/*	proj_tex = display->CreateTextureObject();
	proj_tex->LoadTexture("missle.png",100,100);

	proj_img = display->CreateSpriteObject();
	proj_img->AttatchTextureObject(proj_tex);
	proj_img->AddFrame(0,0,100,100);
	proj_img->SetFrame(0);
	proj_img->Scale(0.0001f,0.0001f);
*/
		proj_img = graphobj;
	pallettenumber = objnumber;
	proj_img->vertexcolor(pallettenumber,0,255,255,255,255);
	proj_img->vertexcolor(pallettenumber,1,255,255,255,255);
	proj_img->vertexcolor(pallettenumber,2,255,255,255,255);
	proj_img->vertexcolor(pallettenumber,3,255,255,255,255);


	float magnitude,xtemp,ytemp;
			xvel = float(cos(-direction));
			yvel = float(sin(-direction));
			//xvel = xv;
			//yvel = yv;
			magnitude = (float)sqrt((xvel*xvel + yvel*yvel));
			if(magnitude == 0) magnitude = 0.0001f;
			xvel /= magnitude;
			yvel /= magnitude;
			xtemp = xv + xvel*1.0f;
			ytemp = yv + yvel*1.0f;
			x = sxp + xvel*0.15f;
			y = syp + yvel*0.15f;
			xvel = xv;
			yvel = yv;
			direct = -direction;
	alpha = 255.0f;
/*	proj_img->VertexColor(0,255,255,255,255);
	proj_img->VertexColor(1,255,255,255,255);
	proj_img->VertexColor(2,255,255,255,255);
	proj_img->VertexColor(3,255,255,255,255);
	//	ship2_basic_img = engine.CreateImageObject();

//	ship2_basic_img->ALoadImage("pellet.bmp", 50, 50);

//	int index;

*/
}

missle_weapon::~missle_weapon()
{
//	engine.DestroyImageObject(ship2_basic_img);
}

bool missle_weapon::MoveProjectile()
{
//	int index;

	x += xvel*diftime;
	y += yvel*diftime;
	alpha -= diftime*200;
	if(alpha < 0) 
	{
		alpha = 0;
		return true;
	}
	return false;
	
}

void missle_weapon::DrawProjectile(float sxp,float syp)
{
//	proj_img->vertexcolor(pallettenumber,0,255,255,255,(int)alpha);
//	proj_img->vertexcolor(pallettenumber,1,255,255,255,(int)alpha);
//	proj_img->vertexcolor(pallettenumber,2,255,255,255,(int)alpha);
//	proj_img->vertexcolor(pallettenumber,3,255,255,255,(int)alpha);
	proj_img->translate(pallettenumber,(x-sxp),(y-syp));
	proj_img->rotate(pallettenumber,(float)(direct-(3.14/2)));
	proj_img->scale(pallettenumber,0.001f,0.001f);
	proj_img->render(pallettenumber);
//	int index;
//	proj_img->VertexColor(0,255,255,255,255);
//	proj_img->VertexColor(1,255,255,255,255);
//	proj_img->VertexColor(2,255,255,255,255);
//	proj_img->VertexColor(3,255,255,255,255);
//	proj_img->VertexColor(4,255,255,255,255);

/*			proj_img->Translate(x - sxp,y - syp);
			proj_img->Rotate((float)(direct-(3.14/2)));
			proj_img->Scale(0.001f,0.001f);
			proj_img->Render();
*/				//			ship2_basic_img->DrawImage(x[index]-25, y[index]-25);
}

/*void missle_weapon::FireProjectile(float direction,float sxp,float syp,float velocity)
{
//	int index;
	float magnitude,xtemp,ytemp;
			xvel = float(cos(-direction));
			yvel = float(sin(-direction));
			magnitude = (float)sqrt((xvel*xvel + yvel*yvel));
			xvel /= magnitude;
			yvel /= magnitude;
			xtemp = (velocity*xvel) + xvel*4;
			ytemp = (velocity*yvel) + yvel*4;
			x = sxp + xvel*60;
			y = syp + yvel*60;
			xvel = xtemp;
			yvel = ytemp;
			direct = -direction;
	alpha = 255.0f;
	proj_img->VertexColor(0,255,255,255,255);
	proj_img->VertexColor(1,255,255,255,255);
	proj_img->VertexColor(2,255,255,255,255);
	proj_img->VertexColor(3,255,255,255,255);
	
}
*/