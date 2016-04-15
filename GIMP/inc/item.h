/*
** item.h for item in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Wed Apr 13 12:40:53 2016 Poc
** Last update Fri Apr 15 12:39:51 2016 Poc
*/

#ifndef _ITEM_
# define _ITEM_

#include "lapin.h"

typedef struct	s_item
{
  t_bunny_pixelarray	*sprite;
  t_bunny_position	pos;
  int			map;
}		t_item;

#endif /* !_ITEM_ */
