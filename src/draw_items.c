/*
** draw_items.c for draw in /home/peau_c/rendu/Lib/gfx_tekadventure/GIMP
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Apr 15 13:54:43 2016 Poc
** Last update Sat Apr 16 14:20:20 2016 marel_m
*/

#include "scene.h"

int	draw_items(t_item *item, t_bunny_pixelarray *pix)
{
  int	i;

  i = 0;
  while (item->sprite[i])
    {
      if (item->selected[i] == 0)
	pixelarray_copy(pix, item->sprite[i], item->pos[i]);
      i++;
    }
  return (0);
}
