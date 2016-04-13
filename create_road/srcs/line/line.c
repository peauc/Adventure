/*
** line.c for line in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs/line
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Apr 11 18:34:57 2016 Paul Wery
** Last update Tue Apr 12 23:02:20 2016 Paul Wery
*/

#include "road.h"

void	line_next(t_road *r, t_points *it, t_color *color,
		  t_bunny_position *pos)
{
  if (it->path_2[0].x != -1 && it->path_2[1].x != -1)
    {
      pos[1].x = it->path_2[1].x - r->x;
      pos[1].y = it->path_2[1].y - r->y;
      tekline(r, pos, color);
    }
  if (it->path_3[0].x != -1 && it->path_3[1].x != -1)
    {
      pos[1].x = it->path_3[1].x - r->x;
      pos[1].y = it->path_3[1].y - r->y;
      tekline(r, pos, color);
    }
}

void			line(t_road *r, t_points *it)
{
  t_color		color[2];
  t_bunny_position	pos[2];

  color[0].full = RED;
  color[1].full = RED;
  pos[0].x = it->el.center.x - r->x;
  pos[0].y = it->el.center.y - r->y;
  if (it->path_0[0].x != -1 && it->path_0[1].x != -1)
    {
      pos[1].x = it->path_0[1].x - r->x;
      pos[1].y = it->path_0[1].y - r->y;
      tekline(r, pos, color);
    }
  if (it->path_1[0].x != -1 && it->path_1[1].x != -1)
    {
      pos[1].x = it->path_1[1].x - r->x;
      pos[1].y = it->path_1[1].y - r->y;
      tekline(r, pos, color);
    }
  line_next(r, it, color, pos);
}
