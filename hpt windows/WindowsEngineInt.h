// WindowsEngineInt.h: interface for the WindowsEngineInt class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDOWSENGINEINT_H__9DA09469_E568_4E37_89C3_419C841BF3C4__INCLUDED_)
#define AFX_WINDOWSENGINEINT_H__9DA09469_E568_4E37_89C3_419C841BF3C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WindowsEngine.h"
#include "INPUT_OBJECT.h"
#include"InputEngine.h"
#include"display.h"
#include "Window.h"
#include<list>
#include<vector>

using namespace std;



class WindowsEngineInt : public WindowsEngine , INPUT_OBJECT
{
public:
	virtual void CreateHPTTextBox(VectorGraphC* info,int parent_id);
	virtual int* CreateHPTSlider(SliderInfo* info,int parent_id);
	virtual void CreateHPTRadioButton(RadioButtonInfo* info,int parent_id);
	virtual void CreateHPTMinimizeButton(ButtonInfo* info,int parent_id);
	virtual void CreateHPTMoveButton(ButtonInfo* info,int parent_id);
	virtual void CreateHPTButton(ButtonInfo* info,int parent_id);
	virtual void CreateHPTLabel(LabelInfo *info,int parent_id);
	virtual void CreateHPTImage(ImageInfo* info,int parent_id);
	void RegisterInput();
	void AddRef();
	WindowsEngineInt();
	virtual ~WindowsEngineInt();
	virtual bool NewInput(int type,int data);
	virtual void Release();
	virtual void Render();
	virtual int CreateHPTWindow(int type,WindowInfo* arg);
	virtual void SetCallback(void (CALLBACK* f)(int command,int data));
	virtual void SetMousePosition(float x,float y);
	virtual void EnableWindow(int id,bool arg);


private:
	float mouse_y;
	float mouse_x;
	int ref_count;
	list<Window*> window_list;
};

#endif // !defined(AFX_WINDOWSENGINEINT_H__9DA09469_E568_4E37_89C3_419C841BF3C4__INCLUDED_)
