/*
** draw_texture_gui.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/libgui
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 24 16:07:59 2016 Mathieu Sauvau
** Last update Wed Feb 24 16:10:03 2016 Mathieu Sauvau
*/

#include <lapin.h>
#include "libgui.h"

void		check_border_x(int x, int *x2,
				 t_rect *rect, t_gui_texture *texture)
{
  if (x > rect->pos.x + texture->border->left
      && x < rect->size.x + rect->pos.x - texture->border->right - 1
      && *x2 >= texture->texture->clipable.clip_width
      - texture->border->right - 1)
    *x2 = texture->border->left - 1;
  ++*x2;
}

void		check_border_y(int y, int *y2,
				 t_rect *rect, t_gui_texture *texture)
{
  if (*y2 > texture->border->top
      && y < rect->pos.y + rect->size.y - texture->border->bottom - 1
      && *y2 >= texture->texture->clipable.clip_height
      - texture->border->bottom - 1)
    *y2 = texture->border->top - 1;
  ++*y2;
}

void			draw_img_content(t_bunny_pixelarray *pix_ar, t_rect *rect,
					 t_gui_texture *texture)
{
  t_color		*color;
  t_color		*img_color;
  int			new_pos;
  int			img_pos;
  t_bunny_position	pos;
  t_bunny_position	pos2;

  pos.x = rect->pos.x - 1;
  pos2.x = -1;
  color = pix_ar->pixels;
  img_color = texture->texture->pixels;
  while (++pos.x < rect->size.x + rect->pos.x)
    {
      check_border_x(pos.x, &pos2.x, rect, texture);
      pos.y = rect->pos.y - 1;
      pos2.y = -1;
      while (++pos.y < rect->size.y + rect->pos.y)
	{
	  check_border_y(pos.y, &pos2.y, rect, texture);
	  new_pos = pix_ar->clipable.clip_width * pos.y + pos.x;
	  img_pos = texture->texture->clipable.clip_width * pos2.y + pos2.x;
	  if (img_color[img_pos].ALPHA_ != 0)
	    color[new_pos].full = img_color[img_pos].full;
	}
    }
}
