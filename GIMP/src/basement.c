/*
** basement.c for basement in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 15:28:42 2016 marel_m
<<<<<<< HEAD
** Last update Fri Apr 15 14:33:05 2016 Poc
=======
** Last update Fri Apr 15 13:57:19 2016 marel_m
>>>>>>> 657c3ad22870ed5e6ddcf59e633c054fff6ab173
*/

#include "default.h"

void			basement(t_data *data)
{
  t_bunny_position	pos;

  pix_initialize(data->pixel);
  pix_initialize(data->new);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(data->pixel, data->tab[7].front, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->tab[11].front, pos, 0);
  put_pix_in_pix_txt(data->pixel, data->new, pos, 0);
  draw_items(&data->tab[7].item, data->pixel);
}
