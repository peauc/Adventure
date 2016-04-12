/*
** beach.c for beach in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:30:02 2016 marel_m
** Last update Tue Apr 12 18:16:55 2016 marel_m
*/

#include "default.h"

void			beach(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[1].back, pos);
  put_pix_in_pix_txt(data->pixel, data->tab[1].front, pos);
  put_pix_in_pix_txt(data->pixel, data->new, pos);
}
