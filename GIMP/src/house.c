/*
** house_inside.c for house_inside in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:32:57 2016 marel_m
** Last update Tue Apr 12 15:38:58 2016 marel_m
*/

#include "default.h"

void			house_inside(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->house_inside_back, pos);
  put_pix_in_pix_txt(data->pixel, data->house_inside_middle, pos);
  put_pix_in_pix_txt(data->pixel, data->house_inside_front, pos);
  put_pix_in_pix_txt(data->pixel, data->new, pos);
}

void			house_night(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->house_night, pos);
  put_pix_in_pix_txt(data->pixel, data->new, pos);
}
