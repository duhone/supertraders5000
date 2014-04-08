// RadioButton.cpp: implementation of the RadioButton class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RadioButton.h"

extern void (CALLBACK* command_callback)(int command,int data);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RadioButton::RadioButton(RadioButtonInfo* arg,Window *pwin)
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
	num_buttons = arg->num_buttons;
	max_buttons = arg->max_buttons;

	texture1 = d_engine->CreateTextureObject();
	texture1->LoadTexture(image_name1,100,100);
	texture1->SetNumFrames(1);
	texture1->SetSPF(1);

	texture2 = d_engine->CreateTextureObject();
	texture2->LoadTexture(image_name2,100,100);
	texture2->SetNumFrames(1);
	texture2->SetSPF(1);
	back_color_red = arg->background_color_red;
	back_color_green = arg->background_color_green;
	back_color_blue = arg->background_color_blue;
	back_color_alpha = arg->background_color_alpha;

	TRANSFORM *tempt;
	SPRITE_OBJECT *temps;
	for(int count = 0;count < num_buttons;count++)
	{
		tempt = d_engine->CreateTransform();
		temps = d_engine->CreateSpriteObject();
		temps->AttachTransform(tempt);
		temps->AttachTextureObject(texture1);
		temps->SetFrame(0);
		temps->SetColor(back_color_red,back_color_green,back_color_blue,back_color_alpha);
		temps->SetGScale(false);
		transforms.push_back(tempt);
		sprites.push_back(temps);
	}


	clicked = false;
	parent_window = pwin;

	upper_left_x = x_location - (50*x_scale)+parent_window->GetXLoc();
	upper_left_y = y_location + (50*y_scale)+parent_window->GetYLoc();
	lower_right_x = x_location + (50*x_scale)+parent_window->GetXLoc();
	lower_right_y = y_location - (50*y_scale)+parent_window->GetYLoc();

	command = arg->command;
	data = arg->data;

	sprites[data]->DetachTextureObjects();

	sprites[data]->AttachTextureObject(texture2);
}

RadioButton::~RadioButton()
{
	d_engine->DestroyObject(texture1);
	d_engine->DestroyObject(texture2);
	for(int count = 0;count < num_buttons;count++)
	{
		d_engine->DestroyObject(transforms[count]);
		d_engine->DestroyObject(sprites[count]);
	}
	transforms.clear();
	sprites.clear();
	delete image_name1;
	delete image_name2;
}

void RadioButton::Render()
{
	float pos,temp;
	temp = fabs(lower_right_y - upper_left_y);
	temp /= max_buttons;
	pos = upper_left_y-temp/2.0f;
	for(int count = 0;count < num_buttons;count++)
	{
		transforms[count]->Translate(x_location+parent_window->GetXLoc(),
			y_location+pos,1);
		transforms[count]->Scale(x_scale,y_scale/max_buttons);
		sprites[count]->Render();
		pos -= temp;
	}

}

bool RadioButton::click(float x,float y)
{
	
	if(!((x < upper_left_x) || (x > lower_right_x) || (y > upper_left_y)
		|| (y < lower_right_y)))
	{
		clicked = true;
		float pos,temp;
		temp = fabs(lower_right_y - upper_left_y);
		temp /= max_buttons;
		pos = upper_left_y-temp;
		sprites[data]->DetachTextureObjects();
		sprites[data]->AttachTextureObject(texture1);
		for(int count = 0;count < num_buttons;count++)
		{
			if(y >	y_location+pos)
			{
				data = count;
				break;
			}
			pos -= temp;
		}
		sprites[data]->DetachTextureObjects();
		sprites[data]->AttachTextureObject(texture2);
		command_callback(command,data);
	}
	return false;
}

bool RadioButton::Unclick()
{
	return false;

}

void RadioButton::SetMousePosition(float x,float y)
{
		upper_left_x = x_location - (50*x_scale)+parent_window->GetXLoc();
		upper_left_y = y_location + (50*y_scale)+parent_window->GetYLoc();
		lower_right_x = x_location + (50*x_scale)+parent_window->GetXLoc();
		lower_right_y = y_location - (50*y_scale)+parent_window->GetYLoc();


}
