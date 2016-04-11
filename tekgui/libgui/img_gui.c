/*
** img_gui.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/libgui
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 17 09:17:45 2016 Mathieu Sauvau
** Last update Sun Feb 28 21:25:43 2016 Mathieu Sauvau
*/

#include <stdlib.h>
#include <lapin.h>
#include <unistd.h>
#include "libgui.h"

t_img		*new_img(t_rect *rect, char *label, char *texture)
{
  t_img		*img;

  if ((img = bunny_malloc(sizeof(t_img))) == NULL
      || (img->img = bunny_load_picture(texture)) == NULL)
    return (NULL);
  rect->mouse_over = false;
  img->rect = rect;
  img->label = label;
  return (img);
}

void		draw_img(t_bunny_pixelarray *pix_ar,
			 t_img *img, render_type type,
			 t_bunny_position clip_pos)
{
  img->img->scale.x = 1;
  img->img->scale.y = 1;
  if (type == scale)
    {
      img->img->scale.x *= (double)1
	/ ((double)img->img->clip_width / (double)img->rect->size.x);
      img->img->scale.y *= (double)1
	/ ((double)img->img->clip_height / (double)img->rect->size.y);
    }
  else if (type == crop)
    {
      img->img->clip_width = img->rect->size.x;
      img->img->clip_height = img->rect->size.y;
      img->img->clip_x_position = clip_pos.x;
      img->img->clip_y_position = clip_pos.y;
    }
  bunny_blit(&pix_ar->clipable.buffer, img->img, &img->rect->pos);
}
