/*
** change_road.c for change_road in /home/wery_p/rendu/gfx_tekadventure
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Apr 17 17:16:12 2016 Paul Wery
** Last update Sun Apr 17 17:35:20 2016 Paul Wery
*/

#include "road.h"

t_points	*change_road(int num_road, t_points *list)
{
  delete_list(&list);
  if ((list = create_list()) == NULL)
    return (NULL);
  if (num_road == 0 && full_ini(list, "harbor_back.png") == -1)
    return (NULL);
  else if (num_road == 1 && full_ini(list, "boat_back.png") == -1)
    return (NULL);
  else if (num_road == 2 && full_ini(list, "shop_place.png") == -1)
    return (NULL);
  else if (num_road == 3 && full_ini(list, "shop_back.png") == -1)
    return (NULL);
  else if (num_road == 4 && full_ini(list, "beach_back.png") == -1)
    return (NULL);
  else if (num_road == 5 && full_ini(list, "house_out_back.png") == -1)
    return (NULL);
  else if (num_road == 6 && full_ini(list, "house_in_back.png") == -1)
    return (NULL);
  else if (num_road == 7 && full_ini(list, "basement.png") == -1)
    return (NULL);
  else if (num_road == 8 && full_ini(list, "manor.png") == -1)
    return (NULL);
  else if (num_road == 9 && full_ini(list, "manor_in_back.png") == -1)
    return (NULL);
  return (list);
}
