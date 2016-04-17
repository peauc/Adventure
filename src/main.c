/*
** gfx_tekadventure
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sun Apr 17 20:40:21 2016 marel_m
*/

#include "tekadv.h"

t_bunny_response	escape(t_bunny_event_state state,
			       t_bunny_keysym key,
			       t_data *data)
{
  if (key == BKS_ESCAPE && state == GO_DOWN && data)
      return (EXIT_ON_SUCCESS);
  if (key == BKS_LEFT && state == GO_DOWN)
    {
      data->mv_s->mv_bck -= 3;
    }
  if (key == BKS_RIGHT && state == GO_DOWN)
    {
      data->mv_s->mv_bck += 3;
    }
  if (key == BKS_LCONTROL && state == GO_DOWN)
    {
      aff_road(data->mv_s->s_nb, data->p, data->new, 0);
    }
  return (GO_ON);
}

t_bunny_response       	mainloop(t_data *data)
{
  const t_bunny_position        *pos;
  t_flip                        flip;

  pos = bunny_get_mouse_position();
  my_fill(data->pixel, PINK);
  my_fill(data->player->pix, PINK);
  flip.flip = 0;
  flip.row = 0;
  anim_sprite(data->player->pix, data->player->sp, flip, 1);
  data->mv_s->mouse = data->player->pos;
  mv_camera_mouse(data);
  data->mv_s->old_mouse = data->mv_s->mouse.x;
  draw_scene(data);
  draw_menu(data->pixel, data->menu);
  draw_inventory(data->pixel, data->tab);
  data->mv_s->click = 0;
  bunny_blit(&data->win->buffer, &data->pixel->clipable, NULL);
  bunny_blit(&data->win->buffer,
	     &data->player->pix->clipable, &data->player->pos);
  bunny_display(data->win);
  return (GO_ON);
}

t_sprite_sheet          *load_sprite_sheet(char *sprite_sheet,
					   t_bunny_position size,
					   int  anim_speed)
{
  t_sprite_sheet        *sp;

  if ((sp = bunny_malloc(sizeof(t_sprite_sheet *))) == NULL
      || (sp->pix = bunny_load_pixelarray(sprite_sheet)) == NULL)
    return (NULL);
  sp->pos = pos_(-1, 0);
  sp->size = size;
  sp->anim_speed = anim_speed;
  return (sp);
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
  if ((load_music()))
    return (1);
  if ((data.player = bunny_malloc(sizeof(t_player))) == NULL
      || (data.player->sp = load_sprite_sheet("sprites/sprite_monkey_island.png",
					      pos_(125, 290), 10)) == NULL
      || (data.player->pix = bunny_new_pixelarray(data.player->sp->size.x,
						  data.player->sp->size.y)) == NULL)
    return (0);
  data.p = create_list();
  if ((full_ini(data.p, "pictures/harbor_back.png")) == -1)
    return (0);
  data.node = change_list(data.p);
  pos_player(data.player, data.node);
  data.mv_s->s_nb = 0;
  data.mv_s->mv_bck = 0;
  data.mv_s->mv_fr = 0;
  data.mv_s->click = 0;
  if ((data.p = change_road(0, data.p)) == NULL
      || (data.node = change_list(data.p)) == NULL)
    return (1);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)&escape);
  bunny_set_click_response((t_bunny_click)&clicky);
  if (bunny_loop(data.win, 60, &data) == 0)
    return (0);
  load_music();
  free_data(&data);
  bunny_delete_clipable(&data.pixel->clipable);
  bunny_delete_clipable(&data.new->clipable);
  bunny_stop(data.win);
  return (1);
}
