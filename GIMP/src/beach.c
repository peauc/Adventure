/*
** beach.c for beach in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:30:02 2016 marel_m
** Last update Thu Apr 14 13:20:02 2016 marel_m
*/

#include "default.h"

void			beach(t_data *data)
{
  t_bunny_position      pos;
  static int		i = 0;

  data->mv_bck = i;
  data->mv_fr = i;
  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[1].back, pos, data->mv_bck);
  put_pix_in_pix_txt(data->pixel, data->tab[1].front, pos, data->mv_fr);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
  if (i < data->)
    i++;
}
