/*
** menu.c for menu in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 11 16:24:49 2016 Poc
** Last update Mon Apr 11 18:16:36 2016 Poc
*/

#include <stdlib.h>
#include "default.h"

int		draw_menu_background(t_bunny_pixelarray *pixel)
{
  int		i;
  t_color	*color;

  i = WIDTH * (HEIGHT * 0.75);
  while (i < WIDTH * HEIGHT)
    {
      color = (t_color*) pixel->pixels + i;
      color->full = BLUE;
      i++;
    }

  return (0);
}

int		draw_menu_separation(t_bunny_pixelarray *pixel)
{
  int		i;
  t_color	*color;

  i = WIDTH * (HEIGHT * 0.75);
  while (i < WIDTH * HEIGHT)
    {
      color = (t_color *) pixel->pixels + i;
      if (i % (WIDTH / 2) == 0)
	color->full = GREEN;
      i++;
    }
}

int		draw_menu(t_bunny_pixelarray *pixel)
{
  static t_menu	*menu = NULL;

  if (menu == NULL)
    if (load_menu(&menu))
      return (1);
  draw_menu_background(pixel);
  draw_menu_separation(pixel);
}
