/*
** shop.c for shop in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sat Apr 16 14:06:48 2016 marel_m
** Last update Sat Apr 16 14:23:44 2016 marel_m
*/

#include "scene.h"

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
