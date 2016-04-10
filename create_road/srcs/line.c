/*
** line.c for line in /home/wery_p/rendu/gfx_tekadventure/create_road
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Apr 10 14:50:10 2016 Paul Wery
** Last update Sun Apr 10 15:34:37 2016 Paul Wery
*/

#include "road.h"

void			line_fourth(t_bunny_pixelarray *pix,
				    t_line *point, float m, float p)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < pix->clipable.clip_height)
    {
      while (pos.x < pix->clipable.clip_width)
	{
	  if (pos.y >= (m * pos.x + p - point->width)
	      && pos.y <= (m * pos.x + p + point->width)
	      && pos.x >= point->two.x && pos.x <= point->one.x
	      && pos.y >= point->two.y && pos.y <= point->one.y)
	    tekpixel(pix, &pos, RED);
	  pos.x += 1;
	}
      pos.x = 0;
      pos.y += 1;
    }
}

void			line_three(t_bunny_pixelarray *pix,
				   t_line *point, float m, float p)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < pix->clipable.clip_height)
    {
      while (pos.x < pix->clipable.clip_width)
	{
	  if (pos.y >= (m * pos.x + p - point->width)
	      && pos.y <= (m * pos.x + p + point->width)
	      && pos.x >= point->two.x && pos.x <= point->one.x
	      && pos.y >= point->one.y && pos.y <= point->two.y)
	    tekpixel(pix, &pos, RED);
	  pos.x += 1;
	}
      pos.x = 0;
      pos.y += 1;
    }
}

void			line_two(t_bunny_pixelarray *pix,
				 t_line *point, float m, float p)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < pix->clipable.clip_height)
    {
      while (pos.x < pix->clipable.clip_width)
	{
	  if (pos.y >= (m * pos.x + p - point->width)
	      && pos.y <= (m * pos.x + p + point->width)
	      && pos.x >= point->one.x && pos.x <= point->two.x
	      && pos.y >= point->two.y && pos.y <= point->one.y)
	    tekpixel(pix, &pos, RED);
	  pos.x += 1;
	}
      pos.x = 0;
      pos.y += 1;
    }
}

void			line_one(t_bunny_pixelarray *pix,
				 t_line *point, float m, float p)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < pix->clipable.clip_height)
    {
      while (pos.x < pix->clipable.clip_width)
	{
	  if (pos.y >= (m * pos.x + p - point->width)
	      && pos.y <= (m * pos.x + p + point->width)
	      && pos.x >= point->one.x && pos.x <= point->two.x
	      && pos.y >= point->one.y && pos.y <= point->two.y)
	    tekpixel(pix, &pos, RED);
	  pos.x += 1;
	}
      pos.x = 0;
      pos.y += 1;
    }
}

void	line(t_bunny_pixelarray *pix,
	     t_line *point)
{
  float	m;
  float	p;

  m = (float)(point->two.y - point->one.y)
    / (float)(point->two.x - point->one.x);
  p = (float)point->one.y - (float)(m * (float)point->one.x);
  if (point->two.y > point->one.y && point->two.x > point->one.x)
    line_one(pix, point, m, p);
  else if (point->two.y < point->one.y && point->two.x > point->one.x)
    line_two(pix, point, m, p);
  else if (point->two.y > point->one.y && point->two.x < point->one.x)
    line_three(pix, point, m, p);
  else if (point->two.y < point->one.y && point->two.x < point->one.x)
    line_fourth(pix, point, m, p);
}
