/*
** manor_inside.c for manor_inside in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:35:23 2016 marel_m
** Last update Fri Apr 15 11:40:08 2016 marel_m
*/

#include "default.h"

void			manor_inside(t_data *data)
{
  t_bunny_position      pos;
  t_bunny_position      pos1;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[9].back, pos, data->mv_s.mv_bck);
  put_pix_in_pix_txt(data->pixel, data->tab[9].front, pos, data->mv_s.mv_fr);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}

void			manor_outside(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[8].front, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}
