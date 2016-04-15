/*
** SCRIPT
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Fri Apr 15 15:17:28 2016 marel_m
*/

#include "default.h"

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
  draw_scene(data);
  draw_menu(data->pixel, data->menu);
  bunny_blit(&data->win->buffer, &data->pixel->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}

int			main(int ac, char **av)
{
  t_data		data;

  ac = ac;
  av = av;
  bunny_set_maximum_ram(10000000000);
  data.win = bunny_start(WIDTH, HEIGHT, false, "test");
  if ((data.pixel = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if (load_all_scene(&data) == -1)
    return (1);
  if ((data.new = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  data.menu = load_menu();
  if ((data.mv_s = malloc(sizeof(t_mv_scene))) == NULL)
    return (1);
  data.mv_s->s_nb = 0;
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)&escape);
  bunny_set_click_response((t_bunny_click)&clicky);
  if (bunny_loop(data.win, 60, &data) == 0)
    return (0);
  return (1);
}
