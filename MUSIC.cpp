/*
#include "music.h"
extern SOUND_ENGINE *sound_eng;


music::music()
{
	song = sound_eng->CreateMusicObject();
}


music::~music()
{
	sound_eng->DestroyMusicObject(song);
}


void music::playsong(int song_num)
{
//	song->StopMIDI();
	unsigned short *song_name;
	switch(song_num)
	{
	case 1:
		song_name = new unsigned short[17]; 
		song_name = L"introduction.mid";
		break;
	case 2:
		song_name = new unsigned short[11];
		song_name = L"stones.mid";
		break;
	}
	song->ALoadMIDI(song_name);
	song->APlayMIDI();
//	delete song_name;
}
*/