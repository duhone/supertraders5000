#include "MMengine.h"

class music
{
private:
	MUSIC_OBJECT *song;
public:
	music();
	~music();
	void playsong(int song_num);
};
