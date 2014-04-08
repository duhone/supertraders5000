#include "projectile.h"
extern DISPLAY_ENGINE *display;

//extern ENGINE engine;
#include "math.h"

float projectile::diftime = 0.0f;

projectile::projectile()
{

}

projectile::~projectile()
{

}


void projectile::settime(float time)
{
	diftime = time;
}
