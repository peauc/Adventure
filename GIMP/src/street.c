/*
** boat.c for boat in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:22:50 2016 marel_m
** Last update Thu Apr 14 13:12:26 2016 marel_m
*/

#include "default.h"

void			street(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[10].back, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->tab[10].front, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}
