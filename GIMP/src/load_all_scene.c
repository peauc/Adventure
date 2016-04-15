/*
** load_all_picture.c for load_all_picture in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 11:42:20 2016 marel_m
** Last update Fri Apr 15 13:27:19 2016 Poc
*/

#include "default.h"

int	load_manor(t_data *data)
{
  if ((data->tab[9].back =
       bunny_load_pixelarray("pictures/manor_in_back.png")) == NULL
      || (data->tab[9].back =
	  resize_picture(data->tab[9].back, 2048, 576)) == NULL
      || (data->tab[9].front =
	  bunny_load_pixelarray("pictures/manor_in_front.png")) == NULL
      || (data->tab[9].front
	  = resize_picture(data->tab[9].front, 2048, 576)) == NULL
      || (data->tab[9].name = my_strdup("manor_in")) == NULL
      || (data->tab[8].front
	  = bunny_load_pixelarray("pictures/manor.png")) == NULL
      || (data->tab[8].front
	  = resize_picture(data->tab[8].front, 1024, 576)) == NULL
      || (data->tab[8].name = my_strdup("manor")) == NULL)
    return (-1);
  return (0);
}

int	load_harbor(t_data *data)
{
  if ((data->tab[1].back =
       bunny_load_pixelarray("pictures/boat_back.png")) == NULL
      || (data->tab[1].back =
	  resize_picture(data->tab[1].back, 1024, 576)) == NULL
      || (data->tab[1].front =
	  bunny_load_pixelarray("pictures/boat_front.png")) == NULL
      || (data->tab[1].front =
	  resize_picture(data->tab[1].front, 1024, 576)) == NULL
      || (data->tab[1].name = my_strdup("boat")) == NULL
      || (data->tab[0].back =
	  bunny_load_pixelarray("pictures/harbor_back.png")) == NULL
      || (data->tab[0].back =
	  resize_picture(data->tab[0].back, 2048, 576)) == NULL
      || (data->tab[0].front =
	  bunny_load_pixelarray("pictures/harbor_front.png")) == NULL
      || (data->tab[0].front =
	  resize_picture(data->tab[0].front, 1024, 576)) == NULL
      || (data->tab[0].name = my_strdup("harbor")) == NULL)
    return (-1);
  return (0);
}

int	load_shop(t_data *data)
{
  if ((data->tab[3].back =
       bunny_load_pixelarray("pictures/shop_back.png")) == NULL
      || (data->tab[3].back =
	  resize_picture(data->tab[3].back, 2048, 576)) == NULL
      || (data->tab[3].middle =
	  bunny_load_pixelarray("pictures/shop_middle.png")) == NULL
      || (data->tab[3].middle =
	  resize_picture(data->tab[3].middle, 2048, 576)) == NULL
      || (data->tab[3].front =
	  bunny_load_pixelarray("pictures/shop_front.png")) == NULL
      || (data->tab[3].front =
	  resize_picture(data->tab[3].front, 2048, 576)) == NULL
      || (data->tab[3].name = my_strdup("shop")) == NULL
      || (data->tab[2].front =
	  bunny_load_pixelarray("pictures/shop_place.png")) == NULL
      || (data->tab[2].front =
	  resize_picture(data->tab[2].front, 2048, 576)) == NULL
      || (data->tab[2].name = my_strdup("shop_place")) == NULL)
    return (-1);
  return (0);

}

int	load_beach(t_data *data)
{
  if ((data->tab[4].back =
       bunny_load_pixelarray("pictures/beach_back.png")) == NULL
      || (data->tab[4].back =
	  resize_picture(data->tab[4].back, 2048, 576)) == NULL
      || (data->tab[4].front =
	  bunny_load_pixelarray("pictures/beach_front.png")) == NULL
      || (data->tab[4].front =
	  resize_picture(data->tab[4].front, 2048, 576)) == NULL
      || (data->tab[4].name = my_strdup("beach")) == NULL)
    return (-1);
  return (0);
}

int	load_basement(t_data *data)
{
  if ((data->tab[7].front =
       bunny_load_pixelarray("pictures/basement.png")) == NULL
      || (data->tab[7].front =
	  resize_picture(data->tab[7].front, 1024, 576)) == NULL
      || (data->tab[7].name = my_strdup("basement")) == NULL
      /* || (load_item_basement(&(data->tab[7].item))) */)
    return (-1);
  return (0);
}

int	load_house(t_data *data)
{
  if ((data->tab[6].back =
       bunny_load_pixelarray("pictures/house_in_back.png")) == NULL
      || (data->tab[6].back =
	  resize_picture(data->tab[6].back, 1024, 576)) == NULL
      || (data->tab[6].middle =
	  bunny_load_pixelarray("pictures/house_in_middle.png")) == NULL
      || (data->tab[6].middle =
	  resize_picture(data->tab[6].middle, 1024, 576)) == NULL
      || (data->tab[6].front =
	  bunny_load_pixelarray("pictures/house_in_front.png")) == NULL
      || (data->tab[6].front =
	  resize_picture(data->tab[6].front, 1024, 576)) == NULL
      || (data->tab[6].name = my_strdup("house_in")) == NULL
      || (data->tab[5].back =
	  bunny_load_pixelarray("pictures/house_out_back.png")) == NULL
      || (data->tab[5].back =
	  resize_picture(data->tab[5].back, 1024, 576)) == NULL
      || (data->tab[5].front =
	  bunny_load_pixelarray("pictures/house_out_front.png")) == NULL
      || (data->tab[5].front =
	  resize_picture(data->tab[5].front, 1024, 576)) == NULL
      || (data->tab[5].name = my_strdup("house_out")) == NULL)
    return (-1);
  return (0);
}

int	load_all_scene(t_data *data)
{
  if (load_manor(data) == -1
      || load_harbor(data) == -1
      || load_beach(data) == -1
      || load_shop(data) == -1
      || load_basement(data) == -1
      || load_house(data) == -1)
        return (-1);
  return (0);
}
