/*
** manor_inside.c for manor_inside in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:35:23 2016 marel_m
** Last update Tue Apr 12 18:17:54 2016 marel_m
*/

#include "default.h"

void			manor_inside(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[6].back, pos);
  put_pix_in_pix_txt(data->pixel, data->tab[6].front, pos);
  put_pix_in_pix_txt(data->pixel, data->new, pos);
}

void			manor_outside(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[7].front, pos);
  put_pix_in_pix_txt(data->pixel, data->new, pos);
}
