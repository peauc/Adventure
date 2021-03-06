/*
** tekpixel.c for tekpixel in /home/wery_p/rendu/gfx_tekadventure/create_road
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Apr 10 13:57:15 2016 Paul Wery
** Last update Tue Apr 12 22:01:03 2016 Paul Wery
*/

#include "road.h"

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  t_color	*pixel;
  int		i;

  i = pos->x + (pos->y * pix->clipable.clip_width);
  if (pos->x >= 0 && pos->x < WINL
      && pos->y >= 0 && pos->y < WINH)
    {
      pixel = (t_color*)pix->pixels + i;
      pixel->full = color;
    }
}

void	road_pix(t_road *r, t_bunny_pixelarray *pix,
		 t_bunny_position *pos, unsigned int color)
{
  t_color	*pixel;
  int		i;

  i = pos->x + (pos->y * pix->clipable.clip_width);
  if (pos->x >= 0 && pos->x < r->max_x
      && pos->y >= 0 && pos->y < r->max_y)
    {
      pixel = (t_color*)pix->pixels + i;
      pixel->full = color;
    }
}

void			cop_pix(t_road *r,
				t_bunny_pixelarray *dest,
				t_bunny_pixelarray *src)
{
  t_bunny_position	pos;
  t_color		*color;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < dest->clipable.clip_height
	 && pos.y < src->clipable.clip_height)
    {
      while (pos.x < dest->clipable.clip_width
	     && pos.x < src->clipable.clip_width)
	{
	  color = (t_color*)src->pixels
	    + (pos.x + r->x + ((pos.y + r->y) * src->clipable.clip_width));
	  if (color->argb[3] != 0)
	    road_pix(r, dest, &pos, color->full);
	  pos.x += 1;
	}
      pos.x = 0;
      pos.y += 1;
    }
}
