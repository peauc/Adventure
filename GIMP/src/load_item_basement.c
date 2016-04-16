/*
** item_load.c for itemlod in /home/peau_c/rendu/Lib/gfx_tekadventure/GIMP
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr 14 21:52:45 2016 Poc
** Last update Sat Apr 16 11:15:17 2016 Poc
*/

#include <stdio.h>
#include <stdlib.h>
#include "default.h"

int	load_item_basement(t_scene *scene)
{
  if ((scene->item = bunny_malloc(sizeof(t_item))) == NULL ||
      (scene->item->sprite =
       bunny_malloc(sizeof(t_bunny_pixelarray) * 2)) == NULL)
    return (1);
  if ((scene->item->selected = bunny_malloc(sizeof(int))) == NULL)
    return (1);
  scene->item->sprite[1] = NULL;
  if ((scene->item->sprite[0] =
       bunny_load_pixelarray("./pictures/key_poc.png")) == NULL)
    return (1);
  if ((scene->item->pos =
       bunny_malloc(sizeof(t_bunny_position) * 1)) == NULL)
    return (1);
  scene->item->selected[0] = 0;
  scene->item->pos[0].x = 560;
  scene->item->pos[0].y = 410;
  scene->item->map = 7;
  return (0);
}
