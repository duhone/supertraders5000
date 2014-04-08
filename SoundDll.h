#ifndef __SOUND_ENGINE_H
#define __SOUND_ENGINE_H

#define INITGUID
#include <dmusici.h>

#define SND_3D			DMUS_APATH_DYNAMIC_3D 
#define SND_MONO		DMUS_APATH_DYNAMIC_MONO
#define SND_STEREO	    DMUS_APATH_DYNAMIC_STEREO
#define SND_3D_REVERB	DMUS_APATH_SHARED_STEREOPLUSREVERB

class __declspec (dllexport) SOUND_ENGINE
{
	friend class SOUND_OBJECT;
	friend class MUSIC_OBJECT;

private:

	IDirectMusicLoader8*      g_pLoader;      //Handles Loading of various SND Objects
	IDirectMusicPerformance8* g_pSoundPerformance; //Play Buffer
	IDirectMusicPerformance8* g_pMusicPerformance; // Play MIDI Buffer

public:

	// Initialize Sound Engine
	BOOL InitializeSound(void);
	BOOL ShutDown(void);

	// Create Sound Object Instances
	SOUND_OBJECT *CreateSoundObject(void);
	MUSIC_OBJECT *CreateMusicObject(void);

	BOOL DestroySoundObject(SOUND_OBJECT *snd_obj);
	BOOL DestroyMusicObject(MUSIC_OBJECT *music_obj);
	
};

class __declspec (dllexport) SOUND_OBJECT
{
	friend class SOUND_ENGINE;

private:
	SOUND_ENGINE *snd_engine;
	
	// Immediate Sound Buffer
	IDirectMusicSegment8*     g_pSegment;

public:
	
	// Sound Prototypes
	BOOL ALoadSound(WCHAR *filename);
	BOOL APlaySound(void);
	BOOL StopSound(void);
	
};

class __declspec (dllexport) MUSIC_OBJECT
{
	friend class SOUND_ENGINE;

private:
	SOUND_ENGINE *snd_engine;

	// Immediate Sound Buffer
	IDirectMusicSegment8*	  g_pSegment;

public:

	// Sound Prototypes
	BOOL ALoadMIDI(WCHAR *filename);
	BOOL APlayMIDI(void);
	BOOL StopMIDI(void);

};

#endif
