/*
** determine_item.c for item in /home/peau_c/rendu/Lib/gfx_tekadventure/GIMP
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Apr 15 15:35:00 2016 Poc
** Last update Fri Apr 15 19:42:57 2016 marel_m
*/

#include "default.h"

int				is_clicked(t_bunny_position *pos,
					   t_bunny_pixelarray *pixel,
					   t_bunny_position offset)

{
  if (pos->x > offset.x && pos->x < offset.x + pixel->clipable.clip_width &&
      pos->y > offset.y && pos->y < offset.y + pixel->clipable.clip_height)
    printf("clickety\n");
}

int				determine_item(t_scene *scene)
{
  const	t_bunny_position	*pos;
  int				i;
  return (0);
  i = 0;
  pos = bunny_get_mouse_position();
  if (is_clicked(pos,
		 scene->item.sprite[0],
		 scene->item.pos[0]))
    printf("item\n");
}
