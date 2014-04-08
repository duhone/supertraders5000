// INPUTENGINE.h: interface for the INPUTENGINE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INPUTENGINE_H__2C06B0E6_40E8_471A_9095_E987FD7AF4D2__INCLUDED_)
#define AFX_INPUTENGINE_H__2C06B0E6_40E8_471A_9095_E987FD7AF4D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "input_object.h"
#define DLLEXPORT _declspec(dllexport)
#define DLLIMPORT _declspec(dllimport)

class DLLIMPORT INPUT_ENGINE  
{
public:
	virtual void Release() = 0;
	virtual bool FreeInputObject(INPUT_OBJECT*) = 0;
	virtual bool RegisterInputObject(INPUT_OBJECT*) = 0;
	INPUT_ENGINE();
	virtual ~INPUT_ENGINE();
	
};

#endif // !defined(AFX_INPUTENGINE_H__2C06B0E6_40E8_471A_9095_E987FD7AF4D2__INCLUDED_)
