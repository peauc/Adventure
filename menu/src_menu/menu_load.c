/*
** menu_load.c for load menu in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 11 18:14:27 2016 Poc
** Last update Mon Apr 11 21:09:14 2016 Poc
*/

#include <stdlib.h>
#include "menu.h"

static int		load_first_button(t_button *button)
{
  t_bunny_pixelarray	*pix;

  if ((pix = bunny_load_pixelarray("sprites/look-at.png")) == NULL)
    return (1);
    button->is_clicked = 0;
  button->sprite = pix;
  button->start.x = 50;
  button->start.y = 575;
  return (0);
}

static int		load_fourth_button(t_button *button)
{
  t_bunny_pixelarray	*pix;

  if ((pix = bunny_load_pixelarray("sprites/give.png")) == NULL)
    return (1);
  button->is_clicked = 0;
  button->sprite = pix;
  button->start.x = 50;
  button->start.y = 650;
  return (0);
}

static int		load_third_button(t_button *button)
{
  t_bunny_pixelarray	*pix;

  if ((pix = bunny_load_pixelarray("sprites/pick-up.png")) == NULL)
    return (1);
    button->is_clicked = 0;
  button->sprite = pix;
  button->start.x = 350;
  button->start.y = 575;
  return (0);
}

static int	     	load_second_button(t_button *button)
{
  t_bunny_pixelarray	*pix;

  if ((pix = bunny_load_pixelarray("sprites/use.png")) == NULL)
    return (1);
  button->is_clicked = 0;
  button->sprite = pix;
  button->start.x = 350;
  button->start.y = 650;
  return (0);
}

int			load_menu()
{
  t_menu		*menu;

  if ((menu = bunny_malloc(sizeof(t_menu))) == NULL)
    return (NULL);
  if (((menu)->buttons = bunny_malloc(sizeof(t_button) * 5)) == NULL)
    return (NULL);
  if ((load_first_button(&menu->buttons[0])) ||
      (load_second_button(&menu->buttons[1])) ||
      (load_third_button(&menu->buttons[2])) ||
      (load_fourth_button(&menu->buttons[3])))
    return (NULL);
  return (menu);
}
