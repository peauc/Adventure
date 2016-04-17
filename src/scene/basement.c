/*
** basement.c for basement in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:28:42 2016 marel_m
** Last update Sun Apr 17 21:15:08 2016 Poc
*/

#include "tekadv.h"

int			change_scene_seven_six(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 300;
  pos.y = 100;
  if (data->mv_s->mouse.x >= 300
      && data->mv_s->mouse.x <= 400
      && data->mv_s->mouse.y <= 200 && data->mv_s->mouse.y >= 100)
    {
      put_pix_in_pix(data->pixel, data->tab[11].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 6;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	  if ((data->p = change_road(6, data->p)) == NULL
	      || (data->node = change_list(data->p)) == NULL)
	    return (1);
	  pos_player(data->player, data->node);
	}
    }
  return (0);
}

int			basement(t_data *data)
{
  t_bunny_position	pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix(data->pixel, data->tab[7].front, pos, 0);
  if ((change_scene_seven_six(data)))
    return (1);
  put_pix_in_pix(data->pixel, data->new, pos, 0);
  draw_items(data->tab[7].item, data->pixel);
  return (0);
}
