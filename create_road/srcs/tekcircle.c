/*
** tekcircle.c for tekcircle in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Apr 11 16:07:41 2016 Paul Wery
** Last update Sun Apr 17 21:27:14 2016 Mathieu Sauvau
*/

#include <math.h>
#include "road.h"

void	zcircle(t_road *r, t_bunny_pixelarray *pix,
		t_el *el, unsigned int color)
{
  t_cir	c;

  c.i = 0;
  c.angle = (2 * M_PI) / 360 / 10;
  c.posi.x = el->center.x - r->x;
  c.posi.y = el->center.y - r->y;
  while (c.i <= 3600)
    {
      c.posi.x = el->center.x - r->x + (el->zaxe_a*cos(c.i * c.angle));
      c.posi.y = el->center.y - r->y + (el->zaxe_b*sin(c.i * c.angle));
      road_pix(r, pix, &c.posi, color);
      c.i = c.i + 1;
    }
}

void	circle(t_road *r, t_bunny_pixelarray *pix,
	       t_el *el, unsigned int color)
{
  t_cir	c;

  c.i = 0;
  c.angle = (2 * M_PI) / 360 / 10;
  c.posi.x = el->center.x - r->x;
  c.posi.y = el->center.y - r->y;
  while (c.i <= 3600)
    {
      c.posi.x = el->center.x - r->x + (el->axe_a*cos(c.i * c.angle));
      c.posi.y = el->center.y - r->y + (el->axe_b*sin(c.i * c.angle));
      road_pix(r, pix, &c.posi, color);
      c.i = c.i + 1;
    }
}
