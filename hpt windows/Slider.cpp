// Slider.cpp: implementation of the Slider class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Slider.h"
extern void (CALLBACK* command_callback)(int command,int data);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Slider::Slider(SliderInfo* arg,Window *pwin)
{
	image_name1 = new char[strlen(arg->bar_image) + 9];
	sprintf(image_name1,"windows\\%s",arg->bar_image);
	image_name2 = new char[strlen(arg->button_image) + 9];
	sprintf(image_name2,"windows\\%s",arg->button_image);

	type = BUTTON;
	x_location = arg->x_location;
	y_location = arg->y_location;
	x_scale = arg->x_scale;
	y_scale = arg->y_scale;
	movable_minimizable = arg->minimizable_or_movable;
	clicked = false;
	parent_window = pwin;
	command = arg->command;
	data = arg->data;
	max_value = arg->MaxValue;
	min_value = arg->MinValue;


	slider_transform1 = d_engine->CreateTransform();
	slider_sprite1 = d_engine->CreateSpriteObject();
	texture1 = d_engine->CreateTextureObject();
	texture1->LoadTexture(image_name1,100,100);
	slider_sprite1->AttachTransform(slider_transform1);
	slider_sprite1->AttachTextureObject(texture1);
	texture1->SetNumFrames(1);
	back_color_red = arg->background_color_red;
	back_color_green = arg->background_color_green;
	back_color_blue = arg->background_color_blue;
	back_color_alpha = arg->background_color_alpha;
	texture1->SetSPF(1);
	slider_sprite1->SetFrame(0);
	slider_sprite1->SetColor(back_color_red,back_color_green,back_color_blue,back_color_alpha);
	slider_sprite1->SetGScale(false);

	texture2 = d_engine->CreateTextureObject();
	slider_transform2 = d_engine->CreateTransform();
	slider_sprite2 = d_engine->CreateSpriteObject();
	texture2->LoadTexture(image_name2,100,100);
	slider_sprite2->AttachTransform(slider_transform2);
	slider_sprite2->AttachTextureObject(texture2);
	texture2->SetNumFrames(1);
	texture2->SetSPF(1);
	slider_sprite2->SetFrame(0);
	slider_sprite2->SetColor(back_color_red,back_color_green,back_color_blue,back_color_alpha);
	slider_sprite2->SetGScale(false);

	upper_left_x = x_location - (50*x_scale)+parent_window->GetXLoc();
	upper_left_y = y_location + (50*y_scale)+parent_window->GetYLoc();
	lower_right_x = x_location + (50*x_scale)+parent_window->GetXLoc();
	lower_right_y = y_location - (50*y_scale)+parent_window->GetYLoc();

}

Slider::~Slider()
{
	d_engine->DestroyObject(slider_transform1);
	d_engine->DestroyObject(slider_sprite1);
	d_engine->DestroyObject(texture1);
	d_engine->DestroyObject(slider_transform2);
	d_engine->DestroyObject(slider_sprite2);
	d_engine->DestroyObject(texture2);

	delete image_name1;
	delete image_name2;

}

void Slider::Render()
{
	slider_transform1->Translate(x_location+parent_window->GetXLoc()
		,y_location+parent_window->GetYLoc(),1);
	slider_transform1->Scale(x_scale/5.0f,y_scale);
	slider_sprite1->Render();
	
	float temp;
	temp = max_value - min_value;
	temp = data/temp;
	temp -= 0.5f;
	temp *= y_scale*100.0f;

	slider_transform2->Translate(x_location+parent_window->GetXLoc()
		,y_location+temp+parent_window->GetYLoc(),1);
	slider_transform2->Scale(x_scale,y_scale/20.0f);
	slider_sprite2->Render();

}

bool Slider::click(float x,float y)
{
	
	if(!((x < upper_left_x) || (x > lower_right_x) || (y > upper_left_y)
		|| (y < lower_right_y)))
	{
		clicked = true;
		command_callback(command,data);
		if(clicked)
		{
			float temp;
			if(y < lower_right_y) y = lower_right_y;
			if(y > upper_left_y) y = upper_left_y;
			temp = y - lower_right_y;
			temp /= (upper_left_y - lower_right_y);
			temp *= (max_value - min_value);
			temp += min_value;
			data = temp;
			command_callback(command,data);

		}

	}
	return false;
}

bool Slider::Unclick()
{
	clicked = false;
	command_callback(command,data);

	return false;

}

void Slider::SetMousePosition(float x,float y)
{
	upper_left_x = x_location - (50*x_scale)+parent_window->GetXLoc();
	upper_left_y = y_location + (50*y_scale)+parent_window->GetYLoc();
	lower_right_x = x_location + (50*x_scale)+parent_window->GetXLoc();
	lower_right_y = y_location - (50*y_scale)+parent_window->GetYLoc();
	if(clicked)
	{
		float temp;
		if(y < lower_right_y) y = lower_right_y;
		if(y > upper_left_y) y = upper_left_y;
		temp = y - lower_right_y;
		temp /= (upper_left_y - lower_right_y);
		temp *= (max_value - min_value);
		temp += min_value;
		data = temp;
		command_callback(command,data);

	}


}
