/*
** checkbox.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/libgui
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 17 09:03:45 2016 Mathieu Sauvau
** Last update Wed Feb 24 15:38:03 2016 Mathieu Sauvau
*/

#include <stdlib.h>
#include <lapin.h>
#include "libgui.h"
#include "helper.h"

void		     checkbox_over_on(void *data)
{
  t_checkbox	     *checkbox;

  checkbox = data;
  if (checkbox->state == on)
    checkbox->state = over_on;
  else
    checkbox->state = over;
}

void		     checkbox_over_out(void *data)
{
  t_checkbox	     *checkbox;

  checkbox = data;
  if (checkbox->state == on || checkbox->state == over_on)
    checkbox->state = on;
  else
    checkbox->state = normal;
}

t_checkbox	     *gui_checkbox(t_bunny_pixelarray *pix_ar,
				   t_checkbox *checkbox,
				   t_texture_state *textures)
{
  onmouse_over(checkbox->rect, &checkbox_over_on, checkbox);
  onmouse_out(checkbox->rect, &checkbox_over_out, checkbox);
  if (!checkbox->texture_state)
    checkbox->texture_state = textures;
  if (textures->normal != NULL && checkbox->state == normal)
    draw_img_content(pix_ar, checkbox->rect, textures->normal);
  else if (textures->on != NULL && checkbox->state == on)
    draw_img_content(pix_ar, checkbox->rect, textures->on);
  else if (checkbox->state != over_on && checkbox->state != over)
    draw_(pix_ar, checkbox->rect);
  if (textures->over != NULL && checkbox->state == over)
    draw_img_content(pix_ar, checkbox->rect, textures->over);
  else if (textures->over_on != NULL && checkbox->state == over_on)
    draw_img_content(pix_ar, checkbox->rect, textures->over_on);
  else if (checkbox->state == over || checkbox->state == over_on)
    draw_contour(pix_ar, checkbox->rect, checkbox->contour_size,
		 checkbox->contour_color);
    my_blit(pix_ar, checkbox->label_pix,
	    pos_(checkbox->rect->pos.x - checkbox->space_label
		 + (offset_center_txt(checkbox->label).x * 2),
		 checkbox->rect->pos.y
		 + checkbox->rect->size.y / 2 - 4));
  return (checkbox);
}

t_checkbox	*new_checkbox(t_rect *rect, char *label,
			      t_bunny_pixelarray *font)
{
  t_checkbox	*checkbox;

  if ((checkbox = bunny_malloc(sizeof(t_checkbox))) == NULL ||
      (checkbox->label_pix = bunny_new_pixelarray(my_strlen(label) * 8,
						7)) == NULL)
    return (NULL);
  rect->mouse_over = false;
  checkbox->rect = rect;
  checkbox->label = label;
  checkbox->state = normal;
  checkbox->texture_state = NULL;
  checkbox->contour_color = BLACK;
  checkbox->contour_size = 2;
  checkbox->space_label = 20;
  my_fill(checkbox->label_pix, 0x00000000);
  write_png(checkbox->label_pix, font, checkbox->label);
  return (checkbox);
}
