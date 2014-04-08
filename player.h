#include"ship.h"
#include"beam_weapon.h"
#include"missle weapon.h"
#include"AI_interface.h"
#include "power_plant.h"

#define ship_terran_1	1
#define ship_valthrek_1	2

// extern float diftime;

class playerinstance : public AIinput , public AIoutput
{
private:
	bool thrust_on;
	float yspos;
	float xspos;
	int turn_direction;
	int cur_sector;
	float diftime;
	float thrust_amount;
	float xposition,yposition,velocity,xvel,yvel;
	ship *curship;
	float direction;
	float gun1rechargetime,gun2rechargetime;
	float cloak_level;
	bool cloak_up;
	graphic_object* graphobj;
	void setvelocity();
public:
	void Thrust(float &percent);
	void view_transform(float x,float y);
	void set_position(float x,float y);
	void FireEngine(bool arg);
	void FireWeapon2(bool arg);
	void FireWeapon1(bool arg);
	void Hyperspace(int &sec);
	void TurnRight(bool arg);
	void TurnLeft(bool arg);
	float GetThrust();
	int GetSector();
	void settime(float arg);
	void setgrav(float x,float y);
	float get_yvelocity();
	float get_xvelocity();
	playerinstance(graphic_object* gobj);
	~playerinstance();
	void changeship(ship_types* arg);
	void moveship();
	void drawship();
//	void turnship(int leftright);
	void togle_hud();
	void ToggleShields();
	void GetLocation(float &xpos,float &ypos);
	float getxp();
	float getyp();
	float GetDirection();
	float GetSpeed();
	projectile *fireweapon(int weapon_numb);
	void toggle_cloak();
};