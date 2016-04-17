/*
** change_road.c for change_road in /home/wery_p/rendu/gfx_tekadventure
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Apr 17 17:16:12 2016 Paul Wery
** Last update Sun Apr 17 18:28:42 2016 Paul Wery
*/

#include "road.h"

int	in_a_ellps(char *image, t_points *it,
		   const t_bunny_position *pos)
{
  if (same_name(image, it->image) == 1
      && pos->x >= (it->el.center.x - it->el.axe_a)
      && pos->x <= (it->el.center.x + it->el.axe_a)
      && pos->y >= (it->el.center.y - it->el.axe_b)
      && pos->y <= (it->el.center.y + it->el.axe_b))
    return (1);
  else
    return (0);
}

void			aff_roads(t_points *list,
				  t_bunny_pixelarray *pix,
				  char *image, int x)
{
  t_points			*it;
  t_road			r;
  const t_bunny_position	*pos;

  r.x = x;
  r.y = 0;
  r.pix = pix;
  it = list->next;
  while (it != list)
    {
      if (same_name(image, it->image) == 1)
        {
          zcircle(&r, pix, &it->el, BLUE);
          if (in_a_ellps(image, it, pos) == 1)
            circle(&r, pix, &it->el, YELLOW);
          else
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
    aff_roads(list, pix, "harbor_back.png", x);
  else if (num_road == 1)
    aff_roads(list, pix, "boat_back.png", x);
  else if (num_road == 2)
    aff_roads(list, pix, "shop_place.png", x);
  else if (num_road == 3)
    aff_roads(list, pix, "shop_back.png", x);
  else if (num_road == 4)
    aff_roads(list, pix, "beach_back.png", x);
  else if (num_road == 5)
    aff_roads(list, pix, "house_out_back.png", x);
  else if (num_road == 6)
    aff_roads(list, pix, "house_in_back.png", x);
  else if (num_road == 7)
    aff_roads(list, pix, "basement.png", x);
  else if (num_road == 8)
    aff_roads(list, pix, "manor.png", x);
  else if (num_road == 9)
    aff_roads(list, pix, "manor_in_back.png", x);
  return (list);
}

t_points	*change_road(int num_road, t_points *list)
{
  if (list != NULL)
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
