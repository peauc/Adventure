/*
** basement.c for basement in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:28:42 2016 marel_m
** Last update Tue Apr 12 15:29:50 2016 marel_m
*/

#include "default.h"

void			basement(t_data *data)
{
  t_bunny_position	pos;

  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->basement, pos);
  put_pix_in_pix_txt(data->pixel, data->new, pos);
}
