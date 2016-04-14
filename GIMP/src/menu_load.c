/*
** menu_load.c for load menu in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 11 18:14:27 2016 Poc
** Last update Thu Apr 14 22:06:40 2016 Poc
*/

#include <stdlib.h>
#include "default.h"

t_menu			*load_menu(char *str)
{
  t_menu		*menu;
  t_bunny_ini		*items;

  if (!str || (items = bunny_load_ini(str)) == NULL)
    return (write(2, "Usage : ./adv item.ini\n", 23), NULL);
  if ((menu = bunny_malloc(sizeof(t_menu))) == NULL)
    return (NULL);
  if ((load_item(menu, items)))
    {
      printf("items broke\n");
      return (NULL);
    }
  if (!(menu->buttons = bunny_malloc(sizeof(t_button) * 5)) ||
      (load_buttons(menu)))
    return (NULL);
  return (menu);
}
