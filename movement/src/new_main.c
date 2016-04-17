/*
** SCRIPT
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sun Apr 17 15:39:31 2016 Mathieu Sauvau
*/

#include <math.h>
#include "tekadv.h"

void			movement(t_bunny_keysym key, t_data *data)
{
  key = key;
  data = data;
}

t_bunny_position	pos_player(t_player *player, t_points *node)
{
  if (!node)
    return (pos_(0, 0));
  player->node = node;
  return (player->pos = pos_(node->el.center.x - player->sp->size.x / 2,
			     node->el.center.y - player->sp->size.y));
}

void				show_player(t_data *data, int row)
{
  anim_sprite(data->player->pix, data->player->sp, row, 12);
  bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
  bunny_blit(&data->win->buffer, &data->player->pix->clipable, &data->player->pos);
  bunny_display(data->win);
}



t_bunny_response		click(t_bunny_event_state state,
				      t_bunny_mousebutton button,
				      t_data *data)
{
  const t_bunny_position	*pos;
  t_dict			*came_from;
  t_points			*dest;
  t_points			*path;
  bool				clicked;

  pos = bunny_get_mouse_position();
  if (button == BMB_RIGHT && state == GO_DOWN)
    {
      if (!clicked)
	{
	  clicked = true;
	  dest = get_node_byclick(data->node, pos);
	  came_from = find_way(data->node, data->player->node, dest);
	  if (came_from)
	    {
	      path = construct_path(came_from, data->player->node, dest);
	      move(data, path, data->player);
	      clear_dict(came_from);
	      //	      clear_
	    }
	}
    }
  clicked = false;
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
  const t_bunny_position	*pos;

  pos = bunny_get_mouse_position();
  my_fill(data->pix, PINK);
  my_fill(data->player->pix, PINK);
  anim_sprite(data->player->pix, data->player->sp, 1, 12);
  //  aff_all2(data->pix, data->p, pos, "pictures/screen1.jpg");
  bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
  bunny_blit(&data->win->buffer, &data->player->pix->clipable, &data->player->pos);
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
  if ((data.player = bunny_malloc(sizeof(t_player))) == NULL
      || (data.player->sp = load_sprite_sheet("gimp/sprite_monkey_island.png",
					      pos_(125, 290), 10)) == NULL
      || (data.player->pix = bunny_new_pixelarray(data.player->sp->size.x,
						  data.player->sp->size.y)) == NULL
      || (data.win = bunny_start(WIDTH, HEIGHT, false, "test")) == NULL
      || (data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)

    return (0);
  data.p = create_list();
  full_ini(data.p);
  data.node = change_list(data.p);
  pos_player(data.player, data.node);
  bunny_set_click_response(&click);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)&escape);
  bunny_loop(data.win, 60, &data);
  return (1);
}
