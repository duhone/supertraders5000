// WindowsEngineInt.cpp: implementation of the WindowsEngineInt class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WindowsEngineInt.h"
#include"image.h"
#include"label.h"
#include"button.h"
#include"minimizebutton.h"
#include"MoveButton.h"
#include"radiobutton.h"
#include"slider.h"
#include"textbox.h"

extern INPUT_ENGINE* i_engine;
extern DISPLAY_ENGINE *d_engine;
extern WindowsEngineInt *main_engine;

int id = 1000000;
extern WindowsEngineInt *main_engine;

void (CALLBACK* command_callback)(int command,int data);


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WindowsEngineInt::WindowsEngineInt()
{
	ref_count = 0;
	InitializeCriticalSection(&window_delete_section);
}

WindowsEngineInt::~WindowsEngineInt()
{
	i_engine->FreeInputObject((INPUT_OBJECT*)main_engine);
	i_engine->Release();
	DeleteCriticalSection(&window_delete_section);
	list<Window*>::iterator tempi;
	tempi = window_list.begin();
	while(tempi != window_list.end())
	{
		delete (*tempi);
		++tempi;
	}
	window_list.clear();

}

bool WindowsEngineInt::NewInput(int type,int data)
{
	if(type == MOUSE_B1)
	{
		if(data)
		{

			list<Window*>::iterator tempi;
			tempi = window_list.begin();
			while(tempi != window_list.end())
			{
				if((*tempi)->click(mouse_x,mouse_y))
				{
					Window *tempw = (*tempi);
					window_list.erase(tempi);
					window_list.push_front(tempw);
					tempi = window_list.begin();
					while(tempi != window_list.end())
					{
						tempw = (*tempi);
						if(tempw->IsClosed())
						{
							EnterCriticalSection(&window_delete_section);
							delete tempw;
							tempi = window_list.erase(tempi);
							LeaveCriticalSection(&window_delete_section);
						}
						else tempi++;
					}

					return true;
				}
				tempi++;
			}
				
		}
		else
		{
			list<Window*>::iterator tempi;
			tempi = window_list.begin();
			while(tempi != window_list.end())
			{
				if((*tempi)->Unclick())
				{
					return true;
				}
				tempi++;
			}
		}

	}
	return false;
}

void WindowsEngineInt::AddRef()
{
	ref_count++;
}

void WindowsEngineInt::Release()
{
	ref_count--;
	main_engine = NULL;
	delete this;
}

void WindowsEngineInt::Render()
{
	//list<Window*>::reverse_iterator tempi;
	//tempi = window_list.rbegin();
	for(list<Window*>::reverse_iterator tempi = window_list.rbegin();tempi != window_list.rend();++tempi)
	{
		/*if(!(*tempi)->IsClosed())*/ (*tempi)->Render();
		//tempi++;
	}
}

int WindowsEngineInt::CreateHPTWindow(int type, WindowInfo *arg)
{
	arg->created = true;
	if(type == ASSIGN_ID)
	{
		arg->id = id;
		id++;
	}
	list<Window*>::iterator tempi;
	tempi = window_list.begin();
	int pid;
	while(tempi != window_list.end())
	{
		pid = (*tempi)->GetId();
		if(pid == arg->id)
		{
			Window *tempw = (*tempi);
			window_list.erase(tempi);
			window_list.push_front(tempw);
			arg->created = false;
			return pid;
		}
		tempi++;
	}

	Window *temp;
	temp = new Window(arg);
	window_list.push_back(temp);

	return arg->id;
}

void WindowsEngineInt::RegisterInput()
{
	i_engine->RegisterInputObject((INPUT_OBJECT*)main_engine);

}

void WindowsEngineInt::CreateHPTImage(ImageInfo *info, int parent_id)
{
	list<Window*>::iterator tempi;
	tempi = window_list.begin();
	while((tempi != window_list.end()))
	{
		if((*tempi)->GetId() == parent_id)
		{
			Image *tempwin;
			tempwin = new Image(info,(*tempi));
			(*tempi)->AddSubWindow(tempwin);
			return;
		}

		tempi++;
	}

}

