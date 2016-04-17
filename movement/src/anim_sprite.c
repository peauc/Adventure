/*
** anim_sprite.c for  in /home/sauvau_m/rendu/gfx_tekadventure
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue Apr 12 15:30:07 2016 Mathieu Sauvau
** Last update Sun Apr 17 13:12:01 2016 Mathieu Sauvau
*/

#include "tekadv.h"

void			cpy_color(t_bunny_pixelarray *out, t_bunny_pixelarray *src,
				  t_bunny_position o_pos,
				  t_bunny_position pos)
{
  int			new_pos;
  int			o_new_pos;
  t_color		*color;
  t_color		*o_color;

  color = (t_color*)src->pixels;
  o_color = (t_color*)out->pixels;
  new_pos = pos.y * src->clipable.clip_width + pos.x;
  o_new_pos = o_pos.y * out->clipable.clip_width + o_pos.x;
  if (color[new_pos].argb[ALPHA_CMP] != 0)
    o_color[o_new_pos].full = color[new_pos].full;
}

void			cpy_sprite(t_bunny_pixelarray *out, t_sprite_sheet *sp,
				   int col, int row)
{
  t_bunny_position	o_pos;
  t_bunny_position	pos;
  t_bunny_position	limit;

  pos = pos_(col * sp->size.x, row * sp->size.y);
  limit = pos_(pos.x + sp->size.x, pos.y + sp->size.y);
  o_pos.y = 0;
  while (pos.y < limit.y)
    {
      o_pos.x = 0;
      while (pos.x < limit.x)
	{
	  cpy_color(out, sp->pix, o_pos, pos);
	  pos.x += 1;
	  o_pos.x++;
	}
      pos.x = col * sp->size.x;
      pos.y += 1;
      o_pos.y++;
    }
}

void			anim_sprite(t_bunny_pixelarray *out, t_sprite_sheet *sp,
				    int start_row, int limit_col)
{
  if (++sp->speed_cursor > sp->anim_speed)
    {
      if (++sp->col >= limit_col)
	sp->col = 0;
      sp->speed_cursor = 0;
    }
  cpy_sprite(out, sp, sp->col, start_row);
}
