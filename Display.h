#if !defined(display_h)
#define display_h

// Disable a STUPID microsoft warning
#pragma warning(disable: 4251)

// DISPLAY_OBJECT_OBJECT Class Information
#include <iostream>
#include <iomanip>

#include <windows.h>

#include <d3d8.h>
#include <d3dx8.h>
#include <d3dx8core.h>
#include <D3d8types.h>

#include <vector>
#include <string>

#include "MMEngineTypes.h"

using namespace std;

// *** VERTEX DEFINITIONS ***
#define D3DFVF_SPRITEVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE| D3DFVF_NORMAL | D3DFVF_TEX1)
#define D3DFVF_PARTICVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)

// *** DISPLAY PARAMETERS ***
#define MODE_16_FS        0
#define MODE_24_FS        1
#define MODE_32_FS        2
#define MODE_WINDOWED     4

// *** RETURN ERRORS ***
#define MMDISPLAY_OK				0x00000000
#define MMDISPLAY_FAIL				0x80000001
#define MMDISPLAY_INVALID_PARAMETER 0x80000002

// *** SCREEN METRICS DEFINES ***
// Right Now Evertyingis using a conventional coordinate system
// (0, 0) bottom left, (width, height) top right
#define MIN_WIDTH  0.0
#define MIN_HEIGHT 0.0
#define MAX_WIDTH  1.0
#define MAX_HEIGHT 1.0

#define PROJ_MODE_DEFAULT		 0
#define PROJ_MODE_WINDOWXY		 1
#define PROJ_MODE_0_1_EVEN		 2
#define PROJ_MODE_SCREENXY		 3
#define PROJ_MODE_ASPECT_R		 4         
#define _PROJ_METRICS(loc,s_size) (loc*s_size - loc*(s_size/2)) // Project X Screen Coords

// *** TEXT OBJECT DEFINES ***//
#define LEFT_JUST   0
#define RIGHT_JUST  1
#define CENTER_JUST 2

// *** PARTICLE CLIPPING MODES
#define NO_CLIPPING 0
#define AUTO_WRAP	1
#define CLIP_STND	2

class __declspec (dllexport) TRANSFORM
{
public:

	BOOL IS_ROTATE;
	BOOL IS_TRANSLATE;
	BOOL IS_SCALE;

	// Transformation Matricies
	D3DXMATRIX matWorld;
	D3DXMATRIX trans;
	D3DXMATRIX rotz;
	D3DXMATRIX scale;

	void Reset(void);

	void Rotate(float rot_ang_rad);
	void Translate(float dx, float dy);
	void Scale(float dx, float dy);
	void Apply(void);

};

struct SPRITEVERTEX
{
	float     x,y,z;    // Vertex Points
	float     i,j,k;
	D3DCOLOR  color;    // Vertex Color
	float     tu, tv;   // Texture Coordinates (Texels)
};

struct PARTICLE_VERTEX
{
	float x, y, z;
	D3DCOLOR color;
};

// **************************************
// *** POINT OBJECT CLASSES & STRUCTS ***
// **************************************
class __declspec (dllexport) PARTICLE_OBJECT
{
	friend class DISPLAY_ENGINE;

	// PARTICLE CONSTRUCTOR
	PARTICLE_OBJECT();

private:

	// Pointer To Parent Object
	DISPLAY_ENGINE *dsp_engine;

	// Transformation Matricies
	TRANSFORM particle_transform;

	// Test for new or changed points
	BOOL IS_CHANGED;
	BOOL CLIP_MODE;

	// ** D3D Vertex Buffers **
	LPDIRECT3DVERTEXBUFFER8 vertex_buffer;

	// Vertex Buffer (num particles)
	PARTICLE_VERTEX *Vertex;
	DWORD numVertices;

	// Private Buffer Functions
	BOOL UpdateBuffer(void);

public:

	// Vertex Buffer Functions
	BOOL ClearBuffer(void);
	BOOL SetBufferSize(DWORD numParticles);

