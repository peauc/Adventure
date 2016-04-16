/*
** shop.c for shop in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:37:21 2016 marel_m
** Last update Sat Apr 16 11:39:54 2016 marel_m
*/

#include "default.h"

void                    change_scene_three_two(t_data *data)
{
  t_bunny_position      pos;

  pos.x = 250 - data->mv_s->mv_bck;
  pos.y = 350;
  if (data->mv_s->mouse->x + data->mv_s->mv_bck >= 250
      && data->mv_s->mouse->x + data->mv_s->mv_bck <= 350
      && data->mv_s->mouse->y <= 450 && data->mv_s->mouse->y >= 350)
    {
      put_pix_in_pix_txt(data->pixel, data->tab[11].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 2;
	  data->mv_s->mv_fr = WIDTH / 2;
	  data->mv_s->mv_bck = WIDTH / 2;
	  data->mv_s->click = 0;
	}
    }
}

void			shop(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[3].back, pos, data->mv_s->mv_bck);
  change_scene_three_two(data);
  put_pix_in_pix_txt(data->pixel, data->tab[3].middle, pos, data->mv_s->mv_fr);
  put_pix_in_pix_txt(data->pixel, data->tab[3].front, pos, data->mv_s->mv_fr);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}

void                    change_scene_two_zero(t_data *data)
{
  t_bunny_position      pos;

  pos.x = WIDTH - 100;
  pos.y = 400;
  if (data->mv_s->mouse->x + data->mv_s->mv_bck >= 1948
      && data->mv_s->mouse->x + data->mv_s->mv_bck <= 2048
      && data->mv_s->mouse->y <= 500 && data->mv_s->mouse->y >= 400)
    {
      put_pix_in_pix_txt(data->pixel, data->tab[13].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 0;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	}
    }
}

void                    change_scene_two_three(t_data *data)
{
  t_bunny_position      pos;

  pos.x = 1650 - data->mv_s->mv_bck;
  pos.y = 400;
  if (data->mv_s->mouse->x + data->mv_s->mv_bck >= 1650
      && data->mv_s->mouse->x + data->mv_s->mv_bck <= 1750
      && data->mv_s->mouse->y <= 500 && data->mv_s->mouse->y >= 400)
    {
      put_pix_in_pix_txt(data->pixel, data->tab[11].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 3;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	}
    }
}

void                    change_scene_two_four(t_data *data)
{
  t_bunny_position      pos;

  pos.x = 1150 - data->mv_s->mv_bck;
  pos.y = 300;
  if (data->mv_s->mouse->x + data->mv_s->mv_bck >= 1150
      && data->mv_s->mouse->x + data->mv_s->mv_bck <= 1250
      && data->mv_s->mouse->y <= 400 && data->mv_s->mouse->y >= 300)
    {
      put_pix_in_pix_txt(data->pixel, data->tab[11].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 4;
	  data->mv_s->mv_fr = WIDTH - 4;
	  data->mv_s->mv_bck = WIDTH - 4;
	  data->mv_s->click = 0;
	}
    }
}

void			shop_place(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[2].front, pos, data->mv_s->mv_fr);
  change_scene_two_zero(data);
  change_scene_two_three(data);
  change_scene_two_four(data);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}
