/*
** SCRIPT
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Wed Apr 13 12:53:09 2016 Poc
*/

#include "menu.h"

void			movement(t_bunny_keysym key, t_data *data)
{
  key = key;
  data = data;
}

void			set_all_to_zero(t_button *buttons)
{
  int			i;

  i = 0;
  while (i < 4)
    {
      buttons[i].is_clicked = 0;
      i++;
    }

}

t_bunny_response	clicky(t_bunny_event_state clicked,
			       t_bunny_mouse_button button,
			       t_data *data)
{
  data = data;
  if (button == BMB_LEFT && clicked == GO_DOWN)
    {
      if ((determine_button_clicked(data->menu)))
	return (EXIT_ON_ERROR);
      printf("clicky\n");
    }
  if (button == BMB_RIGHT && clicked == GO_DOWN)
    {
      printf("Deplacement\n");
    }
  return (GO_ON);
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
  if ((draw_menu(data->pixel, data->menu)))
    return (EXIT_ON_ERROR);
  bunny_blit(&data->window->buffer, &data->pixel->clipable, NULL);
  bunny_display(data->window);
  return (GO_ON);
}

int			main()
{
  t_data		data;

  data.window = bunny_start(WIDTH, HEIGHT, false, "test");
  data.pixel = bunny_new_pixelarray(WIDTH, HEIGHT);
  if ((data.menu = load_menu()) == NULL) /* || */
      /* (data.item = load_item()) == NULL) */
    return (1);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)&escape);
  bunny_set_click_response((t_bunny_click)&clicky);
  if (bunny_loop(data.window, 60, &data) == 0)
    return (0);
  return (1);
}
