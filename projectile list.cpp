#include "projectile list.h"

projectile_list::projectile_list()
{
	list_front = NULL;
}

projectile_list::~projectile_list()
{
//	projectile *temp = NULL;
	proj_list_struct *cur_pos = list_front;
	while(cur_pos != NULL)
	{
		if(cur_pos->cur_projectile != NULL)
		{
			delete cur_pos->cur_projectile;
		}
		cur_pos = cur_pos->next;
	}

}

void projectile_list::add_projectile(projectile *new_proj)
{
	if(new_proj == NULL) return;
	proj_list_struct *cur_pos = list_front;
	proj_list_struct *new_pos = NULL;
	if(cur_pos == NULL)
	{
		new_pos = new proj_list_struct;
		new_pos->next = NULL;
		list_front = cur_pos = new_pos;
		new_pos->cur_projectile = new_proj;
//		new_pos->cur_projectile->FireProjectile(direction,sxp,syp,velocity);
	}
	else
	{
		while(cur_pos->next != NULL)
		{
			cur_pos = cur_pos->next;
		}
		new_pos = new proj_list_struct;
		new_pos->next = NULL;
		cur_pos->next = new_pos;
		new_pos->cur_projectile = new_proj;
//		new_pos->cur_projectile->FireProjectile(direction,sxp,syp,velocity);

	}

}

void projectile_list::move_projectiles(float time)
{
	proj_list_struct *cur_pos = list_front;
	proj_list_struct *prev_pos = list_front;
	if(cur_pos != NULL)
	{
		if(cur_pos->cur_projectile != NULL)
		{
			cur_pos->cur_projectile->settime(time);
		}
	}
	while(cur_pos != NULL)
	{
		if(cur_pos->cur_projectile != NULL)
		{
			if(cur_pos->cur_projectile->MoveProjectile())
			{
				if(cur_pos == list_front)
				{
					list_front = cur_pos->next;
					delete cur_pos->cur_projectile;
					delete cur_pos;
					prev_pos = list_front;
					cur_pos = list_front;
			
				}
				else
				{
					prev_pos->next = cur_pos->next;
					delete cur_pos->cur_projectile;
					delete cur_pos;
					cur_pos = prev_pos->next;
				}
			}
			else
			{
				prev_pos = cur_pos;
				cur_pos = cur_pos->next;
			}

		}
		else
		{
			prev_pos = cur_pos;
			cur_pos = cur_pos->next;
		}
	}

}

void projectile_list::draw_projectiles(float xp,float yp)
{
	proj_list_struct *cur_pos = list_front;
	while(cur_pos != NULL)
	{
		if(cur_pos->cur_projectile != NULL)
		{
			cur_pos->cur_projectile->DrawProjectile(xp,yp);
		}
		cur_pos = cur_pos->next;
	}

}