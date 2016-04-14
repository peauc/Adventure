/*
** basement.c for basement in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:28:42 2016 marel_m
** Last update Thu Apr 14 17:36:45 2016 marel_m
*/

#include "default.h"

void			basement(t_data *data)
{
  t_bunny_position	pos;
  t_bunny_position	pos1;
  t_bunny_pixelarray	*key;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  pos1.x = 50;
  pos1.y = 50;
  key = bunny_load_pixelarray("pictures/key_poc.png");
  put_pix_in_pix_txt(data->pixel, data->tab[0].front, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
  put_pix_in_pix_txt(data->pixel, key, pos1, 0);
}
