/*
** draw_button.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/libgui
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 17 09:26:31 2016 Mathieu Sauvau
** Last update Sat Feb 20 17:50:50 2016 Mathieu Sauvau
*/

#include <lapin.h>
#include "libgui.h"

void		draw_contour(t_bunny_pixelarray *pix_ar,
			       t_rect *rect, int contour_size, int color)
{
  int		x;
  int		y;

  x = rect->pos.x;
  while (x >= rect->pos.x && x < rect->pos.x + rect->size.x)
    {
      y = rect->pos.y;
      while (y >= rect->pos.y && y < rect->pos.y + rect->size.y)
	{
	  if ((x >= rect->pos.x  && x < rect->pos.x + contour_size)
	      || (y >= rect->pos.y  && y < rect->pos.y + contour_size)
	      || (x >= rect->pos.x + rect->size.x - contour_size
		  && x < rect->pos.x + rect->size.x)
	      || (y >= rect->pos.y + rect->size.y - contour_size
		  && y < rect->pos.y + rect->size.y))
	    pixel(pix_ar, pos_(x, y), color);
	  ++y;
	}
      ++x;
    }
}

void		draw_(t_bunny_pixelarray *pix_ar,
		      t_rect *rect)
{
  t_color	*col;
  int		new_pos;
  int		x;
  int		y;

  x = rect->pos.x - 1;
  col = pix_ar->pixels;
  while (++x < rect->pos.x + rect->size.x)
    {
      y = rect->pos.y - 1;
      while (++y < rect->pos.y + rect->size.y)
	{
	  new_pos = pix_ar->clipable.clip_width * y + x;
	  col[new_pos].full = rect->color;
	}
    }
}
