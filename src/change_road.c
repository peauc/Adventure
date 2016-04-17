/*
** change_road.c for change_road in /home/wery_p/rendu/gfx_tekadventure
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Apr 17 17:16:12 2016 Paul Wery
** Last update Sun Apr 17 23:08:06 2016 Poc
*/

#include "tekadv.h"
#include "road.h"

void			aff_roads(t_points *list,
				  t_bunny_pixelarray *pix,
				  char *image, int x)
{
  t_points			*it;
  t_road			r;

  r.x = x;
  r.y = 0;
  r.pix = pix;
  it = list->next;
  r.max_x = WIDTH + x;
  r.max_y = HEIGHT;
  while (it != list)
    {
      if (same_name(image, it->image) == 1)
        {
          zcircle(&r, pix, &it->el, BLUE);
	  circle(&r, pix, &it->el, RED);
          line(&r, it);
	}
      it = it->next;
    }
}

void	aff_road(int num_road, t_points *list,
		 t_bunny_pixelarray *pix, int x)
{
  if (num_road == 0)
    aff_roads(list, pix, "pictures/harbor_back.png", x);
  else if (num_road == 1)
    aff_roads(list, pix, "pitcures/boat_back.png", x);
  else if (num_road == 2)
    aff_roads(list, pix, "pictures/shop_place.png", x);
  else if (num_road == 3)
    aff_roads(list, pix, "pictures/shop_back.png", x);
  else if (num_road == 4)
    aff_roads(list, pix, "pictures/beach_back.png", x);
  else if (num_road == 5)
    aff_roads(list, pix, "pictures/house_out_back.png", x);
  else if (num_road == 6)
    aff_roads(list, pix, "pictures/house_in_back.png", x);
  else if (num_road == 7)
    aff_roads(list, pix, "pictures/basement.png", x);
  else if (num_road == 8)
    aff_roads(list, pix, "pictures/manor.png", x);
  else if (num_road == 9)
    aff_roads(list, pix, "pictures/manor_in_back.png", x);
}

t_points	*change_road(int num_road, t_points *list)
{
  if (list != NULL)
    delete_list(&list);
  if ((list = create_list()) == NULL)
    return (NULL);
  if (num_road == 0 && full_ini(list, "pictures/harbor_back.png") == -1)
    return (NULL);
  else if (num_road == 1 && full_ini(list, "pictures/boat_back.png") == -1)
    return (NULL);
  else if (num_road == 2 && full_ini(list, "pictures/shop_place.png") == -1)
    return (NULL);
  else if (num_road == 3 && full_ini(list, "pictures/shop_back.png") == -1)
    return (NULL);
  else if (num_road == 4 && full_ini(list, "pictures/beach_back.png") == -1)
    return (NULL);
  else if (num_road == 5 && full_ini(list, "pictures/house_out_back.png") == -1)
    return (NULL);
  else if (num_road == 6 && full_ini(list, "pictures/house_in_back.png") == -1)
    return (NULL);
  else if (num_road == 7 && full_ini(list, "pictures/basement.png") == -1)
    return (NULL);
  else if (num_road == 8 && full_ini(list, "pictures/manor.png") == -1)
    return (NULL);
  else if (num_road == 9 && full_ini(list, "pictures/manor_in_back.png") == -1)
    return (NULL);
  return (list);
}
