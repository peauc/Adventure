/*
** menu_load.c for load menu in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 11 18:14:27 2016 Poc
** Last update Mon Apr 11 18:41:54 2016 Poc
*/

#include <stdlib.h>
#include "default.h"

int	load_menu(t_menu **menu)
{
  if ((*menu = malloc(sizeof(t_menu))) == NULL)
    return (1);
  if (((*menu)->buttons = malloc(sizeof(t_button) * 5)) == NULL)
    return (1);
}
