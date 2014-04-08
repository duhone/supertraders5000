// hptwindows.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "hptwindows.h"
#include "windowsengineint.h"
#include "input engine.h"
INPUT_ENGINE* i_engine;
DISPLAY_ENGINE *d_engine;
WindowsEngineInt *main_engine = NULL;

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}



// This is an example of an exported function.
HPTWINDOWS_API WindowsEngine* GetWindowsEngine(void)
{
	if(!main_engine) 
	{
		GetInputEngine(&i_engine);
		main_engine = new WindowsEngineInt();
		main_engine->RegisterInput();
	}
	main_engine->AddRef();
	
	return main_engine;
}

HPTWINDOWS_API void StartupWindowsEngine(DISPLAY_ENGINE *argd)
{
	d_engine = argd;
}
