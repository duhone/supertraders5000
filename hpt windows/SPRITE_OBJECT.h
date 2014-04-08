#if !defined (SPRITE_OBJECT_H)
#define SPRITE_OBJECT_H

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

#include "TEXTURE_OBJECT.h"

struct TEXTURE_LIST_OBJ
{
	friend class TEXTURE_OBJECT;

	TEXTURE_OBJECT *texture;
	int numFrames;
	int numCellRC;
	float recip_numCellRC;
};

class __declspec (dllexport) SPRITE_OBJECT : public OBJECT
{
	friend class DISPLAY_ENGINE;

public:

	void Render();

	_inline void SetGScale(bool val) { IS_G_SCALE = val; }
	_inline void SetMultiTex(bool val) { IS_MULTITEX = val; }
	_inline void SetBrightness(float val) {	valBrightness = D3DXVECTOR4(val, val, val, val); }
	_inline void SetColor(float r, float g, float b, float a) { RGBA = D3DXVECTOR4(r,g,b,a);}

	_inline int  GetCurFrame() { return current_frame;}
	void StepFrame();
	void SetFrame(int frame){ current_frame = frame; CalcFrame();}

	void SetTexture(int texture) { current_texture = texture; }
	void SetTime(float newtime);

	void AttachTextureObject(TEXTURE_OBJECT *texture);
	_inline void AttachTransform(TRANSFORM *trans) { transforms = trans; }

	void DetachTextureObjects();
	void RRender();	

private:
	
	SPRITE_OBJECT();
	~SPRITE_OBJECT();

	DISPLAY_ENGINE *dsp_engine;
	TRANSFORM *transforms;
	D3DXMATRIX temp;

	vector<TEXTURE_LIST_OBJ*> texture_list;

	bool IS_G_SCALE;
	bool IS_MULTITEX;

	int current_frame, current_texture, numTexRC;

	D3DXVECTOR4 RGBA, valBrightness;
	D3DXVECTOR3 cellVect;

	float I, J;
	float diftime;
	float curfliptime;

	_inline void CalcFrame()
	{	
		//Calculate Frame offset based on current texture
		I = current_frame%texture_list[current_texture]->numCellRC;
		J = floor(current_frame*texture_list[current_texture]->recip_numCellRC);
		cellVect = D3DXVECTOR3(I, J, texture_list[current_texture]->numFrames);
	}
};

#endif