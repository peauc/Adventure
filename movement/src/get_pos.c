/*
** get_pos.c for getpos in /home/peau_c/rendu/Lib/gfx_tekadventure/GIMP
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr 16 11:59:06 2016 Poc
** Last update Sat Apr 16 14:21:56 2016 marel_m
*/

#include "scene.h"

t_bunny_position	get_pos(int x, int y)
{
  t_bunny_position	pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}
