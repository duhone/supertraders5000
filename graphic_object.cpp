// graphic_object.cpp: implementation of the graphic_object class.
//
//////////////////////////////////////////////////////////////////////

#include "graphic_object.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
extern DISPLAY_ENGINE *display;

graphic_object::graphic_object()
{
	for(int count = 0;count< 512;count++)
	{
		tex_obj[count] = NULL;
		sprite_obj[count] = NULL;
		trans_obj[count] = NULL;
		fliptime[count] = 0.2f;
		curfliptime[count] = 0.2f;
	}


}

graphic_object::~graphic_object()
{
	for(int count = 0;count< 512;count++)
	{
//		if(sprite_obj != NULL) delete sprite_obj[count];
//		if(tex_obj != NULL) delete tex_obj[count];
	}

}

void graphic_object::loadobject(int objnumber,const char* filename,int numframes)
{
	if(strlen(filename) > 0)
	{
//		if(tex_obj[objnumber] != NULL) delete tex_obj[objnumber];
//		if(sprite_obj[objnumber] != NULL) delete sprite_obj[objnumber];
	    int count;
		switch(numframes)
		{
		case frames1:
			count = 1;
			break;
		case frames4:
			count = 4;
			break;
		case frames16:
			count = 16;
			break;
		case frames64:
			count = 64;
			break;
		case frames256:
			count = 256;
			break;
		}
	
		tex_obj[objnumber] = display->CreateTextureObject();
		tex_obj[objnumber]->LoadTexture((char*)filename,100,100);
		tex_obj[objnumber]->SetNumFrames(count);
		
		trans_obj[objnumber] = display->CreateTransform();

		sprite_obj[objnumber] = display->CreateSpriteObject();
		sprite_obj[objnumber]->AttachTextureObject(tex_obj[objnumber]);
		sprite_obj[objnumber]->AttachTransform(trans_obj[objnumber]);
	/*	float count;
		switch(numframes)
		{
		case frames1:
			count = 1;
			break;
		case frames4:
			count = 2;
			break;
		case frames16:
			count = 4;
			break;
		case frames64:
			count = 8;
			break;
		case frames256:
			count = 16;
			break;
		}
	
		for(int count2 = 0;count2 < count;count2++)
			for(int count1 = 0;count1 < count;count1++)
			{
				sprite_obj[objnumber]->AddFrame((count2/count)*100,(count1/count)*100,((count2+1)/count)*100,((count1+1)/count)*100);
			}
	*/ 	sprite_obj[objnumber]->SetFrame(0);
	}
}


void graphic_object::translate(int objnumber, float x, float y)
{
	if(trans_obj[objnumber] != NULL) trans_obj[objnumber]->Translate(x,y);
}

void graphic_object::rotate(int objnumber, float theta)
{
	if(trans_obj[objnumber] != NULL) trans_obj[objnumber]->Rotate(theta);
}

void graphic_object::scale(int objnumber, float x, float y)
{
	if(trans_obj[objnumber] != NULL)  trans_obj[objnumber]->Scale(x,y);
}

void graphic_object::render(int objnumber)
{
	if(sprite_obj[objnumber] != NULL)	sprite_obj[objnumber]->Render();
}



void graphic_object::vertexcolor(int objnumb, int vertnumb, int r, int g, int b, int a)
{
	if(sprite_obj[objnumb] != NULL) sprite_obj[objnumb]->SetFrame(0);
//	if(sprite_obj[objnumb] != NULL) sprite_obj[objnumb]->VertexColor(vertnumb,r,g,b,a);
}

void graphic_object::settime(float newtime)
{
	diftime = newtime;
	for(int count = 0;count < 512;count++)
	{
		if(sprite_obj[count] != NULL)
		{
			curfliptime[count] -= diftime;
			if(curfliptime[count] <= 0.0f)
			{
	//			sprite_obj[count]->StepFrame(1);
				curfliptime[count] = fliptime[count];
			}
		}
	}
}
