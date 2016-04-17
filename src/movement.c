/*
** movement.c for  in /home/sauvau_m/rendu/gfx_tekadventure/movement
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Apr 17 15:08:02 2016 Mathieu Sauvau
** Last update Sun Apr 17 22:52:03 2016 Mathieu Sauvau
*/

#include <math.h>
#include "tekadv.h"

void				move_to(t_data *data, t_bunny_position dest)
{
  t_bunny_accurate_position	u;
  double			n;
  t_bunny_accurate_position	move;
  t_flip			flip;

  u = posac_(dest.x - data->player->node->el.center.x,
	     dest.y - data->player->node->el.center.y);
  if (u.x == 0 && u.y == 0)
    return ;
  n = sqrt(pow(u.x, 2) + pow(u.y, 2));
  u = posac_(u.x / n, u.y / n);
  flip = get_row_anim(data->player->node->el.center, dest);
  while (data->player->pos.x != dest.x - data->player->sp->size.x / 2 ||
	 data->player->pos.y != dest.y - data->player->sp->size.y)
    {
      move = posac_(move.x + u.x, move.y + u.y);
      data->player->pos.x += (int)move.x;
      data->player->pos.y += (int)move.y;
      move = posac_(move.x - (int)move.x, move.y - (int)move.y);
      my_fill(data->player->pix, PINK);
      if (flip.flip)
	data->player->pix->clipable.scale.x *= -1;
      show_player(data, flip);
    }
}

void			move(t_data *data,
			     t_points *path, t_player *player)
{
  while (path)
    {
      move_to(data, path->el.center);
      pos_player(player, path);
      player->save_pos.x = player->pos.x;
      path = path->next;
    }
}
