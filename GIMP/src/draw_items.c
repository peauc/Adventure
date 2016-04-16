/*
** draw_items.c for draw in /home/peau_c/rendu/Lib/gfx_tekadventure/GIMP
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Apr 15 13:54:43 2016 Poc
** Last update Sat Apr 16 11:32:02 2016 Poc
*/

#include "default.h"

int	draw_items(t_item *item, t_bunny_pixelarray *pix)
{
  int	i;

  i = 0;
  while (item->sprite[i])
    {
      if (item->selected[i] == 0)
	pixelarray_copy(pix, item->sprite[i], item->pos[i]);
      printf("pos.x = %d pos.y = %d\n", item->pos[i].x, item->pos[i].y);
      i++;
    }
}
