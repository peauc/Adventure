/*
** fill.c for fill in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 11 16:25:41 2016 Poc
** Last update Sat Apr 16 14:20:32 2016 marel_m
*/

#include "scene.h"

void		my_fill(t_bunny_pixelarray *pixel)
{
  int		i;
  t_color	*color;

  i = 0;
  while (i < (pixel->clipable.clip_width * pixel->clipable.clip_height))
    {
      color = (t_color *)pixel->pixels + i;
      color->full = BLACK;
      i++;
    }
}
