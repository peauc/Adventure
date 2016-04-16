/*
** init_tab.c for init in /home/peau_c/rendu/Lib/gfx_tekadventure/GIMP
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Apr 15 20:31:58 2016 Poc
** Last update Sat Apr 16 13:47:45 2016 Poc
*/

#include "default.h"

int	load_scene_tab(t_scene tab[14])
{
  init_scene(tab);
  if (load_item_basement(&tab[7]))
    return (1);
  return (0);
}

int	init_scene(t_scene tab[14])
{
  int	i;

  i = 0;
  while (i < 14)
    {
      tab[i].item = NULL;
      i++;
    }
  return (0);
}
