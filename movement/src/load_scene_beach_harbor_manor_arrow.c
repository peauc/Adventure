/*
** load_scene_harbor_manor.c for load_scene_harbor_manor in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sat Apr 16 14:09:58 2016 marel_m
** Last update Sat Apr 16 14:19:06 2016 marel_m
*/

#include "scene.h"

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
	  resize_picture(data->tab[0].front, 2048, 576)) == NULL
      || (data->tab[0].name = my_strdup("harbor")) == NULL)
    return (-1);
  return (0);
}

int	load_arrow(t_data *data)
{
  if ((data->tab[10].front =
       bunny_load_pixelarray("pictures/arrow_down.png")) == NULL
      || (data->tab[10].name = my_strdup("down")) == NULL
      || (data->tab[11].front =
	  bunny_load_pixelarray("pictures/arrow_up.png")) == NULL
      || (data->tab[11].name = my_strdup("up")) == NULL
      || (data->tab[12].front =
	  bunny_load_pixelarray("pictures/arrow_left.png")) == NULL
      || (data->tab[12].name = my_strdup("left")) == NULL
      || (data->tab[13].front =
	  bunny_load_pixelarray("pictures/arrow_right.png")) == NULL
      || (data->tab[13].name = my_strdup("right")) == NULL)
    return (-1);
  return (0);
}
