/*
** house_inside.c for house_inside in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:32:57 2016 marel_m
** Last update Fri Apr 15 11:39:25 2016 marel_m
*/

#include "default.h"

void			house_inside(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[6].back, pos, data->mv_s.mv_bck);
  put_pix_in_pix_txt(data->pixel, data->tab[6].middle, pos, data->mv_s.mv_mid);
  put_pix_in_pix_txt(data->pixel, data->tab[6].front, pos, data->mv_s.mv_fr);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}

void			house_outside(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[5].back, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->tab[5].front, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}
