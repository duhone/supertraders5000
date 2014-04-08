// TextBox.cpp: implementation of the TextBox class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TextBox.h"
#include "Window.h"
#include "WindowsEngineInt.h"

extern WindowsEngineInt *main_engine;

extern void (CALLBACK* command_callback)(int command,int data);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TextBox::TextBox(VectorGraphC *arg,Window *pwin)
{
	nodes = *arg;
	parent_window = pwin;

	text_info.background_color_alpha = 1.0f;
	text_info.background_color_blue = 1.0f;
	text_info.background_color_green = 1.0f;
	text_info.background_color_red = 1.0f;
	text_info.char_x_scale = .04f;
	text_info.char_y_scale = .04f;
	text_info.x_location = 0.06f;
	text_info.y_location = -.12f;
	text_info.x_scale = parent_window->GetXScale();;
	text_info.y_scale = parent_window->GetYScale()/10.0f;
	text_info.label_text = (char*)(arg->GetText())->c_str();
	text_info.format = J_LEFT;
	text = new Label(&text_info,pwin);

	int n_res = arg->GetNumChoices();
	for(int count = 0;count < n_res;count++)
	{
		Label *templ;
		text_info.x_location = 0.06f;
		text_info.y_location = -.12f - (parent_window->GetYScale() * 50) - count*0.05f;
		text_info.label_text = (char*)(arg->GetChoiceText(count))->c_str();
		templ = new Label(&text_info,pwin);
		responses.push_back(templ);
	}
}

TextBox::~TextBox()
{
	delete text;
	for(int count = 0;count < responses.size();count++)
	{
		Label *templ;
		templ = responses[count];
		delete templ;
	}

}

bool TextBox::Unclick()
{

	return false;
}

bool TextBox::click(float x,float y)
{
	int n_res = nodes.GetNumChoices();
	float tempf = parent_window->GetUpperY() -.12f - (parent_window->GetYScale() * 50);
	int count = 0;
	if(y > tempf) return false;
	while(count < n_res)
	{
		tempf -= .05f;
		if((y > tempf)) break;
		count++;
	}
	if(count < n_res) 
	{
		EnterCriticalSection(&(main_engine->window_delete_section));
		nodes.Next(count);
		delete text;
		text_info.x_location = 0.06f;
		text_info.y_location = -.12f;
		text_info.label_text = (char*)(nodes.GetText())->c_str();
		text = new Label(&text_info,parent_window);

		for(int count = 0;count < responses.size();count++)
		{
			Label *templ;
			templ = responses[count];
			delete templ;
		}
		responses.clear();
		if(nodes.GetNumChoices() == 0)
		{
			command_callback(nodes.GetCommand(),nodes.GetData());
			parent_window->Close();
		}
		int n_res = nodes.GetNumChoices();
		for(count = 0;count < n_res;count++)
		{
			Label *templ;
			text_info.x_location = 0.06f;
			text_info.y_location = -.12f - (parent_window->GetYScale() * 50) - count*0.05f;
			text_info.label_text = (char*)(nodes.GetChoiceText(count))->c_str();
			templ = new Label(&text_info,parent_window);
			responses.push_back(templ);
		}
		LeaveCriticalSection(&main_engine->window_delete_section);
	}
	return false;
}

void TextBox::Render()
{
	text->Render();
	for(int count = 0;count < responses.size();count++)
		responses[count]->Render();
}

void TextBox::SetMousePosition(float x,float y)
{

}
