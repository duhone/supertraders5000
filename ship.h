
#if !defined(ship_h)
#define ship_h

#include "MMEngine.h"
//#include "Engine.h"
#include "graphic_object.h"

//extern float diftime;
struct ship_types
{
	float solar_generation;
	int max_crew;
	int hull_strength;
	float turn_rate;
	float engine_efficency;
	float cargo_capacity;
	int num_weapons;
	int pallettenumber;
};

class ship
{
private:
	float yposition;
	float xposition;
	float engine_power;
	float solar_generation;
	int max_crew;
	int hull_strength;
	float turn_rate;
	float engine_efficency;
	float cargo_capacity;
	int num_weapons;
	float direction;
	
	graphic_object *ship_img;
	int pallettenumber;
/*	float shieldtime;
	float hudtime;
	bool HUD_IS_ON;
	bool SHIELD_IS_ON;
*/
public:
	void set_translation(float x,float y);
	float get_turn_rate();
	float get_thrust_force(float level);
	void set_solar_power(float arg);
	void set_max_crew(int arg);
	void set_hull_strength(int arg);
	void set_turn_rate(float arg);
	void set_engine_effeciency(float arg);
	void set_cargo_capacity(float arg);
	void set_numweapons(int arg);
	ship(graphic_object *graphobj);
	~ship();
	void loadship(ship_types *arg);
	void settime(float arg);
	void setdirection(float dir);
	void drawship();
//	void TOGGLE_HUD();
//	void TOGGLE_SHIELD();
	void set_ship_color(int r,int g,int b,int a);
};

#endif