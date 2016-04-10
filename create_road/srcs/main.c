/*
** main.c for main in /home/wery_p/rendu/gfx_tekadventure/create_road
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Apr  6 22:16:54 2016 Paul Wery
** Last update Sun Apr 10 15:44:48 2016 Paul Wery
*/

#include <lapin.h>
#include "road.h"

void	delete_all(t_road *r)
{
  bunny_stop(r->win);
  bunny_delete_clipable(&r->pix->clipable);
  bunny_delete_clipable(&r->back->clipable);
}

void	start_loop(t_road *r)
{
  bunny_set_loop_main_function(loop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_set_click_response(my_click);
  bunny_loop(r->win, 0, r);
}

int		main(int ac, char **av)
{
  t_road	r;

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
