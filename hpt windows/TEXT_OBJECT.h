#if !defined(TEXT_OBJECT_H)
#define TEXT_OBJECT_H

// Direct3D Includes
#include <d3d8.h>
#include <d3dx8.h>
#include <d3dx8core.h>
#include <d3dx8math.h>
#include <D3d8types.h>

// STL Includes
#include <vector>
#include <string>
#include <map>

using namespace std;

#include "display.h"
#include "OBJECT.h"

enum FORMAT {J_LEFT, J_RIGHT, J_CENTER};
 
class __declspec (dllexport) TEXT_OBJECT : public OBJECT
{
	// Classes that May Access Private Member Info
	friend class DISPLAY_ENGINE;
	friend class TEXTURE_OBJECT;
	friend class SPRITE_OBJECT;
	friend class TRANSFORM;

public:

	// Render Sprite To Display
	void Render();

	// Sprite Transformation Functions
	void Format(enum FORMAT);
	//void SetPosition(float x, float y);
	void SetColor(float r, float g, float b, float a);
	void SetFont(float xsize, float ysize);
	void SetRect(float top, float left, float width, float height);
	// Text Creation Function
	void SetText(char *string);

private:

	TEXT_OBJECT();
	~TEXT_OBJECT();

	// Pointer To Parent Object
	DISPLAY_ENGINE *dsp_engine;

	DWORD format;

	// Text Storage
	string     msgText;

	LPD3DXFONT lpD3DXFont;
	LOGFONT    LogFont;
	RECT	   textRect;

	float X_POS, Y_POS;
	D3DCOLOR txtCol;

	void RRender();
};

#endif