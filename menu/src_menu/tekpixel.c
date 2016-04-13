/*
** tekpixel.c for tekpixel in /home/wery_p/rendu/gfx_tekadventure/create_road
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Apr 10 13:57:15 2016 Paul Wery
** Last update Tue Apr 12 16:42:00 2016 Poc
*/

#include "menu.h"

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  t_color	*pixel;
  int		i;

  i = pos->x + (pos->y * pix->clipable.clip_width);
  if (pos->x >= 0 && pos->x < WIDTH
      && pos->y >= 0 && pos->y < HEIGHT)
    {
      pixel = (t_color*)pix->pixels + i;
      pixel->full = color;
    }
}

void			pixelarray_copy(t_bunny_pixelarray *dest,
					t_bunny_pixelarray *src,
					t_bunny_position offset)
{
  t_bunny_position	pos;
  t_color		*color;

  pos.x = offset.x;
  pos.y = offset.y;
  while (pos.y - offset.y < src->clipable.clip_height)
    {
      while (pos.x - offset.x < src->clipable.clip_width)
	{
	  color = (t_color*)src->pixels
	    + (pos.x - offset.x + ((pos.y - offset.y) *
				   src->clipable.clip_width));
	  if (color->argb[3] != 0)
	    tekpixel(dest, &pos, color->full);
	  pos.x += 1;
	}
      pos.x = offset.x;
      pos.y += 1;
    }
}
