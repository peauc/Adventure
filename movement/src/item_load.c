/*
** item_load.c for itemlod in /home/peau_c/rendu/Lib/gfx_tekadventure/GIMP
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr 14 21:52:45 2016 Poc
** Last update Sat Apr 16 14:21:07 2016 marel_m
*/

#include <stdio.h>
#include <stdlib.h>
#include "scene.h"

int	load_item_basement(t_data *data)
{
  if ((data->tab[7].item.sprite = malloc(sizeof(t_item) * 2)) == NULL)
    return (1);
  if ((data->tab[7].item.selected = malloc(sizeof(int))) == NULL)
    return (1);
  data->tab[7].item.sprite[1] = NULL;
  if ((data->tab[7].item.sprite[0] =
       bunny_load_pixelarray("./pictures/key_poc.png")) == NULL)
    return (1);
  if ((data->tab[7].item.pos = malloc(sizeof(t_bunny_position) * 1)) == NULL)
    return (1);
  data->tab[7].item.selected[0] = 0;
  data->tab[7].item.pos[0].x = 560;
  data->tab[7].item.pos[0].y = 410;
  data->tab[7].item.map = 7;
  return (0);
}
