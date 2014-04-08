// Button.cpp: implementation of the Button class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Button.h"

extern void (CALLBACK* command_callback)(int command,int data);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Button::Button(ButtonInfo* arg,Window *pwin)
{
	image_name1 = new char[strlen(arg->up_image) + 9];
	sprintf(image_name1,"windows\\%s",arg->up_image);
	image_name2 = new char[strlen(arg->dn_image) + 9];
	sprintf(image_name2,"windows\\%s",arg->dn_image);

	type = BUTTON;
	x_location = arg->x_location;
	y_location = arg->y_location;
	x_scale = arg->x_scale;
	y_scale = arg->y_scale;
	movable_minimizable = arg->minimizable_or_movable;
	window_transform = d_engine->CreateTransform();
	window_sprite = d_engine->CreateSpriteObject();
	back_texture = d_engine->CreateTextureObject();
	back_texture->LoadTexture(image_name1,100,100);
	window_sprite->AttachTransform(window_transform);
	window_sprite->AttachTextureObject(back_texture);
	back_texture->SetNumFrames(1);
	back_color_red = arg->background_color_red;
	back_color_green = arg->background_color_green;
	back_color_blue = arg->background_color_blue;
	back_color_alpha = arg->background_color_alpha;
	back_texture->SetSPF(1);
	window_sprite->SetFrame(0);
	window_sprite->SetColor(back_color_red,back_color_green,back_color_blue,back_color_alpha);
	window_sprite->SetGScale(false);

	texture2 = d_engine->CreateTextureObject();
	window_transform2 = d_engine->CreateTransform();
	window_sprite2 = d_engine->CreateSpriteObject();
	texture2->LoadTexture(image_name2,100,100);
	window_sprite2->AttachTransform(window_transform2);
	window_sprite2->AttachTextureObject(texture2);
	texture2->SetNumFrames(1);
	texture2->SetSPF(1);
	window_sprite2->SetFrame(0);
	window_sprite2->SetColor(back_color_red,back_color_green,back_color_blue,back_color_alpha);
	window_sprite2->SetGScale(false);
	clicked = false;
	parent_window = pwin;

	upper_left_x = x_location - (50*x_scale)+parent_window->GetXLoc();
	upper_left_y = y_location + (50*y_scale)+parent_window->GetYLoc();
	lower_right_x = x_location + (50*x_scale)+parent_window->GetXLoc();
	lower_right_y = y_location - (50*y_scale)+parent_window->GetYLoc();

	command = arg->command;
	data = arg->data;
}

Button::~Button()
{
	d_engine->DestroyObject(window_transform);
	d_engine->DestroyObject(window_sprite);
	d_engine->DestroyObject(back_texture);
	d_engine->DestroyObject(texture2);
	d_engine->DestroyObject(window_transform2);
	d_engine->DestroyObject(window_sprite2);
	delete image_name1;
	delete image_name2;
}

void Button::Render()
{
	if(!clicked)
	{
		window_transform->Translate(x_location+parent_window->GetXLoc()
					,y_location+parent_window->GetYLoc(),1);
		window_transform->Scale(x_scale,y_scale);
		window_sprite->Render();
	}
	else
	{
		window_transform2->Translate(x_location+parent_window->GetXLoc()
					,y_location+parent_window->GetYLoc(),1);
		window_transform2->Scale(x_scale,y_scale);
		window_sprite2->Render();
	}


}

bool Button::click(float x,float y)
{
	
	if(!((x < upper_left_x) || (x > lower_right_x) || (y > upper_left_y)
		|| (y < lower_right_y)))
	{
		clicked = true;
		if(command == COMMAND_CLOSE)
		{
			parent_window->Close();
			command_callback(command,parent_window->GetId());
		}
		else
			command_callback(command,data);
	
	}
	return false;
}

bool Button::Unclick()
{
	if(clicked)
	{
		clicked = false;
	}
	return false;

}

void Button::SetMousePosition(float x,float y)
{
		upper_left_x = x_location - (50*x_scale)+parent_window->GetXLoc();
		upper_left_y = y_location + (50*y_scale)+parent_window->GetYLoc();
		lower_right_x = x_location + (50*x_scale)+parent_window->GetXLoc();
		lower_right_y = y_location - (50*y_scale)+parent_window->GetYLoc();


}
