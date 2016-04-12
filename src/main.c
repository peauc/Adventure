/*
** SCRIPT
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Tue Apr 12 11:37:49 2016 Mathieu Sauvau
*/

#include "default.h"

void                    my_fill(t_bunny_pixelarray *pix_ar, unsigned int color)
{
  int                   x;
  int                   y;
  t_color               *col;
  int                   new_pos;

  x = 0;
  y = 0;
  col = pix_ar->pixels;
  while (x < pix_ar->clipable.clip_width)
    {
      while (y < pix_ar->clipable.clip_height)
        {
          new_pos = pix_ar->clipable.clip_width * y  + x;
          col[new_pos].full = color;
          y++;
        }
      x++;
      y = 0;
    }
}

t_bunny_position	pos_(int x, int y)
{
  t_bunny_position	pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}

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

void			movement(t_bunny_keysym key, t_data *data)
{
  key = key;
  data = data;
}

t_bunny_response	escape(t_bunny_event_state state,
			       t_bunny_keysym key,
			       t_data *data)
{
  data = data;
  state = state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response       	mainloop(t_data *data)

{
  my_fill(data->pixel, PINK);
  anim_sprite(data->pixel, data->player->sp, 1, 12);
  bunny_blit(&data->win->buffer, &data->pixel->clipable, NULL);
  //    bunny_blit(&data->win->buffer, &data->player->sp->pix->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}

t_sprite_sheet		*load_sprite_sheet(char *sprite_sheet,
					   t_bunny_position size,
					   int	anim_speed)
{
  t_sprite_sheet	*sp;

  if ((sp = bunny_malloc(sizeof(t_sprite_sheet *))) == NULL
      || (sp->pix = bunny_load_pixelarray(sprite_sheet)) == NULL)
    return (NULL);
  sp->pos = pos_(-1, 0);
  sp->size = size;
  sp->anim_speed = anim_speed;
  return (sp);
}

int			main(int ac, char **av)
{
  t_data		data;

  ac = ac;
  av = av;
  data.win = bunny_start(1000, 1000, false, "test");
  data.pixel = bunny_new_pixelarray(1000, 1000);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)&escape);
  if ((data.player = bunny_malloc(sizeof(t_player))) == NULL
      || (data.player->sp = load_sprite_sheet("gimp/sprite_monkey_island.png",
					      pos_(125, 290), 40)) == NULL
      || bunny_loop(data.win, 60, &data) == 0)
    return (0);
  return (1);
}
