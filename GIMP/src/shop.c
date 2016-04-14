/*
** shop.c for shop in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:37:21 2016 marel_m
** Last update Thu Apr 14 13:12:04 2016 marel_m
*/

#include "default.h"

void			shop(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[8].back, pos, data->mv_bck);
  put_pix_in_pix_txt(data->pixel, data->tab[8].middle, pos, data->mv_pid);
  put_pix_in_pix_txt(data->pixel, data->tab[8].front, pos, data->MV_fr);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}

void			shop_place(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[9].front, pos, data->mv_fr);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}
