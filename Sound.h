#if !defined(sound_h)
#define sound_h

#include <dmusici.h>
//#define INITGUID
#include <windows.h>
#include <dmusicc.h>
#include <dmusici.h>



#define SND_3D			DMUS_APATH_DYNAMIC_3D 
#define SND_MONO		DMUS_APATH_DYNAMIC_MONO
#define SND_STEREO	    DMUS_APATH_DYNAMIC_STEREO
#define SND_3D_REVERB	DMUS_APATH_SHARED_STEREOPLUSREVERB

class __declspec (dllexport) SOUND_ENGINE
{
	friend class SOUND_OBJECT;
	friend class MUSIC_OBJECT;
	friend class MMENGINE;

private:

	IDirectMusicLoader8*      g_pLoader;      //Handles Loading of various SND Objects
	IDirectMusicPerformance8* g_pSoundPerformance; //Play Buffer
	IDirectMusicPerformance8* g_pMusicPerformance; // Play MIDI Buffer

public:

	// Initialize Sound Engine
	BOOL Startup(void);
	BOOL Shutdown(void);

	// Create Sound Object Instances
	SOUND_OBJECT *CreateSoundObject(void);
	MUSIC_OBJECT *CreateMusicObject(void);

	BOOL DestroySoundObject(SOUND_OBJECT *snd_obj);
	BOOL DestroyMusicObject(MUSIC_OBJECT *music_obj);
	
};

class __declspec (dllexport) SOUND_LIST
{

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
	friend class MUSIC_PLAYLIST;

private:
	SOUND_ENGINE *snd_engine;

	// Immediate Sound Buffer
	IDirectMusicSegment8*	  g_pSegment;

	WCHAR *p_filename;

	BOOL IS_PLAYLIST_ACTIVE;

	MUSIC_OBJECT();

public:

	// Sound Prototypes
	BOOL ALoadMIDI(WCHAR *filename);
	BOOL APlayMIDI(void);
	BOOL LoopMIDI(DWORD numRepeats); // NULL = Infinate ?
	BOOL StopMIDI(void);

	BOOL GetMIDIState(void);

	BOOL Refresh(void);

	MUSIC_PLAYLIST *CreatePlayList(void);
	BOOL DestroyPlayList(MUSIC_PLAYLIST *playlist_obj);

};

struct MUSIC_PLAYLIST_ITEM
{
	WCHAR *p_filename;
	char  *songname;
};

class __declspec (dllexport) MUSIC_PLAYLIST
{	
	friend MUSIC_OBJECT;

private:
	MUSIC_PLAYLIST_ITEM play_list[20];
	
	DWORD current_item;
	DWORD numSongs;

	MUSIC_OBJECT *music_obj;

	MUSIC_PLAYLIST();

public:
	BOOL AddSong(WCHAR *filename);
	BOOL RemoveSong(WCHAR *filename);

	BOOL PlayNext();
	BOOL PlayLast();
	BOOL PlayCurrent();

	BOOL PlaySong(DWORD song);

	BOOL LoopCurrent(DWORD numRepeats);

	char GetCurrentSongName();
	char SetSongName(char *name, int song);
};

#endif