	// Geometric Settings
	BOOL SetOriginScreen(float x, float y);
	BOOL SetOriginIntern(float x, float y);

	// Point Specific Tranforms
	BOOL SetParticleColor(DWORD point, int r, int g, int b, int a);

	// General Purpose Particle Settings
	BOOL SetParticle(DWORD point, float x, float y);
	BOOL SetParticle(DWORD point, int r, int g, int b, int a);
	BOOL SetParticle(DWORD point, float x, float y, int r, int g, int b, int a);

	// Single Particle Transforms
	BOOL MoveParticle(DWORD point, float dx, float dy);
	BOOL TranslateParticle(DWORD point, float dx, float dy);

	// Clipping Mode
	BOOL SetClipMode(DWORD CLIP_MODE);

	// Group Transform Functions and settings
	BOOL RotateAll(float radians);
	BOOL ScaleAll(float dx, float dy);
	BOOL TranslateAll(float dx, float dy);
	BOOL SetColorAll(int r, int g, int b, int a);
	BOOL SetParticleAll(float x, float y);

	// Render Vertices to Current Frame
	BOOL RenderBuffer(void);
};

// ****************************
// *** Texture Object Class ***
// ****************************
class __declspec (dllexport) TEXTURE_OBJECT
{

	// Classes That May Access Private Member Info.
	friend class DISPLAY_ENGINE;
	friend class SPRITE_OBJECT;

private:
	TEXTURE_OBJECT();
	~TEXTURE_OBJECT();

	// Texture Pixel Width and Height
	DWORD X_SIZE;
	DWORD Y_SIZE;

	int numFrames;

	// Pointer To Parent Object
	DISPLAY_ENGINE *display_engine;
	LPDIRECT3DTEXTURE8 Texture;

	// Declare Render State of Texture (called by rendering object)
	BOOL SetRenderTexture(void);

public:

	void SetNumFrames(int numframes);

	// Load bmp, jpg, etc.. into DIRECT3DTEXTURE8
	BOOL LoadTexture(char *filename, DWORD width, DWORD height);
};

// ********************************************
// *** Sprite Object Class & Effects Defines***
// ********************************************

// Sprite Frame Container
// Holds Texture Coordinates for each frame

class __declspec (dllexport) SPRITE_OBJECT
{
	// Classes that May Access Private Member Info
	friend class DISPLAY_ENGINE;
	friend class TEXTURE_OBJECT;
	friend class TEXT_OBJECT;

private:

	// Constructor & Destructor
	SPRITE_OBJECT();
	~SPRITE_OBJECT();

	// Pointer To Parent Object
	DISPLAY_ENGINE *dsp_engine;

	// Texture Container (Sprite Frames)
	TEXTURE_OBJECT *texture_obj;

	// Sprite Transforms
	TRANSFORM *transforms;

	// Frame Rect Vertices
	LPDIRECT3DVERTEXBUFFER8 vbp;
	SPRITEVERTEX v_buffer[10];
	int numVertices;

	// Sprite Screen Location
	float X_LOC;
	float Y_LOC;

	// Width & Height (Relative to projection metrics)
	float X_SIZE;
	float Y_SIZE;

	int current_frame;

	// Shader Values
	float brightness;

	int numCellRC;
	float I;
	float J;
	
public:

	// Render Sprite To Display
	BOOL Render();

	// Sprite Transformation Functions
//	void Translate(float dx, float dy);
//	void Scale(float dx, float dy);
//	void Rotate(float rot_ang_rad);
//	void SetPosition(float x, float y);

	// Shader Effects
	void SetBrightness(float val);

	// Sprite Animation
	void StepFrame(void);
	void SetFrame(int numFrame);

	// Assign texture Object to Sprite (frame container)
	BOOL AttachTextureObject(TEXTURE_OBJECT *texture);
	BOOL AttachTransform(TRANSFORM *transforms);

	void SetSize(float dx, float dy);
};


