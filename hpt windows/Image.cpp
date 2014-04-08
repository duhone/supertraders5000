// Image.cpp: implementation of the Image class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Image.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Image::Image(ImageInfo* arg,Window *pwin)
{
	image_name = new char[strlen(arg->image_name) + 9];
	sprintf(image_name,"windows\\%s",arg->image_name);

	type = IMAGE;
	x_location = arg->x_location;
	y_location = arg->y_location;
	x_scale = arg->x_scale;
	y_scale = arg->y_scale;
	movable_minimizable = arg->minimizable_or_movable;
	window_transform = d_engine->CreateTransform();
	window_sprite = d_engine->CreateSpriteObject();
	back_texture = d_engine->CreateTextureObject();
	back_texture->LoadTexture(image_name,100,100);
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

	parent_window = pwin;
}

Image::~Image()
{
	d_engine->DestroyObject(window_transform);
	d_engine->DestroyObject(window_sprite);
	d_engine->DestroyObject(back_texture);
	delete image_name;
}

void Image::Render()
{
	window_transform->Translate(x_location+parent_window->GetXLoc()
					,y_location+parent_window->GetYLoc(),1);
	window_transform->Scale(x_scale,y_scale);
	window_sprite->Render();

}
