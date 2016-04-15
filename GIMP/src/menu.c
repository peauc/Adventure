/*
** SCRIPT
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Fri Apr 15 21:01:15 2016 Poc
*/

#include "default.h"

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
	{
	  printf("Broke clicky\n");
	  return (EXIT_ON_ERROR);
	}
      data->mv_s->click = 1;
      /* if ((determine_item(data->tab[data->mv_s->s_nb]))) */
      /* 	return (EXIT_ON_ERROR); */
      data->mv_s->pos_click = bunny_get_mouse_position();
      printf("clicky\n");
    }
  if (button == BMB_RIGHT && clicked == GO_DOWN)
    {
      printf("Deplacement\n");
    }
  return (GO_ON);
}
