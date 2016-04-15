/*
** boat.c for boat in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:22:50 2016 marel_m
** Last update Fri Apr 15 11:38:13 2016 marel_m
*/

#include "default.h"

void	boat(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[1].back, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->tab[1].front, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}
