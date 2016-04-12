/*
** load_all_picture.c for load_all_picture in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 11:42:20 2016 marel_m
** Last update Tue Apr 12 18:26:21 2016 marel_m
*/

#include "default.h"

int	load_all_scene(t_data *data)
{
  if ((data->tab[0].front = bunny_load_pixelarray("pictures/basement.png")) == NULL
      || (data->tab[0].front = resize_picture(data->tab[0].front, 1024, 576)) == NULL
      || (data->tab[0].name = my_strdup("basement")) == NULL
      || (data->tab[1].back = bunny_load_pixelarray("pictures/beach_back.png")) == NULL
      || (data->tab[1].back = resize_picture(data->tab[1].back, 2048, 576)) == NULL
      || (data->tab[1].front = bunny_load_pixelarray("pictures/beach_front.png")) == NULL
      || (data->tab[1].front = resize_picture(data->tab[1].front, 2048, 576)) == NULL
      || (data->tab[1].name = my_strdup("beach")) == NULL
      || (data->tab[2].back = bunny_load_pixelarray("pictures/boat_back.png")) == NULL
      || (data->tab[2].back = resize_picture(data->tab[2].back, 1024, 576)) == NULL
      || (data->tab[2].front = bunny_load_pixelarray("pictures/boat_front.png")) == NULL
      || (data->tab[2].front = resize_picture(data->tab[2].front, 1024, 576)) == NULL
      || (data->tab[2].name = my_strdup("boat")) == NULL
      || (data->tab[3].back = bunny_load_pixelarray("pictures/harbor_back.png")) == NULL
      || (data->tab[3].back = resize_picture(data->tab[3].back, 2048, 576)) == NULL
      || (data->tab[3].front = bunny_load_pixelarray("pictures/harbor_front.png")) == NULL
      || (data->tab[3].front = resize_picture(data->tab[3].front, 2048, 576)) == NULL
      || (data->tab[3].name = my_strdup("harbor")) == NULL
      || (data->tab[4].back = bunny_load_pixelarray("pictures/house_in_back.png")) == NULL
      || (data->tab[4].back = resize_picture(data->tab[4].back, 1024, 576)) == NULL
      || (data->tab[4].middle = bunny_load_pixelarray("pictures/house_in_middle.png")) == NULL
      || (data->tab[4].middle = resize_picture(data->tab[4].middle, 1024, 576)) == NULL
      || (data->tab[4].front = bunny_load_pixelarray("pictures/house_in_front.png")) == NULL
      || (data->tab[4].front = resize_picture(data->tab[4].front, 1024, 576)) == NULL
      || (data->tab[4].name = my_strdup("house_in")) == NULL
      || (data->tab[5].front = bunny_load_pixelarray("pictures/house_night.png")) == NULL
      || (data->tab[5].front = resize_picture(data->tab[5].front, 1024, 576)) == NULL
      || (data->tab[5].name = my_strdup("house_night")) == NULL
      || (data->tab[6].back = bunny_load_pixelarray("pictures/manor_in_back.png")) == NULL
      || (data->tab[6].back = resize_picture(data->tab[6].back, 2048, 576)) == NULL
      || (data->tab[6].front = bunny_load_pixelarray("pictures/manor_in_front.png")) == NULL
      || (data->tab[6].front = resize_picture(data->tab[6].front, 2048, 576)) == NULL
      || (data->tab[6].name = my_strdup("manor_in")) == NULL
      || (data->tab[7].front = bunny_load_pixelarray("pictures/manor.png")) == NULL
      || (data->tab[7].front = resize_picture(data->tab[7].front, 1024, 576)) == NULL
      || (data->tab[7].name = my_strdup("manor")) == NULL
      || (data->tab[8].back = bunny_load_pixelarray("pictures/shop_back.png")) == NULL
      || (data->tab[8].back = resize_picture(data->tab[8].back, 2048, 576)) == NULL
      || (data->tab[8].middle = bunny_load_pixelarray("pictures/shop_middle.png")) == NULL
      || (data->tab[8].middle = resize_picture(data->tab[8].middle, 2048, 576)) == NULL
      || (data->tab[8].front = bunny_load_pixelarray("pictures/shop_front.png")) == NULL
      || (data->tab[8].front = resize_picture(data->tab[8].front, 2048, 576)) == NULL
      || (data->tab[8].name = my_strdup("shop")) == NULL
      || (data->tab[9].front = bunny_load_pixelarray("pictures/shop_place.png")) == NULL
      || (data->tab[9].front = resize_picture(data->tab[9].front, 2048, 576)) == NULL
      || (data->tab[9].name = my_strdup("shop_place")) == NULL
      || (data->tab[10].back = bunny_load_pixelarray("pictures/street_back.png")) == NULL
      || (data->tab[10].back = resize_picture(data->tab[10].back, 1024, 576)) == NULL
      || (data->tab[10].front = bunny_load_pixelarray("pictures/street_front.png")) == NULL
      || (data->tab[10].front = resize_picture(data->tab[10].front, 1024, 576)) == NULL
      || (data->tab[10].name = my_strdup("street")) == NULL)
    return (-1);
  return (0);
}
