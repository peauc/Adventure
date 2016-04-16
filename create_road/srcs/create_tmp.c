/*
** create_tmp.c for create_tmp in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Apr 11 02:24:44 2016 Paul Wery
<<<<<<< HEAD
** Last update Wed Apr 13 11:57:22 2016 Mathieu Sauvau
=======
** Last update Tue Apr 12 22:56:30 2016 Paul Wery
>>>>>>> 58a9dc824a5a78dd5ee44bbee7b0a8493c20ad5d
*/

#include "road.h"

t_points	*get_elem(t_road *r,
			  const t_bunny_position *pos)
{
  t_points		*it;

  it = r->list->next;
  while (it != r->list)
    {
      if (same_name(r->image, it->image) == 1
	  && pos->x >= (it->el.center.x - it->el.axe_a)
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
      if (same_name(r->image, it->image) == 1
	  && pos->x >= (it->el.center.x - it->el.axe_a)
	  && pos->x <= (it->el.center.x + it->el.axe_a)
	  && pos->y >= (it->el.center.y - it->el.axe_b)
	  && pos->y <= (it->el.center.y + it->el.axe_b))
	return (&it->el.center);
      it = it->next;
    }
  return (NULL);
}

int	in_a_el(t_road *r, t_points *it,
		const t_bunny_position *pos)
{
  if (same_name(r->image, it->image) == 1
      && pos->x >= (it->el.center.x - it->el.axe_a)
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
      if (same_name(r->image, it->image) == 1)
	{
	  zcircle(r, r->pix, &it->el, BLUE);
	  if (in_a_el(r, it, pos) == 1)
	    circle(r, r->pix, &it->el, YELLOW);
	  else
	    circle(r, r->pix, &it->el, RED);
	  line(r, it);
	}
      it = it->next;
    }
}

void	aff_tmp(t_road *r)
{
  if (r->state == 2)
    zcircle(r, r->pix, &r->points.el, BLUE);
  if (r->state == 1 || r->state == 2)
    circle(r, r->pix, &r->points.el, RED);
}
