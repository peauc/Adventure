/*
** do_some_shit.c for shit in /home/peau_c/rendu/Lib/gfx_tekadventure/movement
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr 16 15:35:51 2016 Poc
** Last update Sat Apr 16 17:50:16 2016 Poc
*/

#include "tekadv.h"

t_flip		do_some_shit(t_bunny_position start, t_bunny_position end)
{
  t_flip	flip;

  if (start.y < end.y + 50 && start.y > end.y - 50)
    {
      flip.flip = (start.x < end.x ? 1 : 0);
      flip.row = 3;
    }
  else if (start.x < end.x + 50 && start.x > end.x - 50)
    {
      flip.row = (start.y < end.y ? 1 : 4);
      flip.flip = 0;
    }
  else if (start.x < end.x)
    {
      flip.flip = (start.y < end.y ? 1 : 0);
      flip.row = 2;
    }
  else if (start.x > end.x)
    {
      flip.flip = (start.y > end.y ? 0 : 1);
      flip.row = 5;
    }
  return (flip);
}
