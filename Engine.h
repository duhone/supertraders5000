#ifndef __ENGINE_H
#define __ENGINE_H

#include <windows.h>
#include <d3d8.h>
#include <d3dx8.h>
#include <D3d8types.h>
#include <ddraw.h>
#include <math.h>

#define MODE_FULLSCREEN 0
#define MODE_WINDOWED	1

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)

struct CUSTOMVERTEX
{
	FLOAT x, y, z;		// The transformed position for the vertex.
	DWORD color;        // The vertex color.
};

// Color Storage Structure
struct __declspec (dllexport) RGBVAL
{
	int r;
	int g;
	int b;
};

// GRAPHICS ENGINE CLASS DEFINITION //
class __declspec (dllexport) ENGINE
{
	friend class TEXTURE_OBJECT;
	friend class POINT_LIST_OBJECT;
	friend class POLYGON_OBJECT;
	friend class MESH_OBJECT;

private:
	ENGINE	     *engine;

	// Matrix Projections
	D3DXMATRIX matView;
	D3DXMATRIX matProj;

	// view port
		D3DVIEWPORT8 D3DViewPort;

		// Window Information
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;
	int WINDOW_BPP;
	int WINDOW_MODE;
	RECT CLIENT_RECT;
	HWND hWnd;

	// Frame Status
	BOOL IS_BEGIN;
	
public:

	// Global Surface Pointers and Variables this allows user access to DD
	D3DPRESENT_PARAMETERS *D3Dpp;
	IDirect3DDevice8      *g_pd3dDevice;
	IDirect3D8			  *g_pD3D;
	
	// Graphics Engine Initialization and Shutdown Utility Functions
	BOOL Startup(HWND hWnd, int MODE, int width, int height, int depth);
	BOOL ShutDown();
	
	// Frame Functions
	BOOL Begin_Frame();
	BOOL End_Frame();

	TEXTURE_OBJECT *CreateTextureObject();
	BOOL DestroyTextureObject(TEXTURE_OBJECT *texture_obj);

	POLYGON_OBJECT *CreatePolygonObject();
	BOOL DestroyPolygonObject(POLYGON_OBJECT *polygon_obj);

};

class __declspec (dllexport) POLYGON_OBJECT
{
	friend class ENGINE;

private:

	ENGINE *engine;

	D3DXMATRIX matWorld;
	D3DXMATRIX trans;
	D3DXMATRIX rotz;
	D3DXMATRIX scale;

	LPDIRECT3DVERTEXBUFFER8 g_pVB;
	LPDIRECT3DVERTEXBUFFER8 *triangleVB;
	LPDIRECT3DVERTEXBUFFER8 *pointVB;
	LPDIRECT3DVERTEXBUFFER8 *lineVB;

	int POLYGON_TYPE;

	CUSTOMVERTEX VertexBuffer[9];
	int			 numVertices;

public:
	//Create a square or something
	BOOL AddVertex(float x1, float y1, DWORD col1);

	BOOL RenderPolygon();

	void SetTexture(TEXTURE_OBJECT *texture_obj);

	void FillPolygon();
	void TranslatePolygon(float dx, float dy);
	void ScalePolygon(float dx, float dy);
	void RotatePolygon(float rot_ang_rad);

	BOOL SetVertex(float x, float y, int vertex);
};

// TEXTURE OBJECT DESCRIPTION
class __declspec (dllexport) TEXTURE_OBJECT
{
	friend class ENGINE;
	friend class POLYGON_OBJECT;

private:

		// Texture Object
	IDirect3DTexture8   *LPDIRECT3DTEXTURE8;
	ENGINE				*engine;


public:
	
	BOOL LoadTexture(int width, int height, char *filename);

};

#endif