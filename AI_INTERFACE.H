//contains class def's for inteface to game engine
#ifndef AI_INTERFACE_HEADER
#define AI_INTERFACE_HEADER


class AIinput
{
public:
	virtual float GetDirection () =0;
	virtual void GetLocation(float & xpos, float & ypos) =0;
	virtual float GetSpeed() = 0;
	virtual float GetThrust() = 0;
	virtual int GetSector() =0;
//	virtual void GetRadar( list<radar_object*> *arg) =0;

};

class AIoutput
{
public:
	virtual void TurnLeft(bool) =0;
	virtual void TurnRight(bool)=0;
	virtual void Thrust(float & percent)=0;
	virtual void FireEngine(bool)=0;
	virtual void Hyperspace(int & sector) = 0;
	virtual void FireWeapon1(bool)=0;
	virtual void FireWeapon2(bool)=0;
	virtual void ToggleShields()=0;
};

struct radar_object
{
	float xpos;
	float ypos;
	float direction;
	int	type;
};

#endif





