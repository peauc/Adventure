/*
** SCRIPT
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Tue Apr 12 18:26:51 2016 marel_m
*/

#include "default.h"

void            tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color,
			 int state)
{
  t_color       *pixel;
  int           i;

  if (pos->x >= 0 && pos->x < pix->clipable.clip_width &&
            pos->y >= 0 && pos->y < pix->clipable.clip_height)
    {
      i = pos->x + (pix->clipable.clip_width * pos->y);
      pixel = (t_color*)pix->pixels + i;
      if (color->argb[3] > 0 && (color->full != 0xFFFFFFFF
				 || state != 1))
	pixel->full = color->full;
    }
}
void                    put_pix_in_pix_txt(t_bunny_pixelarray *pix,
					   t_bunny_pixelarray *src,
					   t_bunny_position pos)
{
  t_bunny_position      posi;
  t_color               *color;
  int                   i;

  posi.y = 0;
  while (pos.y < HEIGHT && posi.y < src->clipable.clip_height)
    {
      pos.x = 0;
      posi.x = 0;
      while (pos.x < WIDTH)
	{
	  i = posi.x + (posi.y * src->clipable.clip_width);
	  color = (t_color*)src->pixels + i;
	  if (color->argb[3] != 0)
	    tekpixel(pix, &pos, color, 0);
	  pos.x++;
	  posi.x++;
	}
      pos.y++;
      posi.y++;
    }
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

void            pix_initialize(t_bunny_pixelarray *pix)
{
  t_color       *color;
  int           n;
  int           i;

  n = 0;
  i = pix->clipable.clip_width * pix->clipable.clip_height;
  while (n < i)
    {
      color = (t_color*)pix->pixels + n;
      color->full = 0x00000000;
      n += 1;
    }
}

t_bunny_response       	mainloop(t_data *data)
{
  street(data);
  bunny_blit(&data->win->buffer, &data->pixel->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}

int			main(int ac, char **av)
{
  t_data		data;

  ac = ac;
  av = av;
  bunny_set_maximum_ram(1000000000);
  data.win = bunny_start(WIDTH, HEIGHT, false, "test");
  if ((data.pixel = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if (load_all_scene(&data) == -1)
    return (-1);
  if ((data.new = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)&escape);
  if (bunny_loop(data.win, 60, &data) == 0)
    return (0);
  return (1);
}
