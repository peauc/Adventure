/*
** envents_key.c for envents_key in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Apr 12 21:39:44 2016 Paul Wery
** Last update Tue Apr 12 23:09:04 2016 Paul Wery
*/

#include "road.h"

void	ini_struct(t_road *r)
{
  r->state = 0;
  r->points.image = r->image;
  r->points.path = 0;
  r->points.path_0[0].x = -1;
  r->points.path_0[0].y = -1;
  r->points.path_0[1].x = -1;
  r->points.path_0[1].y = -1;
  r->points.path_1[0].x = -1;
  r->points.path_1[0].y = -1;
  r->points.path_1[1].x = -1;
  r->points.path_1[1].y = -1;
  r->points.path_2[0].x = -1;
  r->points.path_2[0].y = -1;
  r->points.path_2[1].x = -1;
  r->points.path_2[1].y = -1;
  r->points.path_3[0].x = -1;
  r->points.path_3[0].y = -1;
  r->points.path_3[1].x = -1;
  r->points.path_3[1].y = -1;
  r->points.el.center.x = -1;
  r->points.el.center.y = -1;
  r->points.el.axe_a = 10;
  r->points.el.axe_b = 5;
  r->points.el.zaxe_a = 10;
  r->points.el.zaxe_b = 5;
}

void	key_next_w(t_bunny_event_state state,
		   t_bunny_keysym keysym,
		   t_road *r)
{
  if (state == GO_DOWN && keysym == BKS_DOWN
      && (r->winh + r->y) < r->max_y)
    {
      r->y += 50;
      if ((r->winh + r->y) >  r->max_y)
	r->y -= (r->winh + r->y) - r->max_y;
    }
  else if (state == GO_DOWN && keysym == BKS_UP
	   && r->y > 0)
    {
      r->y -= 50;
      if (r->y < 0)
	r->y += 0 - r->y;
    }
}

void	key_next(t_bunny_event_state state,
		 t_bunny_keysym keysym,
		 t_road *r)
{
  if (state == GO_DOWN && keysym == BKS_RIGHT
      && (r->winl + r->x) < r->max_x)
    {
      r->x += 50;
      if ((r->winl + r->x) >  r->max_x)
	r->x -= (r->winl + r->x) - r->max_x;
    }
  else if (state == GO_DOWN && keysym == BKS_LEFT
	   && r->x > 0)
    {
      r->x -= 50;
      if (r->x < 0)
	r->x += 0 - r->x;
    }
  key_next_w(state, keysym, r);
}
