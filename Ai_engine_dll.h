#ifndef AI_ENGINE_DLL_HEADER
#define AI_ENGINE_DLL_HEADER

#include "AI_INTERFACE.H"


#include <windows.h>
#include <iostream>
#include <list>

using namespace std;

//****] defines [***************************
#define TRUE			1
#define FALSE			0
#define AI_PI			3.14159

//--types of ships
#define Friend			1
#define Pirate			2

//---Goals
#define Roaming			1
#define Combat			2
#define Trading			3

//---States
#define Turning			1
#define StartTurn		11
#define StraightLine	2
#define Stoping			3



struct State
{
	int CurrentGoal;
	int CurrentState;
	float arg1;
	float arg2;
	float arg3;
	float arg4;
};


class AIShip
{
public:
	AIinput * pAIinput;
	AIoutput * pAIoutput;

	virtual void DoAI() =0;
	AIinput * getAIinput(){ return pAIinput;}
	AIoutput * getAIoutput(){ return pAIoutput;}
	

	State state;
	int ShipNumber;
	

private:
	
};

typedef list<AIShip*> LIST_AISHIP;
typedef LIST_AISHIP::iterator LIST_AISHIP_ITERATOR;


class __declspec( dllexport ) AIThread
{
public:
	AIThread();
	~AIThread();

	void StartThread();
	void PauseThread();
	void StopThread();
	
	float AddShip(int ShipType, AIinput * aiinput, AIoutput * aioutput);
	void RemoveShip(float ship);

	static DWORD WINAPI ThreadProc(LPVOID lpParam);
	
	LPTHREAD_START_ROUTINE GetThreadProc()
	{
		return ThreadProc;
	};

	HANDLE hThread;
	DWORD lpThread;

	CRITICAL_SECTION AIThreadCriticalSection;

 	list<AIShip*>  AIShips;
	bool RunThread;
	float  ShipCount;
};


#endif