void WindowsEngineInt::CreateHPTLabel(LabelInfo *info, int parent_id)
{
	list<Window*>::iterator tempi;
	tempi = window_list.begin();
	while((tempi != window_list.end()))
	{
		if((*tempi)->GetId() == parent_id)
		{
			Label *tempwin;
			tempwin = new Label(info,(*tempi));
			(*tempi)->AddSubWindow(tempwin);
			return;
		}

		tempi++;
	}

}

void WindowsEngineInt::SetCallback(void (CALLBACK* f)(int command,int data))
{
	command_callback = f;
}

void WindowsEngineInt::SetMousePosition(float x,float y)
{
	mouse_x = x;
	mouse_y = y;
	list<Window*>::iterator tempi;
	tempi = window_list.begin();
	while(tempi != window_list.end())
	{
		if(!(*tempi)->IsClosed()) (*tempi)->SetMousePosition(x,y);
		tempi++;
	}

};

void WindowsEngineInt::CreateHPTButton(ButtonInfo *info, int parent_id)
{
	list<Window*>::iterator tempi;
	tempi = window_list.begin();
	while((tempi != window_list.end()))
	{
		if((*tempi)->GetId() == parent_id)
		{
			Button *tempwin;
			tempwin = new Button(info,(*tempi));
			(*tempi)->AddSubWindow(tempwin);
			return;
		}

		tempi++;
	}

}

int* WindowsEngineInt::CreateHPTSlider(SliderInfo* info,int parent_id)
{
	Slider *tempwin;
	list<Window*>::iterator tempi;
	tempi = window_list.begin();
	while((tempi != window_list.end()))
	{
		if((*tempi)->GetId() == parent_id)
		{
			tempwin = new Slider(info,(*tempi));
			(*tempi)->AddSubWindow(tempwin);
			return tempwin->GetData();
		}

		tempi++;
	}
	return NULL;
}

void WindowsEngineInt::CreateHPTRadioButton(RadioButtonInfo* info,int parent_id)
{
	list<Window*>::iterator tempi;
	tempi = window_list.begin();
	while((tempi != window_list.end()))
	{
		if((*tempi)->GetId() == parent_id)
		{
			RadioButton *tempwin;
			tempwin = new RadioButton(info,(*tempi));
			(*tempi)->AddSubWindow(tempwin);
			return;
		}

		tempi++;
	}

}
void WindowsEngineInt::CreateHPTMinimizeButton(ButtonInfo *info, int parent_id)
{
	list<Window*>::iterator tempi;
	tempi = window_list.begin();
	while((tempi != window_list.end()))
	{
		if((*tempi)->GetId() == parent_id)
		{
			MinimizeButton *tempwin;
			tempwin = new MinimizeButton(info,(*tempi));
			(*tempi)->AddMinimizeWindow(tempwin);
			return;
		}

		tempi++;
	}

}

void WindowsEngineInt::CreateHPTMoveButton(ButtonInfo *info, int parent_id)
{
	list<Window*>::iterator tempi;
	tempi = window_list.begin();
	while((tempi != window_list.end()))
	{
		if((*tempi)->GetId() == parent_id)
		{
			MoveButton *tempwin;
			tempwin = new MoveButton(info,(*tempi));
			(*tempi)->AddSubWindow(tempwin);
			return;
		}

		tempi++;
	}

}

void WindowsEngineInt::CreateHPTTextBox(VectorGraphC* info,int parent_id)
{
	list<Window*>::iterator tempi;
	tempi = window_list.begin();
	while((tempi != window_list.end()))
	{
		if((*tempi)->GetId() == parent_id)
		{
			TextBox *tempwin;
			tempwin = new TextBox(info,(*tempi));
			(*tempi)->AddSubWindow(tempwin);
			return;
		}

		tempi++;
	}

}

void WindowsEngineInt::EnableWindow(int id,bool arg)
{
	list<Window*>::iterator tempi;
	tempi = window_list.begin();
	while((tempi != window_list.end()))
	{
		if((*tempi)->GetId() == id)
		{
			(*tempi)->EnableWindow(arg);
			return;
		}

		tempi++;
	}

}

