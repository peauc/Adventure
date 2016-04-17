/*
** player.c for  in /home/sauvau_m/rendu/gfx_tekadventure/movement
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Apr 17 17:42:10 2016 Mathieu Sauvau
** Last update Sun Apr 17 18:10:37 2016 Mathieu Sauvau
*/

#include "tekadv.h"

t_bunny_position	pos_player(t_player *player, t_points *node)
{
  if (!node)
    return (pos_(0, 0));
  player->node = node;
  return (player->pos = pos_(node->el.center.x - player->sp->size.x / 2,
			     node->el.center.y - player->sp->size.y));
}

void				show_player(t_data *data, t_flip flip)
{
  anim_sprite(data->player->pix, data->player->sp, flip, 12);
  bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
  bunny_blit(&data->win->buffer,
	     &data->player->pix->clipable, &data->player->pos);
  bunny_display(data->win);
}
