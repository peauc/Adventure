/*
** line.c for line in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs/line
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Apr 11 18:34:57 2016 Paul Wery
** Last update Mon Apr 11 19:01:26 2016 Paul Wery
*/

#include "road.h"

void			line(t_bunny_pixelarray *pix, t_points *it)
{
  t_color		color[2];

  color[0].full = RED;
  color[1].full = RED;
  if (it->path_0[0].x != -1 && it->path_0[1].x != -1)
    tekline(pix, it->path_0, color);
    if (it->path_1[0].x != -1 && it->path_1[1].x != -1)
    tekline(pix, it->path_1, color);
  if (it->path_2[0].x != -1 && it->path_2[1].x != -1)
    tekline(pix, it->path_2, color);
  if (it->path_3[0].x != -1 && it->path_3[1].x != -1)
    tekline(pix, it->path_3, color);
}
