/*
** manor_inside.c for manor_inside in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:35:23 2016 marel_m
** Last update Sun Apr 17 21:20:30 2016 Poc
*/

#include "tekadv.h"

int			change_scene_nine_eight(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 200 - data->mv_s->mv_bck;
  pos.y = 250;
  if (data->mv_s->mouse.x + data->mv_s->mv_bck >= 200
      && data->mv_s->mouse.x + data->mv_s->mv_bck <= 300
      && data->mv_s->mouse.y <= 350 && data->mv_s->mouse.y >= 250)
    {
      put_pix_in_pix(data->pixel, data->tab[11].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 8;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	  if ((data->p = change_road(8, data->p)) == NULL
	      || (data->node = change_list(data->p)) == NULL)
	    return (1);
	  pos_player(data->player, data->node);
	}
    }
  return (0);
}

int			manor_in(t_data *data)
{
  t_bunny_position	pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix(data->pixel, data->tab[9].back, pos, data->mv_s->mv_bck);
  put_pix_in_pix(data->pixel, data->tab[9].front, pos, data->mv_s->mv_fr);
  if (change_scene_nine_eight(data))
    return (1);
  put_pix_in_pix(data->pixel, data->new, pos, 0);
  return (0);
}

int			change_scene_eight_zero(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 475;
  if (data->mv_s->mouse.x >= 0
      && data->mv_s->mouse.x <= 100
      && data->mv_s->mouse.y <= 575 && data->mv_s->mouse.y >= 475)
    {
      put_pix_in_pix(data->pixel, data->tab[12].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 0;
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

int			change_scene_eight_nine(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 300;
  pos.y = 325;
  if (data->mv_s->mouse.x >= 300
      && data->mv_s->mouse.x <= 400
      && data->mv_s->mouse.y <= 425 && data->mv_s->mouse.y >= 325)
    {
      put_pix_in_pix(data->pixel, data->tab[11].front, pos, 0);
      if (data->mv_s->click == 1 && data->menu->buttons[1].is_clicked == 1
	  && data->tab[7].item[0].selected[0] == 1)
	{
	  data->mv_s->s_nb = 9;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	  if ((data->p = change_road(9, data->p)) == NULL
	      || (data->node = change_list(data->p)) == NULL)
	    return (1);
	  pos_player(data->player, data->node);
	}
    }
  return (0);
}

int			manor(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix(data->pixel, data->tab[8].front, pos, 0);
  if (change_scene_eight_zero(data) ||
      change_scene_eight_nine(data))
    return (1);
  put_pix_in_pix(data->pixel, data->new, pos, 0);
  return (0);
}
