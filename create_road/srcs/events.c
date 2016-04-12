/*
** events.c for event in /home/wery_p/rendu/gfx_tekadventure/create_road
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Apr  6 22:18:42 2016 Paul Wery
** Last update Tue Apr 12 00:19:03 2016 Paul Wery
*/

#include <unistd.h>
#include "road.h"

void	wheel_next(int wheelid UNUSED, int delta,
		   t_road *r)
{
  if (delta == 1 && r->state == 2
      && r->points.el.zaxe_a < 600)
    {
      r->points.el.zaxe_a += 2;
      r->points.el.zaxe_b += 1;
    }
  else if (delta == -1 && r->state == 2
	   && r->points.el.zaxe_a > r->points.el.axe_a)
    {
      r->points.el.zaxe_a -= 2;
      r->points.el.zaxe_b -= 1;
    }
}

t_bunny_response	wheel_mouse(int wheelid UNUSED, int delta,
				    void *data)
{
  t_road		*r;

  r = (t_road*)data;
  if (delta == 1 && r->points.el.axe_a < 500 && r->state == 1)
    {
      r->points.el.axe_a += 2;
      r->points.el.axe_b += 1;
      r->points.el.zaxe_a += 2;
      r->points.el.zaxe_b += 1;
    }
  else if (delta == -1 && r->points.el.axe_a > 10 && r->state == 1)
    {
      r->points.el.axe_a -= 2;
      r->points.el.axe_b -= 1;
      r->points.el.zaxe_a -= 2;
      r->points.el.zaxe_b -= 1;
    }
  else
    wheel_next(wheelid, delta, r);
  return (GO_ON);
}

t_bunny_response		my_click(t_bunny_event_state state,
					 t_bunny_mousebutton button,
					 void *data)
{
  t_road			*r;
  const t_bunny_position	*pos;

  r = (t_road*)data;
  pos = bunny_get_mouse_position();
  if (in_el(r, pos) == NULL && r->state <= 2)
    {
      if (state == GO_UP && button == BMB_LEFT && r->state == 0)
	ini_el(r, pos);
      else if (state == GO_UP && button == BMB_RIGHT && r->state >= 1)
	{
	  if (add_elem_next(r->list, &r->points) == -1)
	    return (EXIT_ON_ERROR);
	  ini_struct(r);
	}
      else if (state == GO_UP && button == BMB_LEFT && r->state == 1)
	r->state += 1;
    }
  click_next(state, button, pos, r);
  return (GO_ON);
}

t_bunny_response		key(t_bunny_event_state state,
				    t_bunny_keysym keysym,
				    void *data)
{
  t_road			*r;
  t_points			*it;
  const t_bunny_position	*pos;

  r = (t_road*)data;
  pos = bunny_get_mouse_position();
  it = get_elem(r, pos);
  if (state == GO_UP && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  else if (state == GO_UP && keysym == BKS_DELETE && it != NULL)
    {
      delete_elem(r->list, it);
      ini_struct(r);
    }
  return (GO_ON);
}

t_bunny_response		loop(void *data)
{
  t_road			*r;
  const t_bunny_position	*pos;

  r = (t_road*)data;
  pos = bunny_get_mouse_position();
  pix_initialize_alpha(r->pix);
  cop_pix(r->pix, r->back);
  aff_tmp(r);
  aff_all(r, pos);
  bunny_blit(&r->win->buffer, &r->pix->clipable, NULL);
  bunny_display(r->win);
  return (GO_ON);
}
