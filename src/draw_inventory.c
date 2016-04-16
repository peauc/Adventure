/*
** draw_inventory.c for inventory in /home/peau_c/rendu/Lib/gfx_tekadventure/GIMP
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Apr 15 20:05:21 2016 Poc
** Last update Sat Apr 16 14:21:43 2016 marel_m
*/

#include "scene.h"

int	draw_inventory(t_bunny_pixelarray *pix, t_scene tab[14])
{
  if (tab[7].item[0].selected[0] == 1)
    pixelarray_copy(pix, tab[7].item[0].sprite[0], get_pos(600, 650));
  return (0);
}
