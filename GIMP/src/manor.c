/*
** manor_inside.c for manor_inside in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:35:23 2016 marel_m
** Last update Thu Apr 14 15:18:27 2016 marel_m
*/

#include "default.h"

void			manor_inside(t_data *data)
{
  t_bunny_position      pos;
  t_bunny_position      pos1;
  t_bunny_pixelarray	*banana;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  if ((banana = bunny_load_pixelarray("pictures/banana_poc.png")) == NULL)
    return ;
  put_pix_in_pix_txt(data->pixel, data->tab[6].back, pos, data->mv_s.mv_bck);
  put_pix_in_pix_txt(data->pixel, data->tab[6].front, pos, data->mv_s.mv_fr);
  put_pix_in_pix_txt(data->pixel, banana, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}

void			manor_outside(t_data *data)
{
  t_bunny_position      pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[7].front, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
}
