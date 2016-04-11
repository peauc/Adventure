/*
** create_tmp.c for create_tmp in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Apr 11 02:24:44 2016 Paul Wery
** Last update Mon Apr 11 22:29:56 2016 Paul Wery
*/

#include "road.h"

t_points	*get_elem(t_road *r,
			  const t_bunny_position *pos)
{
  t_points		*it;

  it = r->list->next;
  while (it != r->list)
    {
      if (pos->x >= (it->el.center.x - it->el.axe_a)
	  && pos->x <= (it->el.center.x + it->el.axe_a)
	  && pos->y >= (it->el.center.y - it->el.axe_b)
	  && pos->y <= (it->el.center.y + it->el.axe_b))
	return (it);
      it = it->next;
    }
  return (NULL);
}

t_bunny_position	*in_el(t_road *r,
			       const t_bunny_position *pos)
{
  t_points		*it;

  it = r->list->next;
  while (it != r->list)
    {
      if (pos->x >= (it->el.center.x - it->el.axe_a)
	  && pos->x <= (it->el.center.x + it->el.axe_a)
	  && pos->y >= (it->el.center.y - it->el.axe_b)
	  && pos->y <= (it->el.center.y + it->el.axe_b))
	return (&it->el.center);
      it = it->next;
    }
  return (NULL);
}

int	in_a_el(t_points *it,
		const t_bunny_position *pos)
{
  if (pos->x >= (it->el.center.x - it->el.axe_a)
      && pos->x <= (it->el.center.x + it->el.axe_a)
      && pos->y >= (it->el.center.y - it->el.axe_b)
      && pos->y <= (it->el.center.y + it->el.axe_b))
    return (1);
  else
    return (0);
}

void		aff_all(t_road *r,
			const t_bunny_position *pos)
{
  t_points	*it;

  it = r->list->next;
  while (it != r->list)
    {
      zcircle(r->pix, &it->el, BLUE);
      if (in_a_el(it, pos) == 1)
	circle(r->pix, &it->el, YELLOW);
      else
	circle(r->pix, &it->el, RED);
      line(r->pix, it);
      it = it->next;
    }
}

void	aff_tmp(t_road *r)
{
  if (r->state == 2)
    zcircle(r->pix, &r->points.el, BLUE);
  if (r->state == 1 || r->state == 2)
    circle(r->pix, &r->points.el, RED);
}
