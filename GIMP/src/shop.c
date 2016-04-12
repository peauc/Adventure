/*
** shop.c for shop in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:37:21 2016 marel_m
** Last update Tue Apr 12 15:39:20 2016 marel_m
*/

#include "default.h"

void			shop(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->shop_back, pos);
  put_pix_in_pix_txt(data->pixel, data->shop_middle, pos);
  put_pix_in_pix_txt(data->pixel, data->shop_front, pos);
  put_pix_in_pix_txt(data->pixel, data->new, pos);
}

void			shop_place(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->shop_place, pos);
  put_pix_in_pix_txt(data->pixel, data->new, pos);
}
