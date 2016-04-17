/*
** gfx_tekadventure
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sun Apr 17 19:52:33 2016 marel_m
*/

#include "tekadv.h"

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

t_bunny_response	clicky(t_bunny_event_state state,
			       t_bunny_mouse_button button,
			       t_data *data)
{
  const t_bunny_position        *pos;
  t_dict                        *came_from;
  t_points                      *dest;
  t_points                      *path;
  bool                          clicked;

  if (button == BMB_LEFT && state == GO_DOWN)
    {
      if ((determine_button_clicked(data->menu)))
	  return (EXIT_ON_ERROR);
      data->mv_s->click = 1;
      if (data->menu->buttons[2].is_clicked == 1 &&
	  (determine_item(data->tab[data->mv_s->s_nb])))
      	return (EXIT_ON_ERROR);
      data->mv_s->pos_click = bunny_get_mouse_position();
    }
  clicked = false;
  pos = bunny_get_mouse_position();
  path = NULL;
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
	      clear_node(path);
	    }
	}
    }
  return (GO_ON);
}
