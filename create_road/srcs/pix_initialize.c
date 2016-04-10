/*
** pix_initialize.c for pix_initialize in /home/wery_p/rendu/gfx_tekadventure/create_road
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Apr  6 23:20:25 2016 Paul Wery
** Last update Sun Apr 10 15:51:15 2016 Paul Wery
*/

#include <lapin.h>

void		pix_initialize_alpha(t_bunny_pixelarray *pix)
{
  t_color	*color;
  int		i;

  i = pix->clipable.clip_width * pix->clipable.clip_height - 1;
  while (i >= 0)
    {
      color = (t_color*)pix->pixels + i;
      color->full = 0x00000000;
      i -= 1;
    }
}

void		pix_initialize(t_bunny_pixelarray *pix)
{
  t_color	*color;
  int		i;

  i = pix->clipable.clip_width * pix->clipable.clip_height - 1;
  while (i >= 0)
    {
      color = (t_color*)pix->pixels + i;
      color->full = 0xFF000000;
      i -= 1;
    }
}
