// power_plant.cpp: implementation of the power_plant class.
//
//////////////////////////////////////////////////////////////////////

#include "power_plant.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

power_plant::power_plant()
{
	fuel = 0;
	max_generation = 0;
	cur_generation = 0;
}

power_plant::~power_plant()
{

}

void power_plant::set_generation(float arg)
{
	max_generation = arg;
	cur_generation = arg;
}

float power_plant::get_power(float time)
{
	float temp_power;
	temp_power = time * cur_generation;

	fuel -= temp_power;
	if(fuel < 0) temp_power = 0;
	return temp_power;
}

void power_plant::do_damage(float arg)
{
	cur_generation -= (arg * max_generation);
	if(cur_generation < 0)  cur_generation = 0;
}

void power_plant::repair(float arg)
{
	cur_generation += (arg * max_generation);
	if(cur_generation > max_generation)  cur_generation = max_generation;

}

float power_plant::get_specs()
{
	return max_generation;
}

void power_plant::set_fuel(float arg)
{
	fuel = arg;
}

float power_plant::get_fuel()
{
	return fuel;
}

void power_plant::set_max_fuel(float arg)
{
	max_fuel = arg;
}

float power_plant::get_max_fuel()
{
	return max_fuel;
}
