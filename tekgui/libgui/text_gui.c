/*
** text_gui.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/demo
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu Feb 18 14:46:01 2016 Mathieu Sauvau
** Last update Wed Feb 24 15:56:16 2016 Mathieu Sauvau
*/

#include <stdlib.h>
#include "libgui.h"

t_text	*gui_text(t_bunny_pixelarray *pix_ar,
		  t_text *text)
{
  draw_(pix_ar, text->rect);
  my_blit(pix_ar, text->txt_pix, text->rect->pos);
  return (text);
}

t_text		*new_text(t_rect *rect,
			  t_bunny_pixelarray *font, char *txt)
{
  t_text	*text;

  if ((text = bunny_malloc(sizeof(t_text))) == NULL ||
      (text->txt_pix = bunny_new_pixelarray(rect->size.x,
					    rect->size.y)) == NULL)
    return (NULL);
  text->rect = rect;
  text->txt = txt;
  text->color = BLACK;
  text->size = 7;
  my_fill(text->txt_pix, 0x00000000);
  write_txt(text->txt_pix, font, text->txt);
  return (text);
}
