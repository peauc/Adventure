/*
** house_inside.c for house_inside in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:32:57 2016 marel_m
** Last update Fri Apr 15 22:45:38 2016 marel_m
*/

#include "default.h"

void                    change_scene_six_five(t_data *data)
{
  t_bunny_position      pos;

  pos.x = 810;
  pos.y = 300;
  if (data->mv_s->mouse->x >= 810
      && data->mv_s->mouse->x <= 910
      && data->mv_s->mouse->y <= 400 && data->mv_s->mouse->y >= 300)
    {
      put_pix_in_pix_txt(data->pixel, data->tab[11].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 5;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	}
    }
}

void                    change_scene_six_seven(t_data *data)
{
  t_bunny_position      pos;

  pos.x = 200;
  pos.y = 400;
  if (data->mv_s->mouse->x >= 200
      && data->mv_s->mouse->x <= 300
      && data->mv_s->mouse->y <= 500 && data->mv_s->mouse->y >= 400)
    {
      put_pix_in_pix_txt(data->pixel, data->tab[10].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 7;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	}
    }
}

void			house_in(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[6].back, pos, data->mv_s->mv_bck);
  change_scene_six_five(data);
  change_scene_six_seven(data);
  put_pix_in_pix_txt(data->pixel, data->tab[6].middle, pos, data->mv_s->mv_mid);
  put_pix_in_pix_txt(data->pixel, data->tab[6].front, pos, data->mv_s->mv_fr);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}

void                    change_scene_five_four(t_data *data)
{
  t_bunny_position      pos;

  pos.x = WIDTH / 2 + 125;
  pos.y = 476;
  if (data->mv_s->mouse->x >= WIDTH / 2 + 125
      && data->mv_s->mouse->x <= WIDTH / 2 + 225
      && data->mv_s->mouse->y <= 576 && data->mv_s->mouse->y >= 476)
    {
      put_pix_in_pix_txt(data->pixel, data->tab[10].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 4;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	}
    }
}

void                    change_scene_five_six(t_data *data)
{
  t_bunny_position      pos;

  pos.x = 450;
  pos.y = 300;
  if (data->mv_s->mouse->x >= 450
      && data->mv_s->mouse->x <= 550
      && data->mv_s->mouse->y <= 400 && data->mv_s->mouse->y >= 300)
    {
      put_pix_in_pix_txt(data->pixel, data->tab[11].front, pos, 0);
      if (data->mv_s->click == 1)
	{
	  data->mv_s->s_nb = 6;
	  data->mv_s->mv_fr = 0;
	  data->mv_s->mv_bck = 0;
	  data->mv_s->click = 0;
	}
    }
}

void			house_out(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[5].back, pos, 0);
  change_scene_five_four(data);
  change_scene_five_six(data);
  put_pix_in_pix_txt(data->pixel, data->tab[5].front, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}
