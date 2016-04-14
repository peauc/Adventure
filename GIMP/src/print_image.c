/*
** print_image.c for print_image  in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Thu Apr 14 13:02:01 2016 marel_m
** Last update Thu Apr 14 13:13:34 2016 marel_m
*/

#include "default.h"

void            tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color,
			 int state)
{
  t_color       *pixel;
  int           i;

  if (pos->x >= 0 && pos->x < pix->clipable.clip_width &&
      pos->y >= 0 && pos->y < pix->clipable.clip_height)
    {
      i = pos->x + (pix->clipable.clip_width * pos->y);
      pixel = (t_color*)pix->pixels + i;
      if (color->argb[3] > 0 && (color->full != 0xFFFFFFFF
				 || state != 1))
	pixel->full = color->full;
    }
}

void                    put_pix_in_pix_txt(t_bunny_pixelarray *pix,
					   t_bunny_pixelarray *src,
					   t_bunny_position pos,
					   int plus)
{
  t_bunny_position      posi;
  t_color               *color;
  int                   i;

  posi.y = 0;
  while (pos.y < HEIGHT && posi.y < src->clipable.clip_height)
    {
      pos.x = 0;
      posi.x = 0;
      while (pos.x < WIDTH)
	{
	  i = pos.x + (pos.y * src->clipable.clip_width) + plus;
	  color = (t_color*)src->pixels + i;
	  if (color->argb[3] != 0)
	    tekpixel(pix, &pos, color, 0);
	  pos.x++;
	  posi.x++;
	}
      pos.y++;
      posi.y++;
    }
}

void            pix_initialize(t_bunny_pixelarray *pix)
{
  t_color       *color;
  int           n;
  int           i;

  n = 0;
  i = pix->clipable.clip_width * pix->clipable.clip_height;
  while (n < i)
    {
      color = (t_color*)pix->pixels + n;
      color->full = 0x00000000;
      n += 1;
    }
}
