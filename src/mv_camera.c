/*
** mv_camera.c for mv_camera in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sun Apr 17 14:41:55 2016 marel_m
** Last update Sun Apr 17 16:14:56 2016 marel_m
*/

#include "scene.h"

void	mv_front_camera(t_data *data)
{
  if (data->mv_s->s_nb == 1 || data->mv_s->s_nb == 9 || data->mv_s->s_nb == 3
      || data->mv_s->s_nb == 4 || data->mv_s->s_nb == 2)
    {
      if ((data->mv_s->old_mouse < data->mv_s->mouse->x
	   || data->mv_s->mouse->x > WIDTH - 100)
	  && data->mv_s->mv_fr + 3 < WIDTH)
	data->mv_s->mv_fr += 3;
      else if ((data->mv_s->old_mouse > data->mv_s->mouse->x
		|| data->mv_s->mouse->x < 100)
	       && data->mv_s->mv_fr > 3)
	data->mv_s->mv_fr -= 3;
    }
  else if (data->mv_s->s_nb == 0)
    {
      if ((data->mv_s->old_mouse < data->mv_s->mouse->x
	   || data->mv_s->mouse->x > WIDTH - 100)
	  && data->mv_s->mv_bck + 3 < WIDTH)
	data->mv_s->mv_fr += 5;
      else if ((data->mv_s->old_mouse > data->mv_s->mouse->x
		|| data->mv_s->mouse->x < 100)
	       && data->mv_s->mv_bck > 3)
	data->mv_s->mv_fr -= 5;
    }
}

void	mv_camera_mouse(t_data *data)
{
  static int	i;

  if (i != 0)
    {
      if ((data->mv_s->old_mouse < data->mv_s->mouse->x
	   || data->mv_s->mouse->x > WIDTH - 100)
	  && data->mv_s->mv_bck + 3 < WIDTH)
	data->mv_s->mv_bck += 3;
      else if ((data->mv_s->old_mouse > data->mv_s->mouse->x
		|| data->mv_s->mouse->x < 100)
	       && data->mv_s->mv_bck > 3)
	data->mv_s->mv_bck -= 3;
      mv_front_camera(data);
    }
  i++;
}
