/*
** events.c for event in /home/wery_p/rendu/gfx_tekadventure/create_road
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Apr  6 22:18:42 2016 Paul Wery
** Last update Sun Apr 10 15:56:39 2016 Paul Wery
*/

#include "road.h"

t_bunny_response	my_click(t_bunny_event_state state UNUSED,
				 t_bunny_mousebutton button UNUSED,
				 void *your_data UNUSED)
{
  return (GO_ON);
}

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym keysym,
			    void *data UNUSED)
{
  if (state == GO_UP && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	loop(void *data)
{
  t_road		*r;
  t_line		l;

  l.one.x = 200;
  l.two.x = 800;
  l.one.y = 100;
  l.two.y = 500;
  l.width = 1;
  r = (t_road*)data;
  pix_initialize_alpha(r->pix);
  cop_pix(r->pix, r->back);
  line(r->pix, &l);
  bunny_blit(&r->win->buffer, &r->pix->clipable, NULL);
  bunny_display(r->win);
  return (GO_ON);
}
