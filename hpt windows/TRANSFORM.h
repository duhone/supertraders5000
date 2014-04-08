#if !defined(TRANSFORM_H)
#define TRANSFORM_H

#include "OBJECT.h"

class __declspec (dllexport) TRANSFORM : public OBJECT
{

	friend class SPRITE_OBJECT;
	friend class PARTICLE_OBJECT;

public:

	TRANSFORM()
	{
		D3DXMatrixIdentity(&temp);
		D3DXMatrixIdentity(&matWorld);
	};

	~TRANSFORM() {};

	_inline void Rotate(float rot_ang_rad)
	{
		D3DXMatrixIdentity(&temp);	
		D3DXMatrixRotationZ(&temp, rot_ang_rad);
		D3DXMatrixMultiply(&matWorld, &temp, &matWorld);
	};

	_inline	void Translate(float dx, float dy, float dz = 0.0)
	{
		matWorld._41 = dx;
		matWorld._42 = dy;
		matWorld._43 = dz;
	};

	_inline void Scale(float dx, float dy)
	{
		matWorld._11 = dx;
		matWorld._22 = dy;
	};

	_inline void Reset(void) { D3DXMatrixIdentity(&matWorld); };

private:

	D3DXMATRIX matWorld;
	D3DXMATRIX temp;
};

#endif