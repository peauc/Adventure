/*
** SCRIPT
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sat Apr 16 14:29:10 2016 Poc
*/

#include "scene.h"

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
  if (button == BMB_LEFT && clicked == GO_DOWN)
    {
      if ((determine_button_clicked(data->menu)))
	  return (EXIT_ON_ERROR);
      data->mv_s->click = 1;
      if (data->menu->buttons[2].is_clicked == 1 &&
	  (determine_item(data->tab[data->mv_s->s_nb])))
      	return (EXIT_ON_ERROR);
      data->mv_s->pos_click = bunny_get_mouse_position();
    }
  if (button == BMB_RIGHT && clicked == GO_DOWN)
    ;
  return (GO_ON);
}
