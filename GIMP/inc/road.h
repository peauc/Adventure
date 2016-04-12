/*
** road.h for road in /home/wery_p/rendu/gfx_tekadventure/create_road
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Apr  6 22:23:37 2016 Paul Wery
** Last update Tue Apr 12 11:16:59 2016 marel_m
*/

#ifndef ROAD
#define ROAD

#define WINL (1920)
#define WINH (1080)

#define UNUSED __attribute__((unused))

#include <lapin.h>

typedef struct	s_my_scale
{
  double	scale_x;
  double	scale_y;
}		t_my_scale;

typedef struct	s_resize
{
  double	x_one;
  double	y_one;
  double	x_two;
  double	y_two;
  t_color	*color;
  t_color	*pixel;
  int		i;
}		t_resize;

#endif /* !ROAD */
