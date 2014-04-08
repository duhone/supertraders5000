#if !defined(engine_h)
#define engine_h

#include <windows.h>
#include <d3d8.h>
#include <d3dx8.h>
#include <D3d8types.h>
#include <windows.h>
#include <dmusicc.h>
#include <dmusici.h>

#include "Display.h"
#include "Sound.h"
#include "Media.h"

#define INITGUID

// GRAPHICS ENGINE CLASS DEFINITION //
class __declspec (dllexport) MMENGINE
{

private:

	friend class DISPLAY_ENGINE;

	MMENGINE	*mmengine;

	DISPLAY_ENGINE *d_objs;
	SOUND_ENGINE   *s_objs;

	BOOL IS_ACTIVE;

public:

	// Graphics Engine Initialization and Shutdown Utility Functions
	BOOL		   Startup();
	BOOL		   ShutDown();

	MEDIA_ENGINE   *CreateMediaEngine();
	DISPLAY_ENGINE *CreateDisplayEngine();
	SOUND_ENGINE   *CreateSoundEngine();

	void DestroyMediaEngine(MEDIA_ENGINE *engine);
	void DestroyDisplayEngine(DISPLAY_ENGINE *engine);
	void DestroySoundEngine(SOUND_ENGINE *engine);
};

#endif