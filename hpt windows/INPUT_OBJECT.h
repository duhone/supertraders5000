// INPUT_OBJECT.h: interface for the INPUT_OBJECT class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INPUT_OBJECT_H__E0DEE925_EE3A_4954_ADDF_70EA7DAEE656__INCLUDED_)
#define AFX_INPUT_OBJECT_H__E0DEE925_EE3A_4954_ADDF_70EA7DAEE656__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<dinput.h>

#define DLLEXPORT _declspec(dllexport)
#define DLLIMPORT _declspec(dllimport)

#define MOUSE_X  100000
#define MOUSE_Y  100001
#define MOUSE_Z  100002
#define MOUSE_B1  100003
#define MOUSE_B2  100004
#define MOUSE_B3  100005
#define MOUSE_B4  100006

#define JOYSTICK_X 200000
#define JOYSTICK_Y 200001
#define JOYSTICK_Z 200002
#define JOYSTICK_RX 200003
#define JOYSTICK_RY 200004
#define JOYSTICK_RZ 200005
#define JOYSTICK_PV1 200006
#define JOYSTICK_PV2 200007
#define JOYSTICK_PV3 200008
#define JOYSTICK_PV4 200009
#define JOYSTICK_B1 200010
#define JOYSTICK_B2 200011
#define JOYSTICK_B3 200012
#define JOYSTICK_B4 200013
#define JOYSTICK_B5 200014
#define JOYSTICK_B6 200015
#define JOYSTICK_B7 200016
#define JOYSTICK_B8 200017
#define JOYSTICK_B9 200018
#define JOYSTICK_B10 200019
#define JOYSTICK_B11 200020
#define JOYSTICK_B12 200021
#define JOYSTICK_B13 200022
#define JOYSTICK_B14 200023
#define JOYSTICK_B15 200024
#define JOYSTICK_B16 200025
#define JOYSTICK_B17 200026
#define JOYSTICK_B18 200027
#define JOYSTICK_B19 200028
#define JOYSTICK_B20 200029
#define JOYSTICK_B21 200030
#define JOYSTICK_B22 200031
#define JOYSTICK_B23 200032
#define JOYSTICK_B24 200033
#define JOYSTICK_B25 200034
#define JOYSTICK_B26 200035
#define JOYSTICK_B27 200036
#define JOYSTICK_B28 200037
#define JOYSTICK_B29 200038
#define JOYSTICK_B30 200039
#define JOYSTICK_B31 200040
#define JOYSTICK_B32 200041
#define JOYSTICK_SLIDER1 200042
#define JOYSTICK_SLIDER2 200043

class DLLEXPORT INPUT_OBJECT  
{
public:
	virtual bool NewInput(int type,int data) = 0;

	INPUT_OBJECT();
	virtual ~INPUT_OBJECT();
	
	bool keys[256];
	int mouse_x;
	int mouse_y;
	int mouse_z;
	bool mouse_keys[4];
	int joy_x;
	int joy_y;
	int joy_z;
	int joy_rx;
	int joy_ry;
	int joy_rz;
	int sliders[2];
	int pov_hats[4];
	bool joy_keys[32];

};

#endif // !defined(AFX_INPUT_OBJECT_H__E0DEE925_EE3A_4954_ADDF_70EA7DAEE656__INCLUDED_)
