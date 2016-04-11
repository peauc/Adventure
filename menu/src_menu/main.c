/*
** SCRIPT
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Mon Apr 11 17:37:14 2016 Poc
*/

#include "default.h"

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
  /* my_fill(data->pixel); */
  draw_menu(data->pixel);
  bunny_blit(&data->window->buffer, &data->pixel->clipable, NULL);
  bunny_display(data->window);
  return (GO_ON);
}

int			main()
{
  t_data		data;

  data.window = bunny_start(WIDTH, HEIGHT, false, "test");
  data.pixel = bunny_new_pixelarray(WIDTH, HEIGHT);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)&escape);
  if (bunny_loop(data.window, 60, &data) == 0)
    return (0);
  return (1);
}
