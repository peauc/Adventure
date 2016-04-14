/*
** item_load.c for itemlod in /home/peau_c/rendu/Lib/gfx_tekadventure/GIMP
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr 14 21:52:45 2016 Poc
** Last update Thu Apr 14 22:11:17 2016 Poc
*/

#include <stdio.h>
#include <stdlib.h>
#include "default.h"

int	load_item(t_menu *menu, t_bunny_ini *items)
{
  int	i;

  i = 0;
  while (bunny_ini_get_field(items, "item", "item", i) != NULL)
    i++;
  if ((menu->item = malloc(sizeof(t_item) * (i + 1))) == NULL)
    {
      printf("Malloc broke\n");
      return (1);
    }
  menu->item[i] = NULL;
  printf("went correctly\n");
  return (0);
}
