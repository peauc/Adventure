/*
** helper.c for  in /home/sauvau_m/rendu/gfx_tekadventure
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue Apr 12 15:38:33 2016 Mathieu Sauvau
** Last update Tue Apr 12 15:40:09 2016 Mathieu Sauvau
*/

#include "tekadv.h"

void                    my_fill(t_bunny_pixelarray *pix_ar, unsigned int color)
{
  int                   x;
  int                   y;
  t_color               *col;
  int                   new_pos;

  x = 0;
  y = 0;
  col = pix_ar->pixels;
  while (x < pix_ar->clipable.clip_width)
    {
      while (y < pix_ar->clipable.clip_height)
        {
          new_pos = pix_ar->clipable.clip_width * y  + x;
          col[new_pos].full = color;
          y++;
        }
      x++;
      y = 0;
    }
}

t_bunny_position	pos_(int x, int y)
{
  t_bunny_position	pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}
