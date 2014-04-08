// WindowsEngine.h: interface for the WindowsEngine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDOWSENGINE_H__B930CCB8_D05A_4B99_83EA_57A398C70287__INCLUDED_)
#define AFX_WINDOWSENGINE_H__B930CCB8_D05A_4B99_83EA_57A398C70287__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef HPTWINDOWS_EXPORTS
#define HPTWINDOWS_API __declspec(dllexport)
#else
#define HPTWINDOWS_API __declspec(dllimport)
#endif

#include"vectorgraphlib.h"

#define SPECIFY_ID 0
#define ASSIGN_ID 1

#define COMMAND_CLOSE 1000001



struct WindowInfo
{
	float x_location;
	float y_location;
	float x_scale;
	float y_scale;
	bool minimizable_or_movable;
	bool border;
	float border_color_red;
	float border_color_green;
	float border_color_blue;
	float background_color_red;
	float background_color_green;
	float background_color_blue;
	float background_color_alpha;
	bool created;

public:
	int id;
};

struct ImageInfo : public WindowInfo
{
	char *image_name;
};

struct LabelInfo : public WindowInfo
{
	char *label_text;
	float char_x_scale;
	float char_y_scale;
	enum FORMAT format;
};

struct ButtonInfo : public WindowInfo
{
	int command;
	int data;
	char *up_image;
	char *dn_image;
};

struct RadioButtonInfo : public ButtonInfo
{
	int num_buttons;
	int max_buttons;

};

struct SliderInfo : public WindowInfo
{
	int command;
	int data;
	int MaxValue;
	int MinValue;
	char *bar_image;
	char *button_image;


};

class HPTWINDOWS_API WindowsEngine  
{
public:
	virtual void CreateHPTTextBox(VectorGraphC* info,int parent_id) = 0;
	virtual int* CreateHPTSlider(SliderInfo* info,int parent_id) = 0;
	virtual void CreateHPTRadioButton(RadioButtonInfo* info,int parent_id) = 0;
	virtual void CreateHPTMinimizeButton(ButtonInfo* info,int parent_id) = 0;
	virtual void CreateHPTMoveButton(ButtonInfo* info,int parent_id) = 0;
	virtual void CreateHPTButton(ButtonInfo* info,int parent_id) = 0;
	virtual void CreateHPTLabel(LabelInfo *info,int parent_id) = 0;
	virtual void CreateHPTImage(ImageInfo* info,int parent_id) = 0;
	virtual int CreateHPTWindow(int type,WindowInfo* arg) = 0;
	virtual void Render() = 0;
	WindowsEngine();
	virtual ~WindowsEngine();
	virtual void Release() = 0;
	virtual void SetCallback(void (CALLBACK* f)(int command,int data)) = 0;
	virtual void SetMousePosition(float x,float y) = 0;
	virtual void EnableWindow(int id,bool arg) = 0;
	CRITICAL_SECTION window_delete_section;

};

#endif // !defined(AFX_WINDOWSENGINE_H__B930CCB8_D05A_4B99_83EA_57A398C70287__INCLUDED_)
