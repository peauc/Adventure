/*
** menu.c for menu in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 11 16:24:49 2016 Poc
** Last update Sun Apr 17 19:39:08 2016 marel_m
*/

#include <stdlib.h>
#include "tekadv.h"

int		draw_menu_background(t_bunny_pixelarray *pixel)
{
  int		i;
  t_color	*color;

  i = WIDTH * (HEIGHT * 0.75);
  while (i < WIDTH * HEIGHT)
    {
      color = (t_color*) pixel->pixels + i;
      color->full = BLACK;
      i++;
    }

  return (0);
}

int		draw_menu(t_bunny_pixelarray *pixel, t_menu *menu)
{
  int		i;

  i = 0;
  draw_menu_background(pixel);
  while (i < 4)
    {
      if (menu->buttons[i].is_clicked == 0)
	pixelarray_copy(pixel, menu->buttons[i].sprite, menu->buttons[i].start);
      else
	pixelarray_copy(pixel, menu->buttons[i].active_sprite, menu->buttons[i].start);
      i++;
    }
  return (0);
}
