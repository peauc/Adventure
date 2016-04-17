/*
** do_some_shit.c for shit in /home/peau_c/rendu/Lib/gfx_tekadventure/movement
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr 16 15:35:51 2016 Poc
** Last update Sun Apr 17 17:21:04 2016 Mathieu Sauvau
*/

#include "tekadv.h"

t_flip		get_row_anim(t_bunny_position start, t_bunny_position end)
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
      flip.flip = 1;
      flip.row = (start.y < end.y ? 2 : 5);
    }
  else if (start.x > end.x)
    {
      flip.flip = 0;
      flip.row = (start.y < end.y ? 2 : 5);
    }
  return (flip);
}
