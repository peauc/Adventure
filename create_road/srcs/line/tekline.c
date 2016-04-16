/*
** tekline.c for tekline in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs/line
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Apr 11 18:25:58 2016 Paul Wery
** Last update Tue Apr 12 22:54:33 2016 Paul Wery
*/

#include "road.h"

void			excp2(t_road *r, t_bunny_position *pos,
			      t_color *color, t_line *l)
{
  t_bunny_position	posi;
  unsigned int		col[2];

  ini_col(col, color, l);
  posi.x = pos[0].x;
  posi.y = pos[0].y;
  l->i = pos[0].x - pos[1].x;
  if (l->check == 0)
    while (posi.x != pos[1].x && posi.y == pos[1].y)
      {
        road_pix(r, r->pix, &posi, l->mew.full);
        if (l->i > 0)
          posi.x = posi.x - 1;
        if (l->i < 0)
          posi.x = posi.x + 1;
        l->mew.full = my_color(pos, col, l);
        l->check = 1;
      }
  road_pix(r, r->pix, &posi, color->full);
}

void			excp1(t_road *r, t_bunny_position *pos,
			      t_color *color, t_line *l)
{
  t_bunny_position	posi;
  unsigned int		col[2];

  ini_col(col, color, l);
  posi.x = pos[0].x;
  posi.y = pos[0].y;
  l->y = pos[0].y - pos[1].y;
  if (l->check == 0)
    while (posi.x == pos[1].x && posi.y != pos[1].y)
      {
        road_pix(r, r->pix, &posi, l->mew.full);
        if (l->y > 0)
          posi.y = posi.y - 1;
        if (l->y < 0)
          posi.y = posi.y + 1;
        l->mew.full = my_color(pos, col, l);
        l->check = 1;
      }
  road_pix(r, r->pix, &posi, color->full);
  excp2(r, pos, color, l);
}

int	my_liss2(t_bunny_position *posi, int z, t_bunny_position *pos)
{
  if (z > 0 || z < 0)
    {
      if (pos[0].y < pos[1].y)
        posi->y = posi->y + 1;
      if (pos[0].y > pos[1].y)
        posi->y = posi->y - 1;
      z = 0;
    }
  return (z);
}

int	my_liss1(t_bunny_position *posi, int j, t_bunny_position *pos)
{
  if (j > 0 || j < 0)
    {
      if (pos[0].x < pos[1].x)
        posi->x = posi->x + 1;
      if (pos[0].x > pos[1].x)
        posi->x = posi->x - 1;
      j = 0;
    }
  return (j);
}

void			tekline(t_road *r,
				t_bunny_position *pos,
				t_color *color)
{
  t_bunny_position	posi;
  unsigned int		col[2];
  t_line		l;

  ini_col(col, color, &l);
  ini_line(&l, &posi, pos);
  while (posi.x != pos[1].x && posi.y != pos[1].y)
    {
      l.j = l.i;
      l.z = l.y;
      road_pix(r, r->pix, &posi, l.mew.full);
      if (l.j > 0 || l.j < 0)
	l.i = l.i - l.j;
      l.j = my_liss1(&posi, l.j, pos);
      if (l.z > 0 || l.z < 0)
        l.y = l.y - l.z;
      l.z = my_liss2(&posi, l.z, pos);
      l.i = l.i + (float)(pos[1].x - pos[0].x) / (float)(pos[1].y - pos[0].y);
      l.y = l.y + (float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x);
      l.mew.full = my_color(pos, col, &l);
      l.check = 1;
    }
  road_pix(r, r->pix, &posi, color->full);
  excp1(r, pos, color, &l);
}
