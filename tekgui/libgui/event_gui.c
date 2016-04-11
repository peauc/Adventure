/*
** event.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/libgui
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 17 09:10:59 2016 Mathieu Sauvau
** Last update Sun Feb 28 15:03:10 2016 Mathieu Sauvau
*/

#include <stdlib.h>
#include <lapin.h>
#include <unistd.h>
#include "libgui.h"

bool				onmouse_over(t_rect *rect,
					     void (*my_behaviour)(void *data),
					     void *data)
{
  const t_bunny_position	*mouse_pos;

  mouse_pos = bunny_get_mouse_position();
  if (mouse_pos->x >= rect->pos.x
      && mouse_pos->x < rect->pos.x + rect->size.x
      && mouse_pos->y >= rect->pos.y
      && mouse_pos->y < rect->pos.y + rect->size.y)
    {
      if (!rect->mouse_over)
	{
	  rect->mouse_over = true;
	  if (my_behaviour != NULL)
	    my_behaviour(data);
	}
      return (true);
    }
  return (false);
}

bool				onmouse_out(t_rect *rect,
					    void (*my_behaviour)(void *data),
					    void *data)
{
  if (rect->mouse_over && !onmouse_over(rect, NULL, NULL))
    {
      rect->mouse_over = false;
      if (my_behaviour != NULL)
	my_behaviour(data);
      return (true);
    }
  return (false);
}

bool				clicked_left(t_button *gui_button)
{
  const t_bunny_position	*mouse_pos;
  const bool			*mouse_button;

  mouse_button = bunny_get_mouse_button();
  mouse_pos = bunny_get_mouse_position();
  if (mouse_button[BMB_LEFT]
      && mouse_pos->x >= gui_button->rect->pos.x
      && mouse_pos->x < gui_button->rect->pos.x + gui_button->rect->size.x
      && mouse_pos->y >= gui_button->rect->pos.y
      && mouse_pos->y < gui_button->rect->pos.y + gui_button->rect->size.y)
    {
      gui_button->state = on;
      return (true);
    }
  if (gui_button->state == on)
    gui_button->state = over;
  else
    gui_button->state = normal;
  return (false);
}

bool				clicked_checkbox(t_checkbox *checkbox,
						 t_bunny_mouse_button button,
						 t_bunny_event_state state)
{
  const t_bunny_position	*mouse_pos;

  mouse_pos = bunny_get_mouse_position();
  if (button == BMB_LEFT && state == GO_DOWN
      && mouse_pos->x >= checkbox->rect->pos.x
      && mouse_pos->x < checkbox->rect->pos.x + checkbox->rect->size.x
      && mouse_pos->y >= checkbox->rect->pos.y
      && mouse_pos->y < checkbox->rect->pos.y + checkbox->rect->size.y)
    {
      (checkbox->state == on || checkbox->state == over_on)
	      ? (checkbox->state = normal) : (checkbox->state = on);
      return (true);
    }
  return (false);
}
