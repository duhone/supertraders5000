#ifndef __projectile_list_H
#define __projectile_list_H
#include"beam_weapon.h"

struct proj_list_struct
{
	projectile *cur_projectile;
	proj_list_struct *next;
};

class projectile_list
{
private:
	proj_list_struct *list_front;
protected:

public:
	projectile_list();
	~projectile_list();
	void add_projectile(projectile *new_proj);
	void move_projectiles(float time);
	void draw_projectiles(float xp,float yp);
};










#endif




