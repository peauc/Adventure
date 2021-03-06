/*
** beach.c for beach in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:30:02 2016 marel_m
** Last update Sun Apr 17 21:18:19 2016 marel_m
*/

#include "tekadv.h"

int			change_scene_four_two(t_data *data)
{
  t_bunny_position	pos;

  pos.x = WIDTH - 100;
  pos.y = 300;
  if (data->mv_s->mouse->x + data->mv_s->mv_bck >= 1948
      && data->mv_s->mouse->x + data->mv_s->mv_bck <= 2048
      && data->mv_s->mouse->y <= 400 && data->mv_s->mouse->y >= 300)
    {
      put_pix_in_pix(data->pixel, data->tab[13].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 2;
	  data->mv_s->mv_fr = WIDTH - 300;
	  data->mv_s->mv_bck = WIDTH - 300;
	  data->mv_s->click = 0;
	  if ((data->p = change_road(2, data->p)) == NULL
	      || (data->node = change_list(data->p)) == NULL)
	    return (1);
	  pos_player(data->player, data->node);
	}
    }
  return (0);
}

int			change_scene_four_five(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 300;
  if (data->mv_s->mouse->x + data->mv_s->mv_bck >= 0
      && data->mv_s->mouse->x + data->mv_s->mv_bck <= 100
      && data->mv_s->mouse->y <= 400 && data->mv_s->mouse->y >= 300)
    {
      put_pix_in_pix(data->pixel, data->tab[12].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 5;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	  if ((data->p = change_road(5, data->p)) == NULL
	      || (data->node = change_list(data->p)) == NULL)
	    return (1);
	  pos_player(data->player, data->node);
	}
    }
  return (0);
}

int			beach(t_data *data)
{
  t_bunny_position	pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix(data->pixel, data->tab[4].back, pos, data->mv_s->mv_bck);
  put_pix_in_pix(data->pixel, data->tab[4].front, pos, data->mv_s->mv_fr);
  if ((change_scene_four_two(data)) ||
      (change_scene_four_five(data)))
    return (1);
  put_pix_in_pix(data->pixel, data->new, pos, 0);
  return (0);
}
