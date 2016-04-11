/*
** ini_line.c for ini_line in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs/line
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Apr 11 18:25:14 2016 Paul Wery
** Last update Mon Apr 11 18:25:15 2016 Paul Wery
*/

#include "road.h"

void	ini_col(unsigned int *col, t_color *color, t_line *l)
{
  col[0] = color[0].full;
  col[1] = color[1].full;
  l->mew.full = col[0];
}

void	ini_line(t_line *l, t_bunny_position *posi, t_bunny_position *pos)
{
  l->check = 0;
  posi->x = pos[0].x;
  posi->y = pos[0].y;
  l->i = (float)(pos[1].x - pos[0].x) / (float)(pos[1].y - pos[0].y);
  l->y = (float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x);
}