class __declspec (dllexport) SHADER_OBJECT
{
	friend class DISPLAY_ENGINE;

public:
	int SetShader(int numShader);
	void LoadAndCreateShader(const string& strFilePath, 
							const DWORD* pDeclaration, DWORD* pHandle);
		
private:

	SHADER_OBJECT();
	~SHADER_OBJECT();

	DISPLAY_ENGINE *dsp_engine;

	DWORD shader_basic;
	DWORD shader_point;
	DWORD shader3;
};

// *************************
// *** TEXT OBJECT CLASS ***
// *************************
class __declspec (dllexport) TEXT_OBJECT
{
	// Classes that May Access Private Member Info
	friend class DISPLAY_ENGINE;
	friend class TEXTURE_OBJECT;
	friend class SPRITE_OBJECT;
	friend class TRANSFORM;

private:

	TEXT_OBJECT();
	~TEXT_OBJECT();

	TRANSFORM      *ASCII_trn;
	SPRITE_OBJECT  *ASCII_spr;
	TEXTURE_OBJECT *ASCII_tex;


	// Pointer To Parent Object
	DISPLAY_ENGINE *dsp_engine;

	// Transformation Matricies
		D3DXMATRIX matWorld;
	D3DXMATRIX trans;
		D3DXMATRIX rotz;
	D3DXMATRIX scale;

	// Text Storage
	char *string;

	float X_POS;
	float Y_POS;

public:

	// Render Sprite To Display
	void Render();

	// Sprite Transformation Functions
	void SetPosition(float x, float y);
	void ScaleText(float dx, float dy);
	void RotateText(float rot_ang_rad);
	void Justify(int just);
	void SetColor(int r, int g, int b, int a);

	// Text Creation Function
	void SetText(char *string);
};


// *****************************
// *** DISPLAY ENGINE OBJECT ***
// *****************************
class __declspec (dllexport) DISPLAY_ENGINE : SHADER_OBJECT
{
	// Classes that May Access Private Member Info
	friend class MMENGINE;
	friend class SPRITE_OBJECT;
	friend class TEXTURE_OBJECT;
	friend class SHADER_OBJECT;
	friend class PARTICLE_OBJECT;
//	friend class TEXT_OBJECT;

private:

	// Pointer To Parent Object
	MMENGINE *mmengine;

	// BOOLEAN CHECKS
	BOOL IS_BEGIN;

	// Global Surface Pointers and Variables this allows user access to DD
	D3DPRESENT_PARAMETERS d3dpp; 
	D3DDISPLAYMODE d3ddm;
	D3DCAPS8 devCaps;
	IDirect3DDevice8      *g_pd3dDevice;
	IDirect3D8			  *g_pD3D;
	BOOL bIsWindowed;

	// Display Matrix Projections
	D3DXMATRIX matProj;

	// Window Information
	int WIN_WIDTH;
	int WIN_HEIGHT;
	int WIN_BPP;
	int WIN_MODE;
	DWORD Proj_Metrics;

	//Create Shaders
	BOOL InitializeShaders(void);
	int  CurrentShader;

	void SetVertShader(int numShader = 0);

public:

	// Constructor & Destructor
	DISPLAY_ENGINE();
	~DISPLAY_ENGINE();

	// Initialization Function Calls
	BOOL Startup(HWND hWnd, int MODE, int width, int height);
//	BOOL ChangeMode(int MODE, int width, int height);
	BOOL Shutdown();

	// Frame Functions
	BOOL Begin_Frame();
	BOOL End_Frame();

	// Mode Calls
	BOOL SetProjMetrics(DWORD METRICS_MODE);

	// Child Object Creation Functions
	SPRITE_OBJECT   *CreateSpriteObject();
	TEXTURE_OBJECT  *CreateTextureObject();
	PARTICLE_OBJECT *CreatePointObject();
	TEXT_OBJECT		*CreateTextObject();
	TRANSFORM       *CreateTransform();

};

#endif
