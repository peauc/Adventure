/*
** button.c for tekgui in /home/sauvau_m/rendu/gfx_tekgui
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue Feb  9 12:09:01 2016 Mathieu Sauvau
** Last update Wed Feb 24 15:34:31 2016 Mathieu Sauvau
*/

#include <stdlib.h>
#include <lapin.h>
#include "libgui.h"
#include "helper.h"

void		     button_over_on(void *data)
{
  t_button	     *button;

  button = data;
  button->state = over;
}

void		     button_over_out(void *data)
{
  t_button	     *button;

  button = data;
  button->state = normal;
}

t_button	     *gui_button(t_bunny_pixelarray *pix_ar,
				 t_button *button,
				 t_texture_state *textures)
{
  onmouse_over(button->rect, &button_over_on, button);
  onmouse_out(button->rect, &button_over_out, button);
  if (!button->texture_state)
    button->texture_state = textures;
  if (textures->normal != NULL && button->state == normal)
    draw_img_content(pix_ar, button->rect, textures->normal);
  else if (textures->on != NULL && button->state == on)
    draw_img_content(pix_ar, button->rect, textures->on);
  else if (button->state != over && button->state != over_on)
    draw_(pix_ar, button->rect);
  if (textures->over != NULL && button->state == over)
    draw_img_content(pix_ar, button->rect, textures->over);
  else if (button->state == over || button->state == over_on)
    draw_contour(pix_ar, button->rect, button->contour_size,
		 button->contour_color);
  my_blit(pix_ar, button->label_pix, get_center(button->rect,
						offset_center_txt(button->label)));
  return (button);
}

t_button	*new_button(t_rect *rect, char *label,
			    t_bunny_pixelarray *font,
			    void (*onclick)())
{
  t_button	*button;

  if ((button = bunny_malloc(sizeof(t_button))) == NULL ||
      (button->label_pix = bunny_new_pixelarray(my_strlen(label) * 8,
						7)) == NULL)
    return (NULL);
  rect->mouse_over = false;
  button->rect = rect;
  button->label = label;
  button->onclick = onclick;
  button->state = normal;
  button->texture_state = NULL;
  button->contour_color = BLACK;
  button->contour_size = 2;
  my_fill(button->label_pix, 0x00000000);
  write_png(button->label_pix, font, button->label);
  return (button);
}
