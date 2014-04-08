// Label.cpp: implementation of the Label class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Label.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Label::Label(LabelInfo* arg,Window *pwin)
{
	label_name = new char[strlen(arg->label_text) + 1];
	sprintf(label_name,"%s",arg->label_text);

	type = LABEL;
	x_location = arg->x_location;
	y_location = arg->y_location;
	x_scale = arg->x_scale;
	y_scale = arg->y_scale;
	char_x_scale = arg->char_x_scale;
	char_y_scale = arg->char_y_scale;
	movable_minimizable = arg->minimizable_or_movable;
	back_color_red = arg->background_color_red;
	back_color_green = arg->background_color_green;
	back_color_blue = arg->background_color_blue;
	back_color_alpha = arg->background_color_alpha;

	parent_window = pwin;

	text = d_engine->CreateTextObject();
	text->SetText(label_name);
	text->SetRect(y_location+parent_window->GetYLoc()/*-(50*parent_window->GetYScale())*/,
				x_location+parent_window->GetXLoc()/*+(50*parent_window->GetXScale())*/,100*x_scale,100*y_scale);
	text->SetColor(back_color_red,back_color_green,back_color_blue,back_color_alpha);
	text->SetFont(char_x_scale,char_y_scale);
	text->Format(arg->format);
}

Label::~Label()
{
	d_engine->DestroyObject(text);
	delete label_name;
}

void Label::Render()
{

	text->SetRect(y_location+parent_window->GetYLoc()+(50*parent_window->GetYScale()),
			x_location+parent_window->GetXLoc()-(50*parent_window->GetXScale()),100*x_scale,100*y_scale);

	text->Render();
}
