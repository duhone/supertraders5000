#include"player.h"
#include <math.h>
playerinstance::playerinstance(graphic_object* gobj)
{
	xposition = 500.;
	yposition = 482.0;
	direction = 0;
	velocity = 0;
	xvel = 0;
	yvel = 0;
	thrust_amount = 0;
	gun1rechargetime = 0.0f;
	gun2rechargetime = 0.0f;
	curship = new ship(gobj);
	cloak_level = 255;
	cloak_up = false;
	graphobj = gobj;
	cur_sector = 0;
	turn_direction = 0;
}

playerinstance::~playerinstance()
{
	delete curship;
}

void playerinstance::changeship(ship_types* arg)
{
		curship->loadship(arg);
}

void playerinstance::drawship()
{
	curship->set_ship_color(255,255,255,(int)cloak_level);
	curship->set_translation(xspos,yspos);
	curship->drawship();
}

float playerinstance::getxp()
{
	return xposition;
}

float playerinstance::getyp()
{
	return yposition;
}

void playerinstance::moveship()
{
	direction += curship->get_turn_rate()*diftime * turn_direction;
	if(direction < 0) direction += 6.283185f;
	if(direction > 6.283185f) direction -= 6.283185f;
	curship->setdirection(direction);
		
	if(thrust_on)   setvelocity();
	
	
	gun1rechargetime -= diftime;
	gun2rechargetime -= diftime;
/*	xposition += (float)cos(-direction) * velocity * diftime;
	yposition += (float)sin(-direction) * velocity * diftime;
*/	
	xposition += xvel * diftime;
	yposition += yvel * diftime;

	
	if((cloak_up == true) && (cloak_level >= 64.0))
		cloak_level -= diftime * 100;
	if((cloak_up == false) && (cloak_level <= 255.0))
		cloak_level += diftime * 100;
	if(cloak_level < 64) cloak_level = 64;
	if(cloak_level > 255) cloak_level = 255;


	
}

void playerinstance::togle_hud()
{
}

void playerinstance::ToggleShields()
{
}

/*void playerinstance::turnship(int leftright)
{
	if(leftright < 0) 
	{
		direction -= curship->get_turn_rate()*diftime*abs(leftright);
		if(direction < 0) direction += 6.283185f;
		if(direction > 6.283185f) direction -= 6.283185f;
	}
	if(leftright > 0) 
	{
		direction += curship->get_turn_rate()*diftime*leftright;
		if(direction < 0) direction += 6.283185f;
		if(direction > 6.283185f) direction -= 6.283185f;
	}
	curship->setdirection(direction);
}
*/
void playerinstance::setvelocity()
{
	//velocity = v;
	float temp;
	temp = curship->get_thrust_force(thrust_amount) * diftime;
	xvel += temp * (float)cos(direction);
	yvel += temp * (float)sin(direction);

}

float playerinstance::GetDirection()
{
	return direction;
}

float playerinstance::GetSpeed()
{
	return (float)sqrt((xvel*xvel + yvel*yvel));
}

projectile *playerinstance::fireweapon(int  weapon_numb)
{
	beam_weapon *temp1 = NULL;
	missle_weapon *temp2 = NULL;
	
	if(weapon_numb == 1)
	{
		if(gun1rechargetime <= 0.0)
		{
			temp1 = new beam_weapon(direction,xposition,yposition,velocity,graphobj,0);
			gun1rechargetime = 0.15f;
			return temp1;
		}
	}
	else
	{
		if(gun2rechargetime <= 0.0)
		{
			temp2 = new missle_weapon(direction,xposition,yposition,xvel,yvel,graphobj,1);
			gun2rechargetime = 1.0f;
			return temp2;
		}
	}
	return NULL;

}

void playerinstance::toggle_cloak()
{
	if(cloak_level > 254) 
	{
//		cloak_level = 64;
		cloak_up = true;
	}
	else if(cloak_level < 65) 
	{
//		cloak_level = 255;
		cloak_up = false;
	}
}


float playerinstance::get_xvelocity()
{
	return xvel;
}

float playerinstance::get_yvelocity()
{
	return yvel;
}

void playerinstance::setgrav(float x, float y)
{
	xvel += x*diftime;
	yvel += y*diftime;
}

void playerinstance::settime(float arg)
{
	diftime = arg;
	curship->settime(arg);
}

void playerinstance::GetLocation(float &xpos,float &ypos)
{
	xpos = xposition;
	ypos = yposition;
}

int playerinstance::GetSector()
{
	return cur_sector;
}

float playerinstance::GetThrust()
{
	return thrust_amount;
}

void playerinstance::TurnLeft(bool arg)
{
	if(arg) turn_direction = 1;
	else turn_direction = 0;
}

void playerinstance::TurnRight(bool arg)
{
	if(arg) turn_direction = -1;
	else turn_direction = 0;
}

void playerinstance::Hyperspace(int &sec)
{
	cur_sector = sec;
}

void playerinstance::FireWeapon1(bool arg)
{

}

void playerinstance::FireWeapon2(bool arg)
{

}

void playerinstance::FireEngine(bool arg)
{
	thrust_on = arg;
}



void playerinstance::set_position(float x, float y)
{
	xposition = x;
	yposition = y;

}

void playerinstance::view_transform(float x, float y)
{
	xspos = xposition - x;
	yspos = yposition - y;
}

void playerinstance::Thrust(float &percent)
{
	thrust_amount = percent;

}
