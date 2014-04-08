/* Display Engine */

#if !defined(display_h)
#define display_h

#pragma warning(disable: 4251)
#pragma warning(disable: 4786)

// Direct3D Includes
#include <d3d8.h>
#include <d3dx8.h>
#include <d3dx8core.h>
#include <d3dx8math.h>
#include <D3d8types.h>

// STL Includes
#include <list>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Object Includes
#include "TRANSFORM.h"
#include "TEXTURE_OBJECT.h"
#include "SPRITE_OBJECT.h"
#include "TEXT_OBJECT.h"

//typedef multimap<float, OBJECT*, greater<float> > mmip;

struct ADAPTER_MODE
{
	D3DDISPLAYMODE DisplayMode;
	int Mode;
};

class __declspec (dllexport) SHADER_OBJECT
{
	friend class DISPLAY_ENGINE;
	friend class SPRITE_OBJECT;

public:
	void LoadAndCreateShader(const string& strFilePath, 
							const DWORD* pDeclaration, DWORD* pHandle);
		
private:

	SHADER_OBJECT();
	~SHADER_OBJECT();

	DISPLAY_ENGINE *dsp_engine;

	DWORD shader_basic;
	DWORD shader_point;
	DWORD shader3;

	D3DXVECTOR4 zeroVect;
	D3DXVECTOR4 oneVect;
	D3DXVECTOR4 constVect;
};

class __declspec (dllexport) DISPLAY_ENGINE : SHADER_OBJECT
{
	// Classes that May Access Private Member Info
	friend class MMENGINE;
	friend class SPRITE_OBJECT;
	friend class TEXTURE_OBJECT;
	friend class SHADER_OBJECT;
	friend class TEXT_OBJECT;
	friend class PARTICLE_OBJECT;

public:

	// Constructor & Destructor
	DISPLAY_ENGINE();
	~DISPLAY_ENGINE();

	// Initialization Function Calls
	BOOL Startup(HWND hWnd, int MODE, bool isWindowed);
	BOOL Shutdown();

	// Frame Functions
	void Begin_Frame();
	void End_Frame();

	// Child Object Creation Functions
	SPRITE_OBJECT   *CreateSpriteObject();
	TEXTURE_OBJECT  *CreateTextureObject();
	TEXT_OBJECT		*CreateTextObject();
	TRANSFORM       *CreateTransform();

	void DestroyObject(OBJECT*);

	bool GlobalScale(float dx, float dy);

	void getModes(vector<ADAPTER_MODE*> &modes);

private:

	// BOOLEAN CHECKS
	BOOL IS_BEGIN, IS_DEVICE_LOST;

	// Global Surface Pointers and Variables this allows user access to DD
	IDirect3DDevice8      *g_pd3dDevice;
	IDirect3D8			  *g_pD3D;
	
	D3DPRESENT_PARAMETERS d3dpp; 
	D3DDISPLAYMODE d3ddm;
	D3DCAPS8 devCaps;

	// Display Matrix Projections
	D3DXMATRIX matProj, matView;

	// Window Information
	int WIN_WIDTH, WIN_HEIGHT;
	BOOL bIsWindowed;
	HWND hWnd;

	bool ModeEnumeration();
	bool ModeValidation(int);
	bool ModeSet(int);

	vector<ADAPTER_MODE*> adapter_modes;

	//Create Shaders
	BOOL InitializeShaders(void);
	int  CurrentShader;

	//Object Rendering Tree
//	vector<mmip> rlist;

	vector<list<OBJECT *> > rlist;
};

#endif
