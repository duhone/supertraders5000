#include "beam_weapon.h"
extern DISPLAY_ENGINE *display;

//extern ENGINE engine;
#include "math.h"
beam_weapon::beam_weapon(float direction,float sxp,float syp,float velocity,graphic_object *graphobj,int objnumber)
{
//	proj_tex = display->CreateTextureObject();
/*	proj_tex->LoadTexture("pellet.png",100,100);

	proj_img = display->CreateSpriteObject();
	proj_img->AttatchTextureObject(proj_tex);
	proj_img->AddFrame(0,0,100,100);
	proj_img->SetFrame(0);
	proj_img->Scale(0.002,0.002);
*/	proj_img = graphobj;
	pallettenumber = objnumber;
	proj_img->vertexcolor(pallettenumber,0,255,255,255,255);
	proj_img->vertexcolor(pallettenumber,1,255,255,255,255);
	proj_img->vertexcolor(pallettenumber,2,255,255,255,255);
	proj_img->vertexcolor(pallettenumber,3,255,255,255,255);

	float magnitude,xtemp,ytemp;
			xvel = float(cos(-direction));
			yvel = -float(sin(-direction));
			magnitude = (float)sqrt((xvel*xvel + yvel*yvel));
			xvel /= magnitude;
			yvel /= magnitude;
			xtemp = (velocity*xvel) + xvel*4;
			ytemp = (velocity*yvel) + yvel*4;
			x = sxp /*+ xvel*0.01f*/;
			y = syp /*+ yvel*0.01f*/;
			xvel = xtemp;
			yvel = ytemp;
			direct = direction;
	alpha = 255.0f;
	/*proj_img->VertexColor(0,255,255,255,255);
	proj_img->VertexColor(1,255,255,255,255);
	proj_img->VertexColor(2,255,255,255,255);
	proj_img->VertexColor(3,255,255,255,255);
	*///	ship2_basic_img = engine.CreateImageObject();

//	ship2_basic_img->ALoadImage("pellet.bmp", 50, 50);

//	int index;


}

beam_weapon::~beam_weapon()
{
//	engine.DestroyImageObject(ship2_basic_img);
}

bool beam_weapon::MoveProjectile()
{
//	int index;

			x += xvel*diftime;
			y += yvel*diftime;
	alpha -= diftime*350;
	if(alpha < 0) 
	{
		alpha = 0;
		return true;
	}
	return false;
	
}

void beam_weapon::DrawProjectile(float sxp,float syp)
{
//	int index;
/*	proj_img->VertexColor(0,255,255,255,alpha);
	proj_img->VertexColor(1,255,255,255,alpha);
	proj_img->VertexColor(2,255,255,255,alpha);
	proj_img->VertexColor(3,255,255,255,alpha);
	proj_img->VertexColor(4,255,255,255,alpha);

			proj_img->Translate(x-sxp,y-syp);
			proj_img->Rotate((float)(direct-(3.14/2)));
	proj_img->Scale(0.001,0.001);
			proj_img->Render();
*/
				//			ship2_basic_img->DrawImage(x[index]-25, y[index]-25);
	proj_img->vertexcolor(pallettenumber,0,255,255,255,(int)alpha);
	proj_img->vertexcolor(pallettenumber,1,255,255,255,(int)alpha);
	proj_img->vertexcolor(pallettenumber,2,255,255,255,(int)alpha);
	proj_img->vertexcolor(pallettenumber,3,255,255,255,(int)alpha);
	proj_img->translate(pallettenumber,(x-sxp),(y-syp));
	proj_img->rotate(pallettenumber,(float)(direct-(3.14/2)));
	proj_img->scale(pallettenumber,0.001f,0.001f);
	proj_img->render(pallettenumber);


}

/*void beam_weapon::FireProjectile(float direction,float sxp,float syp,float velocity)
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
	
}*/
