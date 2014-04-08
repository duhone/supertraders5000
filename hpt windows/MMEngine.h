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

	DISPLAY_ENGINE *dsp_eng;
	SOUND_ENGINE   *snd_eng;
	MEDIA_ENGINE   *med_eng;

public:

	MMENGINE();
	~MMENGINE();

	MEDIA_ENGINE   *CreateMediaEngine();
	DISPLAY_ENGINE *CreateDisplayEngine();
	SOUND_ENGINE   *CreateSoundEngine();
	
	void DestroyMediaEngine();
	void DestroyDisplayEngine();
	void DestroySoundEngine();
};

#endif