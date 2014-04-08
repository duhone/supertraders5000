#include "ship.h"

//extern ENGINE engine;
extern DISPLAY_ENGINE *display;

void ship::loadship(ship_types *arg)
{
	pallettenumber = arg->pallettenumber;
	cargo_capacity = arg->cargo_capacity;
	engine_efficency = arg->engine_efficency;
	hull_strength = arg->hull_strength;
	max_crew = arg->max_crew;
	num_weapons = arg->num_weapons;
	solar_generation = arg->solar_generation;
	turn_rate = arg->turn_rate;

	//engine.DestroyImageObject(ship_image);
	//engine.DestroySpriteObject(ship_sprite);
	//ship_image = engine.CreateImageObject();

	
	//ship_image->ALoadImage(name, 500, 500);
	//ship_sprite = engine.CreateSpriteObject(ship_image);
	/*ship_tex->LoadTexture("ship.png",100,100);
	ship_img->AttatchTextureObject(ship_tex);
	ship_img->AddFrame(0,0,100,100);
	ship_img->SetFrame(0);
	ship_img->Scale(0.002f,0.002f);
	*/
	//for(index_y = 0; index_y < 10; index_y++)
//		for(index_x = 0; index_x < 10; index_x++)
//			ship_sprite->AddAnimationFrame(index_x*50,
//										   index_y*50,
//										   index_x*50 + 49,
//										   index_y*50 + 49);

}

ship::ship(graphic_object *graphobj)
{
	ship_img = graphobj;
	pallettenumber = 0;
	direction = 0;
	cargo_capacity = 0;
	engine_efficency = .1f;
	hull_strength = 10;
	max_crew = 1;
	num_weapons = 0;
	solar_generation = 50;
	turn_rate = 2;
}



ship::~ship()
{
//	engine.DestroyImageObject(ship_image);
//	engine.DestroySpriteObject(ship_sprite);
//	engine.DestroyImageObject(ship_shield);
//	engine.DestroyImageObject(HUD);
}

  void ship::drawship(void)
{
//	settime();
	ship_img->rotate(pallettenumber,direction);

	ship_img->translate(pallettenumber,xposition,yposition);
	ship_img->scale(pallettenumber,0.002f,0.002f);
	ship_img->render(pallettenumber);

}



void ship::setdirection(float dir)
{
	direction = dir;
}

/*void ship::TOGGLE_HUD()
{
	if(HUD_IS_ON)
	{
		if(hudtime <= 0.00f) 
		{
			HUD_IS_ON = false;
			hudtime = 0.3f;
		}
	}
	else
	{
		if(hudtime <= 0.00f)
		{
			hudtime = 0.3f;
			HUD_IS_ON = true;
		}
	}
}

void ship::TOGGLE_SHIELD()
{
	if(SHIELD_IS_ON)
	{
		if(shieldtime <= 0.00f) 
		{
			SHIELD_IS_ON = false;
			shieldtime = 0.3f;
		}
	}
	else
	{
		if(shieldtime <= 0.00f)
		{
			shieldtime = 0.3f;
			SHIELD_IS_ON = true;
		}
	}
}
*/
void ship::settime(float arg)
{
	float total_power;
	total_power = solar_generation * arg;

	engine_power = total_power;
	//diftime = time;
//	shieldtime -= diftime;
//	hudtime -= diftime;
}


void ship::set_ship_color(int r,int g,int b,int a)
{
	ship_img->vertexcolor(pallettenumber,0,r,g,b,a);
	ship_img->vertexcolor(pallettenumber,1,r,g,b,a);
	ship_img->vertexcolor(pallettenumber,2,r,g,b,a);
	ship_img->vertexcolor(pallettenumber,3,r,g,b,a);
	//ship_img->VertexColor(4,r,g,b,a);

}

void ship::set_numweapons(int arg)
{
	num_weapons = arg;
}

void ship::set_cargo_capacity(float arg)
{
	cargo_capacity = arg;
}

void ship::set_engine_effeciency(float arg)
{
	engine_efficency = arg;
}

void ship::set_turn_rate(float arg)
{
	turn_rate = arg;
}

void ship::set_hull_strength(int arg)
{
	hull_strength = arg;
}

void ship::set_max_crew(int arg)
{
	this->max_crew = arg;
}

void ship::set_solar_power(float arg)
{
	solar_generation = arg;
}

float ship::get_thrust_force(float level)
{
	float temp;
	temp = level * engine_power * engine_efficency;
	return temp;
}

float ship::get_turn_rate()
{
	return turn_rate;
}

void ship::set_translation(float x, float y)
{
	xposition = x;
	yposition = y;
}
