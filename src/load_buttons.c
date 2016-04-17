/*
** load_buttons.c for load in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr 12 16:57:44 2016 Poc
** Last update Sun Apr 17 19:39:06 2016 marel_m
*/

#include "tekadv.h"

static int		load_first_button(t_button *button)
{
  t_bunny_pixelarray	*pix;

  if ((pix = bunny_load_pixelarray("sprites/look-at.png")) == NULL ||
      (button->active_sprite =
       bunny_load_pixelarray("sprites/active_look-at.png")) == NULL)
    return (1);
  if ((button->name = my_strdup("lookat")) == NULL)
    return (1);
  button->is_clicked = 0;
  button->sprite = pix;
  button->start.x = 50;
  button->start.y = 580;
  return (0);
}

static int	     	load_second_button(t_button *button)
{
  t_bunny_pixelarray	*pix;

  if ((pix = bunny_load_pixelarray("sprites/use.png")) == NULL ||
      (button->active_sprite =
       bunny_load_pixelarray("sprites/active_use.png")) == NULL)
    return (1);
  if ((button->name = my_strdup("use")) == NULL)
    return (1);
  button->is_clicked = 0;
  button->sprite = pix;
  button->start.x = 350;
  button->start.y = 680;
  return (0);
}

static int		load_third_button(t_button *button)
{
  t_bunny_pixelarray	*pix;

  if ((pix = bunny_load_pixelarray("sprites/pick-up.png")) == NULL ||
      (button->active_sprite =
       bunny_load_pixelarray("sprites/active_pick-up.png")) == NULL)
    return (1);
  if ((button->name = my_strdup("pickup")) == NULL)
    return (1);
  button->is_clicked = 0;
  button->sprite = pix;
  button->start.x = 350;
  button->start.y = 580;
  return (0);
}

static int		load_fourth_button(t_button *button)
{
  t_bunny_pixelarray	*pix;

  if ((pix = bunny_load_pixelarray("sprites/give.png")) == NULL ||
      (button->active_sprite =
       bunny_load_pixelarray("sprites/active_give.png")) == NULL)
    return (1);
  if ((button->name = my_strdup("give")) == NULL)
    return (1);
  button->is_clicked = 0;
  button->sprite = pix;
  button->start.x = 50;
  button->start.y = 680;
  return (0);
}

int	load_buttons(t_menu *menu)
{
  if ((load_first_button(&menu->buttons[0])) ||
      (load_second_button(&menu->buttons[1])) ||
      (load_third_button(&menu->buttons[2])) ||
      (load_fourth_button(&menu->buttons[3])))
    return (1);
  return (0);
}
