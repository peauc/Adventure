/*
** menu_load.c for load menu in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 11 18:14:27 2016 Poc
** Last update Sun Apr 17 17:39:11 2016 Poc
** Last update Sat Apr 16 14:18:53 2016 marel_m
*/

#include <stdlib.h>
#include "scene.h"

t_menu			*load_menu()
{
  t_menu		*menu;

  if ((menu = bunny_malloc(sizeof(t_menu))) == NULL)
    return (NULL);
  if (!(menu->buttons = bunny_malloc(sizeof(t_button) * 5)) ||
      (load_buttons(menu)))
    return (NULL);
  return (menu);
}
