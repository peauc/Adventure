/*
** item_load.c for itemlod in /home/peau_c/rendu/Lib/gfx_tekadventure/GIMP
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr 14 21:52:45 2016 Poc
** Last update Fri Apr 15 13:19:37 2016 Poc
*/

#include <stdio.h>
#include <stdlib.h>
#include "default.h"

int	load_item_basement(t_item *item)
{
  if ((item->sprite = bunny_load_pixelarray("./pictures/key_poc.png")) == NULL)
    return (1);
  item->pos.x = 0;
  item->pos.y = 0;
  return (0);
}
