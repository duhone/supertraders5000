// super trader 5000.cpp : Defines the entry point for the application.
//
#include<windows.h>
#include<stdio.h>
//#include<dir.h>
#include<io.h>
#include <fcntl.h>

//#include"engine.h"
#include"input.h"
#include"starfield.h"
#include"ship.h"
#include<math.h>
#include"projectile.h"
#include"projectile list.h"
#include"graphic_object.h"
//#include"sounddll.h"
#include"player.h"
//#include"display.h"
//#include"mmsystem.h"
#include"MMEngine.h"
//#include "music.h"
#include "beam_weapon.h"
bool done = false;
#include"planet.h"
#include "cursor_class.h"
#include "orbitniobject.h"
#include "niobjectlist.h"
#include "ai_engine_dll.h"
#include "power_plant.h"


bool paused = false;
#include<vector>
using namespace std;
HWND hwnd;
int width,height;
//ENGINE engine;
starfield stars;
playerinstance      *player = NULL;
float velocity,direction;
projectile_list *all_projectiles = NULL;
cursor_class *main_cursor = NULL;
vector<ship_types*> ship_type_list;
vector<power_plant_types*> power_plant_type_list;

//TEXT_OBJECT *text;
MMENGINE engine;
DISPLAY_ENGINE *display = NULL;
SOUND_ENGINE *sound_eng = NULL;
AIThread *aithreadp = NULL;


//music *back_music = NULL;
// Frame Rate Timer Defs
long int counter = 0;
LARGE_INTEGER timerfreq;
LARGE_INTEGER starttime;
LARGE_INTEGER currenttime;

LARGE_INTEGER starttime1;
LARGE_INTEGER currenttime1;
float diftime;
int nframes = 0;
float pausetime;

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
 switch(message)
 {
 case WM_DESTROY:
	 done = true;
	 return 0;
 case WM_QUIT:
	 done = true;
	 return 0;
 case WM_TIMER:
	aithreadp->StartThread();
	 return 0;
 }
	return DefWindowProc(hwnd,message,wParam,lParam);
}

void CALLBACK WndProc2(int message,int value)
{
	static lock_turn = false;
	static lock_engine = false;
	//lock_engine = false;
	switch(message)
	{
	case DIK_ESCAPE:
		if(value) done = true;
		break;
	case DIK_LEFT:
		if(value)
		{
			player->TurnLeft(true);
			lock_turn = true;
		}
		else
		{
			player->TurnLeft(false);
		}

		break;
	case DIK_RIGHT:
		if(value)
		{
			player->TurnRight(true);
		}
		else
		{
			if(!lock_turn)
			{
				player->TurnRight(false);
				lock_turn = false;
			}
		}

		break;
	case DIK_UP:
		if(value)
		{
			velocity += 0.5f*diftime;
			if(velocity > 1) velocity = 1;
			if(velocity < 0) velocity = 0;
			player->Thrust(velocity);
		}
		break;
	case DIK_DOWN:
		if(value)
		{
			velocity -= 0.01f*diftime;
			if(velocity > 1) velocity = 1;
			if(velocity < 0) velocity = 0;
			player->Thrust(velocity);
		}
		break;
	case DIK_RSHIFT:
	case DIK_LSHIFT:
		if(value)
		{
			lock_engine = true;
			player->FireEngine(true);
		}
		else
		{
			lock_engine = false;
			player->FireEngine(false);
		}
		break;

	
/*	case JOYSTICK_X:
		direction += value/60000.0f;
		if(direction < 0) direction += 6.283185f;
		if(direction > 6.283185f) direction -= 6.283185f;
		break;
	case JOYSTICK_Y:
		velocity -= value/10000.0f;
		if(velocity > 5) velocity = 5;
		if(velocity < 0) velocity = 0;
		break;
		*/
	case DIK_C:
		if(value)
			player->toggle_cloak();
		break;
	case DIK_H:
		if(value)
			player->togle_hud();
		break;

	case DIK_S:
		if(value)
			player->ToggleShields();
		break;
	case DIK_SPACE:
		if(value)
			all_projectiles->add_projectile(player->fireweapon(1));
			//	pellet_gun->FireProjectile(player->getdirection(),player->getxp(),player->getyp(),player->getvelocity());
		break;
	case DIK_LCONTROL:
	case DIK_RCONTROL:
		if(value)
			all_projectiles->add_projectile(player->fireweapon(2));
			//	pellet_gun->FireProjectile(player->getdirection(),player->getxp(),player->getyp(),player->getvelocity());
		break;
	case DIK_1:
		if(value)
			player->changeship(ship_type_list[0]);
		break;
	case DIK_2:
		if(value)
			player->changeship(ship_type_list[0]);
		break;
	case MOUSE_X:
			if(paused) main_cursor->move_cursor((float)value,0.0f);
			else
	//			player->turnship(value/2.0f);
			break;
	case MOUSE_Y:
			if(paused) main_cursor->move_cursor(0.0f,-(float)value);
			else
			{
		/*		velocity += 0.1f*diftime*value;
				if(velocity > 1) velocity = 1;
				if(velocity < 0) velocity = 0;
				player->setthrust(velocity);
		*/	}
	
			break;
	case MOUSE_B1:
		if(value)
		{
			if(!paused)
			{
				all_projectiles->add_projectile(player->fireweapon(1));
			}
		}
		break;
	case MOUSE_B2:
		if(value)
		{
			if(pausetime < 0.0f)
			{
				pausetime = 0.5f;
				paused = !paused;
			}
		}
		break;
	case MOUSE_B3:
		if(value)
		{
				player->FireEngine(true);
		}
		else
		{
			if(!lock_engine)	player->FireEngine(false);
		}
		break;

	}	

}


