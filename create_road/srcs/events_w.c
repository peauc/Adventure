/*
** events_w.c for events_w.c in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Apr 12 00:17:23 2016 Paul Wery
** Last update Fri Apr 15 16:05:14 2016 Paul Wery
*/

#include "road.h"

int	links_elem(t_bunny_position *start, t_points *it)
{
  if ((it->path_0[1].x == start->x && it->path_0[1].y == start->y)
      || (it->path_1[1].x == start->x && it->path_1[1].y == start->y)
      || (it->path_2[1].x == start->x && it->path_2[1].y == start->y)
      || (it->path_3[1].x == start->x && it->path_3[1].y == start->y))
    return (1);
  return (0);
}

void	cop_path_next(t_bunny_position *start, t_points *it)
{
  if (it->path == 2)
    {
      it->path_2[0].x = it->el.center.x;
      it->path_2[0].y = it->el.center.y;
      it->path_2[1].x = start->x;
      it->path_2[1].y = start->y;
      it->path += 1;
    }
  else if (it->path == 3)
    {
      it->path_3[0].x = it->el.center.x;
      it->path_3[0].y = it->el.center.y;
      it->path_3[1].x = start->x;
      it->path_3[1].y = start->y;
      it->path += 1;
    }
}

int	cop_path(t_bunny_position *start, t_points *it)
{
  if (it->path == 4 || links_elem(start, it) == 1)
    return (-1);
  if (it->path == 0)
    {
      it->path_0[0].x = it->el.center.x;
      it->path_0[0].y = it->el.center.y;
      it->path_0[1].x = start->x;
      it->path_0[1].y = start->y;
      it->path += 1;
    }
  else if (it->path == 1)
    {
      it->path_1[0].x = it->el.center.x;
      it->path_1[0].y = it->el.center.y;
      it->path_1[1].x = start->x;
      it->path_1[1].y = start->y;
      it->path += 1;
    }
  else
    cop_path_next(start, it);
  return (0);
}

void	ini_el(t_road *r, const t_bunny_position *pos)
{
  r->points.el.center.x = pos->x;
  r->points.el.center.y = pos->y;
  r->points.el.axe_a = 10;
  r->points.el.axe_b = 5;
  r->state += 1;
}
