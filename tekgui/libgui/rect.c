/*
** rect.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/libgui
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 17 09:05:56 2016 Mathieu Sauvau
** Last update Thu Feb 18 16:06:29 2016 Mathieu Sauvau
*/

#include <lapin.h>
#include <stdlib.h>
#include "libgui.h"

t_rect		*new_rect(t_bunny_position pos,
			 t_bunny_position size,
			 int color)
{
  t_rect	*rect;

  if ((rect = bunny_malloc(sizeof(t_rect))) == NULL)
    return (NULL);
  rect->pos = pos;
  rect->size = size;
  rect->color = color;
  rect->mouse_over = false;
  return (rect);
}

t_bunny_position	pos_(int x, int y)
{
  t_bunny_position	pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}

t_bunny_position      get_center(t_rect *rect, t_bunny_position offset)
{
  t_bunny_position     center;

  center.x = rect->pos.x + rect->size.x / 2 + offset.x;
  center.y = rect->pos.y + rect->size.y / 2 + offset.y;
  return (center);
}
