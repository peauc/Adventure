/*
** SCRIPT
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Mon Apr 11 20:35:51 2016 Mathieu Sauvau
*/

#include "default.h"

t_bunny_position	pos_(int x, int y)
{
  t_bunny_position	pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}

void			anim_sprite_sheet(t_bunny_pixelarray *out, t_sprite_sheet *sp,
					  int line)
{
  t_color		*out_col;
  t_color		*sp_col;
  t_bunny_position	limit;
  t_bunny_position	p;
  int			new_pos;

  out_col = (t_color *)out->pixels;
  sp_col = (t_color *)sp->pix->pixels;
  if (sp->pos.x >= sp->pix->clipable.clip_width)
    sp->pos.x = 0;
  p.x = -1;
  sp->pos.y = line * sp->size.y - 1;
  limit = pos_(sp->pos.x + sp->size.x, sp->pos.y + + sp->size.y);
  while (++sp->pos.x <= limit.x)
    {
      p.y = -1;
      ++p.x;
      while (++sp->pos.y <= limit.y)
	{
	  ++p.y;
	  new_pos = sp->pix->clipable.clip_width * sp->pos.y + sp->pos.x;
	  out_col[p.y * sp->size.x + p.x]
	    = sp_col[new_pos];
	}
    }
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
  anim_sprite_sheet(data->pixel, data->player->sp, 1);
  bunny_blit(&data->win->buffer, &data->pixel->clipable, NULL);
  //  bunny_blit(&data->win->buffer, &data->player->sp->pix->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}

t_sprite_sheet		*load_sprite_sheet(char *sprite_sheet,
					  t_bunny_position size)
{
  t_sprite_sheet	*sp;

  if ((sp = bunny_malloc(sizeof(t_sprite_sheet *))) == NULL
      || (sp->pix = bunny_load_pixelarray(sprite_sheet)) == NULL)
    return (NULL);
  sp->pos = pos_(-1, 0);
  sp->size = size;
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
					      pos_(125, 290))) == NULL
      || bunny_loop(data.win, 60, &data) == 0)
    return (0);
  return (1);
}
