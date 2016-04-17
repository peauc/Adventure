/*
** gfx_tekadventure
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sun Apr 17 16:20:31 2016 marel_m
*/

#include "scene.h"

t_bunny_response	escape(t_bunny_event_state state,
			       t_bunny_keysym key,
			       t_data *data)
{
  if (key == BKS_ESCAPE && state == GO_DOWN)
      return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response       	mainloop(t_data *data)
{
  data->mv_s->mouse = bunny_get_mouse_position();
  mv_camera_mouse(data);
  data->mv_s->old_mouse = data->mv_s->mouse->x;
  draw_scene(data);
  draw_menu(data->pixel, data->menu);
  draw_inventory(data->pixel, data->tab);
  data->mv_s->click = 0;
  bunny_blit(&data->win->buffer, &data->pixel->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}

int			main()
{
  t_data		data;

  bunny_set_maximum_ram(10000000000);
  if (load_all_scene(&data) == -1)
      return (1);
  data.win = bunny_start(WIDTH, HEIGHT, false, "test");
  if ((data.pixel = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if ((data.new = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
      return (1);
  if ((data.menu = load_menu()) == NULL)
      return (1);
  if ((data.mv_s = malloc(sizeof(t_mv_scene))) == NULL)
      return (1);
  if ((load_scene_tab(data.tab)))
      return (1);
  data.mv_s->s_nb = 0;
  data.mv_s->mv_bck = 0;
  data.mv_s->mv_fr = 0;
  data.mv_s->click = 0;
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)&escape);
  bunny_set_click_response((t_bunny_click)&clicky);
  if (bunny_loop(data.win, 60, &data) == 0)
    return (0);
  free_data(&data);
  bunny_delete_clipable(&data.pixel->clipable);
  bunny_delete_clipable(&data.new->clipable);
  bunny_stop(data.win);
  return (1);
}
