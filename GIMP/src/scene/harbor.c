/*
** harbor.c for harbor in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:17:55 2016 marel_m
** Last update Sat Apr 16 11:42:35 2016 marel_m
*/

#include "default.h"

void			change_scene_zero_two(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 400;
  if (data->mv_s->mouse->x + data->mv_s->mv_bck >= 0
      && data->mv_s->mouse->x + data->mv_s->mv_bck <= 100
      && data->mv_s->mouse->y <= 500 && data->mv_s->mouse->y >= 400)
    {
      put_pix_in_pix_txt(data->pixel, data->tab[12].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 2;
	  data->mv_s->mv_fr = WIDTH - 4;
	  data->mv_s->mv_bck = WIDTH - 4;
	  data->mv_s->click = 0;
	}
    }
}

void			change_scene_zero_eight(t_data *data)
{
  t_bunny_position	pos;

  pos.x = WIDTH - 100;
  pos.y = 350;
  if (data->mv_s->mouse->x + data->mv_s->mv_bck >= 2048 - 100
      && data->mv_s->mouse->x + data->mv_s->mv_bck <= 2048
      && data->mv_s->mouse->y <= 450 && data->mv_s->mouse->y >= 350)
    {
      put_pix_in_pix_txt(data->pixel, data->tab[13].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 8;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	}
    }
}

void			change_scene_zero_one(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 1350 - data->mv_s->mv_bck;
  pos.y = 50;
  if (data->mv_s->mouse->x + data->mv_s->mv_bck >= 1350
      && data->mv_s->mouse->x + data->mv_s->mv_bck <= 1450
      && data->mv_s->mouse->y <= 150 && data->mv_s->mouse->y >= 50)
    {
      put_pix_in_pix_txt(data->pixel, data->tab[11].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 1;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	}
    }
}

void			harbor(t_data *data)
{
  t_bunny_position	pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[0].back, pos, data->mv_s->mv_bck);
  change_scene_zero_two(data);
  change_scene_zero_eight(data);
  change_scene_zero_one(data);
  put_pix_in_pix_txt(data->pixel, data->tab[0].front, pos, data->mv_s->mv_fr);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}