void loadsector(niobjectlist *arg,graphic_object& arg2)
{
	char picdirectory[256];
	  strcpy(picdirectory,"data\\niseclist.hpt");
 
	

HANDLE filehandle;
HANDLE filemaphandle;
void* filepointer;
int* tempfilepntr;

//load info from file using memory mapped files
    
 filehandle = CreateFile(picdirectory,GENERIC_READ,0,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
 filemaphandle = CreateFileMapping(filehandle,NULL,PAGE_READONLY,0,0,NULL);
 filepointer = MapViewOfFile(filemaphandle,FILE_MAP_READ,0,0,0);
  if(filepointer != NULL)
 {
	  tempfilepntr = (int*)filepointer;
	  orbitniobject* tempobj;
	  for(int count3 = 0;count3 < 20;count3++)
	  {
		int count = *tempfilepntr;
		tempfilepntr++;
		for(int count2 = 0;count2 < count;count2++)
		{
			tempobj = new orbitniobject(&arg2,*tempfilepntr,*(float*)(tempfilepntr+2),*(float*)(tempfilepntr+3));
			tempobj->setscale(*(float*)(tempfilepntr+7),*(float*)(tempfilepntr+8));
			tempobj->setorbitpos(*(float*)(tempfilepntr+4),*(float*)(tempfilepntr+5),*(float*)(tempfilepntr+25));
			tempobj->setgravstrength(*(float*)(tempfilepntr+6));
			tempobj->setrotspeed(*(float*)(tempfilepntr+26));
			tempobj->setcolor((*(float*)(tempfilepntr+9))/255.0f,(*(float*)(tempfilepntr+13))/255.0f,(*(float*)(tempfilepntr+17))/255.0f,(*(float*)(tempfilepntr+21))/255.0f);
			arg[count3].add(tempobj);
			tempfilepntr += 27;
		
		}
	  }
  }
 else MessageBox(hwnd,"Error could not open piclist.hpt","ERROR",MB_OK);
 UnmapViewOfFile(filepointer);
 CloseHandle(filemaphandle);
 CloseHandle(filehandle);

}

void loadpowertypes()
{
	power_plant_types *temp;
	temp = new power_plant_types();
	temp->max_fuel = 10000;
	temp->max_generation = 500;
	power_plant_type_list.push_back(temp);

	temp = new power_plant_types();
	temp->max_fuel = 6000;
	temp->max_generation = 300;
	power_plant_type_list.push_back(temp);

}

void delete_power_plant_types()
{
	power_plant_types *temp;
	for(int count = 0;count < power_plant_type_list.size();count++)
	{
		
		temp = power_plant_type_list[count];
		delete temp;
	}
}

void loadshiptypes()
{
	ship_types *temp;
	temp = new ship_types();
	temp->cargo_capacity = 10;
	temp->engine_efficency = 0.9f;
	temp->hull_strength = 10;
	temp->max_crew = 1;
	temp->num_weapons = 0;
	temp->pallettenumber = 3;
	temp->solar_generation = 200;
	temp->turn_rate = 2;
	ship_type_list.push_back(temp);

	temp = new ship_types();
	temp->cargo_capacity = 10;
	temp->engine_efficency = 0.5f;
	temp->hull_strength = 10;
	temp->max_crew = 1;
	temp->num_weapons = 0;
	temp->pallettenumber = 2;
	temp->solar_generation = 50;
	temp->turn_rate = 2;
	ship_type_list.push_back(temp);
}

void delete_ship_types()
{
	ship_types *temp;
	for(int count = 0;count < ship_type_list.size();count++)
	{
		
		temp = ship_type_list[count];
		delete temp;
	}
}

void loadpallette(graphic_object& arg)
{
	char picdirectory[256];
	  strcpy(picdirectory,"pics\\piclist.hpt");
    char temp2[1024];

	

HANDLE filehandle;
HANDLE filemaphandle;
void* filepointer;


//load info from file using memory mapped files
    
 filehandle = CreateFile(picdirectory,GENERIC_READ,0,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
 filemaphandle = CreateFileMapping(filehandle,NULL,PAGE_READONLY,0,0,NULL);
 filepointer = MapViewOfFile(filemaphandle,FILE_MAP_READ,0,0,0);
 if(filepointer != NULL)
 {
  char* temp = (char*)filepointer;
  int tempres;
  int tempframes;
  for(int count1 = 0;count1 < 512;count1++)
  {
       strcpy(temp2,"pics\\");
	  strcat(temp2,temp);
     	temp+= strlen(temp) + 1;
      tempres = *((int*)temp);
      temp += 4;
      tempframes = *((int*)temp);
      temp += 4;
	arg.loadobject(count1,temp2,tempframes);  	

  }
 }
 else MessageBox(hwnd,"Error could not open piclist.hpt","ERROR",MB_OK);
 UnmapViewOfFile(filepointer);
 CloseHandle(filemaphandle);
 CloseHandle(filehandle);

}


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	vector<playerinstance*> badguys;
	
	graphic_object graphic_objects;
//	int count;
	main_cursor = new cursor_class(&graphic_objects,6);
	MSG msg;
	char appname[6];
	strcpy(appname,"Super Trader 5000");
	width = 800;
	height = 600;
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = appname;
	RegisterClass(&wc);
	hwnd = CreateWindowEx(NULL,appname,NULL,WS_POPUP,0,0,width,height,NULL,NULL,hInstance,NULL);
	ShowWindow(hwnd,SW_SHOW);
	SetFocus(hwnd);
	ShowCursor(false);
	//engine.Startup(hwnd,MODE_WINDOWED,width,height,32);
	engine.Startup();
	display = engine.CreateDisplayEngine();
	//sound_eng = engine.CreateSoundEngine();

	if(display->Startup(hwnd, MODE_WINDOWED, width, height) == FALSE)
		MessageBox(hwnd, "UNABLE TO CREATE D3D WINDOW", "ERROR", MB_OK);
	display->SetProjMetrics(PROJ_MODE_DEFAULT);
	inputstartup(hwnd,hInstance,use_keyboard | use_mouse /*| use_joystick*/);
	//sound_eng->InitializeSound();
	
	

	loadpallette(graphic_objects);
	loadshiptypes();
	loadpowertypes();
	
	niobjectlist niobjects[20];

	loadsector(niobjects,graphic_objects);

	SetTimer(hwnd,0, 50, NULL);
	
	float xv,yv;
	direction = 0.0f;
	velocity = 0;
	xv = 0;
	yv = 0;
	player = new playerinstance(&graphic_objects);
	player->changeship(ship_type_list[0]);
	
	

	QueryPerformanceFrequency(&timerfreq);
	QueryPerformanceCounter(&starttime);
	all_projectiles = new projectile_list;
//	pellet_gun = new beam_weapon();

	//text = engine.CreateTextObject();
	
	stars.createnewstar();
	//back_music = new music();

	QueryPerformanceCounter(&starttime1);
    display->SetProjMetrics(PROJ_MODE_ASPECT_R);
	//back_music->playsong(1);
	float xg,yg;
	playerinstance *badguy;
	badguy = new playerinstance(&graphic_objects);
	badguy->changeship(ship_type_list[1]);
	badguy->set_position(501.5,482);
	player->set_position(500,482);

	aithreadp = new AIThread;
	aithreadp->AddShip(Friend,(AIinput*)badguy,(AIoutput*)badguy);


for(int count = 0;count < 50;count++)
{
	playerinstance* temp;
	temp = new playerinstance(&graphic_objects);
	temp->set_position(498 + (count%5),481 + (count/20.0f));
	badguys.push_back(temp);
	aithreadp->AddShip(Friend,(AIinput*)temp,(AIoutput*)temp);
}
for(count = 0;count < 50;count++)
{
	badguys[count]->changeship(ship_type_list[1]);
}

	while(!done)
	{
		xg = yg = 0;
		QueryPerformanceCounter(&currenttime1);
		diftime = ((float)(currenttime1.QuadPart - starttime1.QuadPart)/(float)timerfreq.QuadPart);
		starttime1 = currenttime1;
		pausetime -= diftime;
		if(paused) diftime = 0;
		
		stars.settime(diftime);
		player->settime(diftime);
		badguy->settime(diftime);
for(int count = 0;count < 50;count++)
{
	badguys[count]->settime(diftime);
}

		niobjects[0].settime(diftime);

		graphic_objects.settime(diftime);
//		pellet_gun->settime(diftime);
		player->moveship();
		badguy->moveship();
for(count = 0;count < 50;count++)
{
	badguys[count]->moveship();
}

		while(PeekMessage(&msg,NULL,WM_DESTROY,WM_DESTROY,PM_REMOVE))
		{
	
			done = true;
		}
		while(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}
		getinput(WndProc2);
	//	xv = -(float)cos(player->getdirection()) * player->getvelocity();
	//	yv = (float)sin(player->getdirection()) * player->getvelocity();
	
		xv = player->get_xvelocity();
		yv = player->get_yvelocity();
		
		niobjects[0].movobjs();
		niobjects[0].viewtans(player->getxp(),player->getyp());
		niobjects[0].getgravity(player->getxp(),player->getyp(),xg,yg);
		niobjects[0].cull(player->getxp(),player->getyp());
		player->setgrav(xg,yg);
		
		niobjects[0].getgravity(badguy->getxp(),badguy->getyp(),xg,yg);
	
		badguy->setgrav(xg,yg);
for(count = 0;count < 50;count++)
{
		niobjects[0].getgravity(badguys[count]->getxp(),badguys[count]->getyp(),xg,yg);
	badguys[count]->setgrav(xg,yg);
}

		player->view_transform(player->getxp(),player->getyp());

		badguy->view_transform(player->getxp(),player->getyp());
for(count = 0;count < 50;count++)
{
	badguys[count]->view_transform(player->getxp(),player->getyp());
}

		//	for(count = 0;count < 200;count++)
			stars.movestar(xv,yv);
		
		display->Begin_Frame();
		//engine.Lock_Frame();
	//	for(count = 0;count < 200;count++)
			stars.drawstar();
		//engine.Unlock_Frame();
		all_projectiles->move_projectiles(diftime);
//		pellet_gun->MoveProjectile();
		//player->setdirection(direction);
		niobjects[0].draw();
		all_projectiles->draw_projectiles(player->getxp(),player->getyp());
		//		pellet_gun->DrawProjectile(player->getxp(),player->getyp());
		player->drawship();
		badguy->drawship();
	for(count = 0;count < 50;count++)
{
	badguys[count]->drawship();
}
	nframes++;
		if(nframes > 100)
		{
			char string[50];
			float fps;
			QueryPerformanceCounter(&currenttime);
			fps = (float)nframes/((float)(currenttime.QuadPart - starttime.QuadPart)/(float)timerfreq.QuadPart);
			sprintf(string,"Frame Rate %0.1f avg fps",fps);
			nframes = 0;
			QueryPerformanceCounter(&starttime);    
		}

		//text->PrintMessage(50, 50, string, rand()%255, rand()%255, rand()%255);

		if(paused) main_cursor->draw_cursor();	
		display->End_Frame();
	}
	KillTimer(hwnd,0);
aithreadp->StopThread();
		
	delete main_cursor;
	delete player;
//	delete pellet_gun;
	//delete back_music;
	//engine.DestroyTextObject(text);
	//sound_eng->ShutDown();
	//delete sound_eng;
	delete all_projectiles;
//	engine.ShutDown();
	delete_power_plant_types();
	delete_ship_types();
	delete aithreadp;
	delete badguy;
for(count = 0;count < 50;count++)
{
	playerinstance* temp;
	temp = badguys[count];
	delete temp;
}

	inputshutdown();
	return 0;
}





		
	

	

