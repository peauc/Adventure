/*
** helper.c for  in /home/sauvau_m/rendu/gfx_tekadventure
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue Apr 12 15:38:33 2016 Mathieu Sauvau
** Last update Sun Apr 17 23:36:43 2016 Poc
*/

#include "tekadv.h"

int				my_fill(t_bunny_pixelarray *pix_ar,
					unsigned int color)
{
  int			x;
  int			y;
  t_color		*col;
  int			new_pos;

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
  return (0);
}

t_bunny_position		pos_(int x, int y)
{
  t_bunny_position		pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}

t_bunny_accurate_position	posac_(double x, double y)
{
  t_bunny_accurate_position	pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}

bool				cmp_position(t_bunny_position pos1,
					     t_bunny_position pos2)
{
  if (pos1.x == pos2.x && pos1.y == pos2.y)
    return (true);
  return (false);
}
