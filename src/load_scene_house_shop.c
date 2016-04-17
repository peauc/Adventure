/*
** load_all_picture.c for load_all_picture in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 12 11:42:20 2016 marel_m
** Last update Sun Apr 17 11:32:36 2016 marel_m
*/

#include "scene.h"

int	load_shop(t_data *data)
{
  if ((data->tab[3].back =
       bunny_load_pixelarray("sprites/shop_back.png")) == NULL
      || (data->tab[3].back =
	  resize_picture(data->tab[3].back, 2048, 576)) == NULL
      || (data->tab[3].middle =
	  bunny_load_pixelarray("sprites/shop_middle.png")) == NULL
      || (data->tab[3].middle =
	  resize_picture(data->tab[3].middle, 2048, 576)) == NULL
      || (data->tab[3].front =
	  bunny_load_pixelarray("sprites/shop_front.png")) == NULL
      || (data->tab[3].front =
	  resize_picture(data->tab[3].front, 2048, 576)) == NULL
      || (data->tab[3].name = my_strdup("shop")) == NULL
      || (data->tab[2].front =
	  bunny_load_pixelarray("sprites/shop_place.png")) == NULL
      || (data->tab[2].front =
	  resize_picture(data->tab[2].front, 2048, 576)) == NULL
      || (data->tab[2].name = my_strdup("shop_place")) == NULL)
    return (-1);
  return (0);

}

int	load_basement(t_data *data)
{
  if ((data->tab[7].front =
       bunny_load_pixelarray("sprites/basement.png")) == NULL
      || (data->tab[7].front =
	  resize_picture(data->tab[7].front, 1024, 576)) == NULL
      || (data->tab[7].name = my_strdup("basement")) == NULL)
    return (-1);
  return (0);
}

int	load_house_outside(t_data *data)
{
  if ((data->tab[5].back =
       bunny_load_pixelarray("sprites/house_out_back.png")) == NULL
      || (data->tab[5].back =
	  resize_picture(data->tab[5].back, 1024, 576)) == NULL
      || (data->tab[5].middle =
	  bunny_load_pixelarray("sprites/house_out_middle.png")) == NULL
      || (data->tab[5].middle =
	  resize_picture(data->tab[5].middle, 1024, 576)) == NULL
      || (data->tab[5].front =
	  bunny_load_pixelarray("sprites/house_out_front.png")) == NULL
      || (data->tab[5].front =
	  resize_picture(data->tab[5].front, 1024, 576)) == NULL
      || (data->tab[5].name = my_strdup("house_out")) == NULL)
    return (-1);
  return (0);
}

int	load_house_inside(t_data *data)
{
  if ((data->tab[6].back =
       bunny_load_pixelarray("sprites/house_in_back.png")) == NULL
      || (data->tab[6].back =
	  resize_picture(data->tab[6].back, 1024, 576)) == NULL
      || (data->tab[6].middle =
	  bunny_load_pixelarray("sprites/house_in_middle.png")) == NULL
      || (data->tab[6].middle =
	  resize_picture(data->tab[6].middle, 1024, 576)) == NULL
      || (data->tab[6].front =
	  bunny_load_pixelarray("sprites/house_in_front.png")) == NULL
      || (data->tab[6].front =
	  resize_picture(data->tab[6].front, 1024, 576)) == NULL
      || (data->tab[6].name = my_strdup("house_in")) == NULL)
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
      || load_house_outside(data) == -1
      || load_house_inside(data) == -1
      || load_arrow(data) == -1)
        return (-1);
  return (0);
}
