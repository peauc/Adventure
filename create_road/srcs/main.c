/*
** main.c for main in /home/wery_p/rendu/gfx_tekadventure/create_road
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Apr  6 22:16:54 2016 Paul Wery
** Last update Mon Apr 11 18:52:26 2016 Paul Wery
*/

#include <unistd.h>
#include "road.h"

void	ini_struct(t_road *r)
{
  r->state = 0;
  r->points.path = 0;
  r->points.path_0[0].x = -1;
  r->points.path_0[0].y = -1;
  r->points.path_0[1].x = -1;
  r->points.path_0[1].y = -1;
  r->points.path_1[0].x = -1;
  r->points.path_1[0].y = -1;
  r->points.path_1[1].x = -1;
  r->points.path_1[1].y = -1;
  r->points.path_2[0].x = -1;
  r->points.path_2[0].y = -1;
  r->points.path_2[1].x = -1;
  r->points.path_2[1].y = -1;
  r->points.path_3[0].x = -1;
  r->points.path_3[0].y = -1;
  r->points.path_3[1].x = -1;
  r->points.path_3[1].y = -1;
  r->points.el.center.x = -1;
  r->points.el.center.y = -1;
  r->points.el.axe_a = 10;
  r->points.el.axe_b = 5;
  r->points.el.zaxe_a = 10;
  r->points.el.zaxe_b = 5;
}

void	delete_all(t_road *r)
{
  if (r->win != NULL)
    bunny_stop(r->win);
  if (r->pix != NULL)
    bunny_delete_clipable(&r->pix->clipable);
  if (r->back != NULL)
    bunny_delete_clipable(&r->back->clipable);
}

void	start_loop(t_road *r)
{
  if ((r->list = create_list()) == NULL)
    return ;
  ini_struct(r);
  bunny_set_loop_main_function(loop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_set_click_response(my_click);
  bunny_set_wheel_response(wheel_mouse);
  bunny_loop(r->win, 0, r);
}

int		main(int ac, char **av)
{
  t_road	r;

  r.win = NULL;
  r.pix = NULL;
  r.back = NULL;
  if ((r.win = bunny_start(WINL, WINH, true, "Road")) == NULL
      || (r.pix = bunny_new_pixelarray(WINL, WINH)) == NULL)
    return (0);
  if (ac == 2)
    {
      if ((r.back = bunny_load_pixelarray(av[1])) == NULL
	  || (r.back = resize_picture(r.back, WINL, WINH)) == NULL)
	return (0);
    }
  else
    {
      if ((r.back = bunny_new_pixelarray(WINL, WINH)) == NULL)
	return (0);
      pix_initialize(r.back);
    }
  start_loop(&r);
  delete_all(&r);
  return (0);
}
