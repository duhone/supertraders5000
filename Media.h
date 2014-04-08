#if !defined(media_h)
#define media_h

#include <DShow.h>
#include <malloc.h>
#include <windows.h>



class __declspec (dllexport) MEDIA_ENGINE
{

	friend class MP3_OBJECT;

private:

	IGraphBuilder *g_pGraphBuilder;
	IMediaControl *g_pMediaControl;
	IMediaSeeking *g_pMediaSeeking;
	IMediaEventEx *g_pMediaEventEx;

public:

	BOOL Startup(HWND hWndMain);

	MP3_OBJECT *CreateMP3Object();

	
};

class __declspec (dllexport) MP3_OBJECT
{
	friend class MEDIA_ENGINE;

private:

	MEDIA_ENGINE *media_eng;

	IBaseFilter *pSource;

public:

	void LoadMP3(LPCWSTR wszFilename);
	void HandleMP3Events();
	void OnMP3Finish(long);
	void PlayMP3();
	void StopMP3();
};

#endif