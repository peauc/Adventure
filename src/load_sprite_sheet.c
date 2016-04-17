/*
** load_sprite_sheet.c for  in /home/peau_c/rendu/Lib/gfx_tekadventure
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sun Apr 17 23:28:13 2016 Poc
** Last update Sun Apr 17 23:39:47 2016 Poc
*/

#include "tekadv.h"

t_sprite_sheet	*load_sprite_sheet(char *sprite_sheet, t_bunny_position size,
				   int  anim_speed)
{
  t_sprite_sheet                *sp;

  if ((sp = bunny_malloc(sizeof(t_sprite_sheet *))) == NULL
      || (sp->pix = bunny_load_pixelarray(sprite_sheet)) == NULL)
    return (NULL);
  sp->pos = pos_(-1, 0);
  sp->size = size;
  sp->anim_speed = anim_speed;
  return (sp);
}
