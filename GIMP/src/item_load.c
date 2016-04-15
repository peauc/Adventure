/*
** item_load.c for itemlod in /home/peau_c/rendu/Lib/gfx_tekadventure/GIMP
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr 14 21:52:45 2016 Poc
** Last update Fri Apr 15 14:52:35 2016 Poc
*/

#include <stdio.h>
#include <stdlib.h>
#include "default.h"

int	load_item_basement(t_item *item)
{
  if ((item->sprite = malloc(sizeof(t_item) * 2)) == NULL)
    return (1);
  if ((item->selected = malloc(sizeof(int))) == NULL)
    return (1);
  item->sprite[1] = NULL;
  if ((item->sprite[0] =
       bunny_load_pixelarray("./pictures/key_poc.png")) == NULL)
    return (1);
  if ((item->pos = malloc(sizeof(t_bunny_position) * 1)) == NULL)
    return (1);
  item->selected[0] = 0;
  item->pos[0].x = 560;
  item->pos[0].y = 410;
  item->map = 7;
  return (0);
}
