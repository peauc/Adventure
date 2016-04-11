/*
** events_next.c for events_next in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Apr 11 16:55:27 2016 Paul Wery
** Last update Mon Apr 11 18:20:42 2016 Paul Wery
*/

#include <unistd.h>
#include "road.h"

void	get_three(t_road *r, const t_bunny_position *pos,
		  t_points *it, t_bunny_position *posi)
{
  if (it->path == 3)
    {
      posi = in_el(r, pos);
      if (r->state == 3)
	{
	  it->path_3[0].x = posi->x;
	  it->path_3[0].y = posi->y;
	}
      else if (r->state == 4)
	{
	  it->path_3[1].x = posi->x;
	  it->path_3[1].y = posi->y;
	}
    }
}

void	get_two(t_road *r, const t_bunny_position *pos,
		t_points *it, t_bunny_position *posi)
{
  if (it->path == 2)
    {
      posi = in_el(r, pos);
      if (r->state == 3)
	{
	  it->path_2[0].x = posi->x;
	  it->path_2[0].y = posi->y;
	}
      else if (r->state == 4)
	{
	  it->path_2[1].x = posi->x;
	  it->path_2[1].y = posi->y;
	}
    }
  else
    get_three(r, pos, it, posi);
}

void	get_one(t_road *r, const t_bunny_position *pos,
		t_points *it, t_bunny_position *posi)
{
  if (it->path == 1)
    {
      posi = in_el(r, pos);
      if (r->state == 3)
	{
	  it->path_1[0].x = posi->x;
	  it->path_1[0].y = posi->y;
	}
      else if (r->state == 4)
	{
	  it->path_1[1].x = posi->x;
	  it->path_1[1].y = posi->y;
	}
    }
  else
    get_two(r, pos, it, posi);
}

void	get_line(t_road *r, const t_bunny_position *pos,
		 t_points *it, t_bunny_position *posi)
{
  if (it->path == 0)
    {
      posi = in_el(r, pos);
      if (r->state == 3)
	{
	  it->path_0[0].x = posi->x;
	  it->path_0[0].y = posi->y;
	}
      else if (r->state == 4)
	{
	  it->path_0[1].x = posi->x;
	  it->path_0[1].y = posi->y;
	}
    }
  else
    get_one(r, pos, it, posi);
}

void			click_next(t_bunny_event_state state,
				   t_bunny_mousebutton button,
				   const t_bunny_position *pos,
				   t_road *r)
{
  static t_points	*it = NULL;

  if (r->state == 0)
    it = NULL;
  if (it == NULL)
    it = get_elem(r, pos);
  if (state == GO_UP && button == BMB_LEFT
      && in_el(r, pos) != NULL
      && (r->state == 0 || r->state > 2)
      && it->path < 4)
    {
      if (r->state == 0 || r->state == 4)
	r->state = 3;
      else if (r->state >= 3)
	r->state += 1;
      get_line(r, pos, it, NULL);
      if (r->state == 4)
	it->path += 1;
    }
}
