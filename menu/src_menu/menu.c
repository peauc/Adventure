/*
** menu.c for menu in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 11 16:24:49 2016 Poc
** Last update Mon Apr 11 20:26:58 2016 Poc
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
      color->full = BLACK;
      i++;
    }

  return (0);
}

int		draw_menu(t_bunny_pixelarray *pixel)
{
  static t_menu	*menu = NULL;

  if (menu == NULL)
    if (load_menu(&menu))
      return (1);
  draw_menu_background(pixel);
  pixelarray_copy(pixel, menu->buttons[0].sprite, menu->buttons[0].start);
  pixelarray_copy(pixel, menu->buttons[1].sprite, menu->buttons[1].start);
  pixelarray_copy(pixel, menu->buttons[2].sprite, menu->buttons[2].start);
  pixelarray_copy(pixel, menu->buttons[3].sprite, menu->buttons[3].start);
  return (0);
}
