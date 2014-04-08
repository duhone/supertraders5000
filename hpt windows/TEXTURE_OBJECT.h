#if !defined(TEXTURE_OBJECT_H)
#define TEXTURE_OBJECT_H

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

// *** VERTEX DEFINITIONS ***
#define D3DFVF_SPRITEVERTEX (D3DFVF_XYZ| D3DFVF_TEX1)

struct SPRITEVERTEX
{
	float     x,y,z;    // Vertex Points
	float     i,j,k;
	D3DCOLOR  color;    // Vertex Color
	float     tu, tv;   // Texture Coordinates (Texels)
};

class __declspec (dllexport) TEXTURE_OBJECT : public OBJECT
{
	friend class DISPLAY_ENGINE;
	friend class SPRITE_OBJECT;

public:

	void SetNumFrames(int numframes);
	void LoadTexture(char *filename, DWORD width, DWORD height);
	void SetSPF(float val);
	
private:

	TEXTURE_OBJECT();
	~TEXTURE_OBJECT();

	DISPLAY_ENGINE *dsp_engine;
	
	int numFrames;
	float spf;

	SPRITEVERTEX v_buffer[4];

	LPDIRECT3DTEXTURE8 Texture;	
	LPDIRECT3DVERTEXBUFFER8 vbp;

	void SetSize(float dx, float dy);
	void SetRenderTexture(void);
};


#endif