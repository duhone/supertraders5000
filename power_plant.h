// power_plant.h: interface for the power_plant class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POWER_PLANT_H__9E28F7C0_4C5B_4301_A4B1_9534318CBB91__INCLUDED_)
#define AFX_POWER_PLANT_H__9E28F7C0_4C5B_4301_A4B1_9534318CBB91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct power_plant_types
{
	float max_fuel;
	float max_generation;
};



class power_plant  
{
public:
	float get_max_fuel();
	void set_max_fuel(float arg);
	float get_fuel();
	void set_fuel(float arg);
	float get_specs();
	void repair(float arg);
	void do_damage(float arg);
	float get_power(float time);
	void set_generation(float arg);
	power_plant();
	virtual ~power_plant();

private:
	float max_fuel;
	float fuel;
	float cur_generation;
	float max_generation;
};

#endif // !defined(AFX_POWER_PLANT_H__9E28F7C0_4C5B_4301_A4B1_9534318CBB91__INCLUDED_)
