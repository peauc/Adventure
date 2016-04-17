/*
** boat.c for boat in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:22:50 2016 marel_m
** Last update Sun Apr 17 21:14:53 2016 Poc
*/

#include "tekadv.h"

int                    change_scene_one_zero(t_data *data)
{
  t_bunny_position      pos;

  pos.x = 185;
  pos.y = 375;
  if (data->mv_s->mouse.x >= 185
      && data->mv_s->mouse.x <= 285
      && data->mv_s->mouse.y <= 475 && data->mv_s->mouse.y >= 375)
    {
      put_pix_in_pix(data->pixel, data->tab[11].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 0;
	  data->mv_s->mv_fr = WIDTH / 2;
	  data->mv_s->mv_bck = WIDTH / 2;
	  data->mv_s->click = 0;
	  if ((data->p = change_road(0, data->p)) == NULL
	      || (data->node = change_list(data->p)) == NULL)
	    return (1);
	  pos_player(data->player, data->node);
	}
    }
  return (0);
}

int	boat(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix(data->pixel, data->tab[1].back, pos, 0);
  if (change_scene_one_zero(data))
    return (1);
  put_pix_in_pix(data->pixel, data->tab[1].front, pos, 0);
  put_pix_in_pix(data->pixel, data->new, pos, 0);
  return (0);
}
