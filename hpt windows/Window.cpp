// Window.cpp: implementation of the Window class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Window.h"
#include "WindowsEngineInt.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
extern WindowsEngineInt *main_engine;

Window::Window()
{

}

Window::Window(WindowInfo *arg)
{
	type = WINDOW;
	x_location = arg->x_location;
	y_location = arg->y_location;
	x_scale = arg->x_scale;
	y_scale = arg->y_scale;
	movable_minimizable = arg->minimizable_or_movable;
	window_transform = d_engine->CreateTransform();
	window_sprite = d_engine->CreateSpriteObject();
	back_texture = d_engine->CreateTextureObject();
	back_texture->LoadTexture("windows\\block.png",100,100);
	window_sprite->AttachTransform(window_transform);
	window_sprite->AttachTextureObject(back_texture);
	back_texture->SetNumFrames(1);
	back_color_red = arg->background_color_red;
	back_color_green = arg->background_color_green;
	back_color_blue = arg->background_color_blue;
	back_color_alpha = arg->background_color_alpha;
	id = arg->id;
	window_sprite->SetGScale(false);
	window_sprite->SetColor(back_color_red,back_color_green,back_color_blue,back_color_alpha);

	upper_left_x = x_location - (50*x_scale);
	upper_left_y = y_location + (50*y_scale);
	lower_right_x = x_location + (50*x_scale);
	lower_right_y = y_location - (50*y_scale);
	
	clicked = false;
	minimize_button = NULL;
	minimized = false;
	closed = false;
	enabled = true;
}

Window::~Window()
{

}

void Window::Render()
{
	if(enabled)
	{
		if(!minimized)
		{
			window_transform->Translate(x_location,y_location,1);
			window_transform->Scale(x_scale,y_scale);
			window_sprite->Render();
			for(list<Window*>::iterator tempi = sub_window_list.begin();tempi != sub_window_list.end();++tempi)
			{
				(*tempi)->Render();
			}
		}
		if(minimize_button) minimize_button->Render();
	}
}

void Window::AddSubWindow(Window *arg)
{
	sub_window_list.push_back(arg);
}

void Window::AddMinimizeWindow(Window* arg)
{
	minimize_button = arg;
}

bool Window::click(float x,float y)
{
	bool retval = false;
	if(enabled)
	{

		if(!minimized)
		{
			if((x < upper_left_x) || (x > lower_right_x) || (y > upper_left_y)
				|| (y < lower_right_y)) return false;
			else 
			{
				retval = true;
				clicked = true;
			}
		

			list<Window*>::iterator tempi;
			tempi = sub_window_list.begin();
			while(tempi != sub_window_list.end())
			{
				(*tempi)->click(x,y);
				++tempi;
			}
		}
		if(minimize_button && minimized) return minimize_button->click(x,y);
			else if(minimize_button) minimize_button->click(x,y);
		
		if(closed)
		{
			EnterCriticalSection(&main_engine->window_delete_section);
		
			list<Window*>::iterator tempi;
			tempi = sub_window_list.begin();
			Window *tempw;
			while(tempi != sub_window_list.end())
			{
				tempw = (*tempi);
				tempi = sub_window_list.erase(tempi);
				delete tempw;
				}
			sub_window_list.clear();
			if(minimize_button) delete minimize_button;
			d_engine->DestroyObject(window_transform);
			d_engine->DestroyObject(window_sprite);
			d_engine->DestroyObject(back_texture);

			LeaveCriticalSection(&main_engine->window_delete_section);

		}
	}
	return retval;
}

bool Window::Unclick()
{
	bool retval = false;

	list<Window*>::iterator tempi;
	tempi = sub_window_list.begin();
	while(tempi != sub_window_list.end())
	{
		(*tempi)->Unclick();
		++tempi;
	}
	clicked = false;
	return retval;
}

void Window::ToggleMinimize()
{
	minimized = !minimized;
}

void Window::SetMousePosition(float x, float y)
{
	if(closed) return;
	list<Window*>::iterator tempi;
	tempi = sub_window_list.begin();
	EnterCriticalSection(&main_engine->window_delete_section);
	while(tempi != sub_window_list.end())
	{
		(*tempi)->SetMousePosition(x,y);
		tempi++;
	}
	LeaveCriticalSection(&main_engine->window_delete_section);


}

void Window::MoveWindow(float x, float y)
{
	x_location += x;
	y_location += y;
	upper_left_x = x_location - (50*x_scale);
	upper_left_y = y_location + (50*y_scale);
	lower_right_x = x_location + (50*x_scale);
	lower_right_y = y_location - (50*y_scale);

}

void Window::Close()
{
	closed = true;
	
}

bool Window::IsClosed()
{
	return closed;
}

float Window::GetUpperY()
{
	return upper_left_y;
}

void Window::EnableWindow(bool arg)
{
	enabled = arg;
	minimized = false;
	if(minimize_button) minimize_button->EnableWindow(false);

}
