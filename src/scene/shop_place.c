/*
** shop.c for shop in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:37:21 2016 marel_m
** Last update Sun Apr 17 22:06:21 2016 Poc
*/

#include "tekadv.h"

int			change_scene_two_zero(t_data *data)
{
  t_bunny_position	pos;

  pos.x = WIDTH - 100;
  pos.y = 400;
  if (data->mv_s->mouse->x + data->mv_s->mv_bck >= 1948
      && data->mv_s->mouse->x + data->mv_s->mv_bck <= 2048
      && data->mv_s->mouse->y <= 500 && data->mv_s->mouse->y >= 400)
    {
      put_pix_in_pix(data->pixel, data->tab[13].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 0;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	  if ((data->p = change_road(0, data->p)) == NULL
	      || (data->node = change_list(data->p)) == NULL)
	    return (1);
	  pos_player(data->player, data->node);
	}
    }
  return (0);
}

int			change_scene_two_three(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 1650 - data->mv_s->mv_bck;
  pos.y = 400;
  if (data->mv_s->mouse->x + data->mv_s->mv_bck >= 1650
      && data->mv_s->mouse->x + data->mv_s->mv_bck <= 1750
      && data->mv_s->mouse->y <= 500 && data->mv_s->mouse->y >= 400)
    {
      put_pix_in_pix(data->pixel, data->tab[11].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 3;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	  if ((data->p = change_road(0, data->p)) == NULL
	      || (data->node = change_list(data->p)) == NULL)
	    return (1);
	  pos_player(data->player, data->node);
	}
    }
  return (0);
}

int			change_scene_two_four(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 1150 - data->mv_s->mv_bck;
  pos.y = 300;
  if (data->mv_s->mouse->x + data->mv_s->mv_bck >= 1150
      && data->mv_s->mouse->x + data->mv_s->mv_bck <= 1250
      && data->mv_s->mouse->y <= 400 && data->mv_s->mouse->y >= 300)
    {
      put_pix_in_pix(data->pixel, data->tab[11].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 4;
	  data->mv_s->mv_fr = WIDTH - 4;
	  data->mv_s->mv_bck = WIDTH - 4;
	  data->mv_s->click = 0;
	  if ((data->p = change_road(0, data->p)) == NULL
	      || (data->node = change_list(data->p)) == NULL)
	    return (1);
	  pos_player(data->player, data->node);
	}
    }
  return (0);
}

int			shop_place(t_data *data)
{
  t_bunny_position	pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix(data->pixel, data->tab[2].front, pos, data->mv_s->mv_fr);
  if (change_scene_two_zero(data) ||
      change_scene_two_three(data) ||
      change_scene_two_four(data))
    return (1);
  put_pix_in_pix(data->pixel, data->new, pos, 0);
  return (0);
}
