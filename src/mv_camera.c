/*
** mv_camera.c for mv_camera in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sun Apr 17 14:41:55 2016 marel_m
** Last update Sun Apr 17 21:15:32 2016 marel_m
*/

#include "tekadv.h"

void	mv_camera_mouse(t_data *data)
{
  static int	i;

  if (i != 0 && data->mv_s->s_nb != 5)
    {
      if ((data->mv_s->old_pos < data->mv_s->pos.x)
	  && data->mv_s->mv_bck + 3 < WIDTH)
	data->mv_s->mv_bck += 3;
      else if ((data->mv_s->old_pos > data->mv_s->pos.x
		|| data->mv_s->pos.x < 100)
	       && data->mv_s->mv_bck > 3)
	data->mv_s->mv_bck -= 3;
    }
  i++;
}
