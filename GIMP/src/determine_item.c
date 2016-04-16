/*
** determine_item.c for item in /home/peau_c/rendu/Lib/gfx_tekadventure/GIMP
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Apr 15 15:35:00 2016 Poc
** Last update Sat Apr 16 11:21:55 2016 marel_m
*/

#include "default.h"

int				is_clicked(t_bunny_position *pos,
					   t_bunny_pixelarray *pixel,
					   t_bunny_position offset)

{
  if (pos->x > offset.x && pos->x < offset.x + pixel->clipable.clip_width &&
      pos->y > offset.y && pos->y < offset.y + pixel->clipable.clip_height)
    return (1);
  return (0);
}

int				determine_item(t_scene scene)
{
  const	t_bunny_position	*pos;
  int				i;
  return (0);
  i = 0;
  pos = bunny_get_mouse_position();
  while (scene.item->sprite[i])
    {
      if (is_clicked(pos, scene.item->sprite[i], scene.item->pos[i]))
	scene.item->selected[i] = 1;
      i++;
    }
  return (0);
}
