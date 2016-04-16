/*
** free_scene.c for free_scene in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sat Apr 16 15:10:11 2016 marel_m
** Last update Sat Apr 16 15:23:22 2016 marel_m
*/

#include "scene.h"

void	free_scene(t_data *data)
{
  int	i;

  i = -1;
  while (++i < 14)
    {
      free(data->tab[i].name);
      bunny_delete_clipable(&data->tab[i].front->clipable);
      if (i == 0 || i == 1 || i == 4 || i == 9)
	bunny_delete_clipable(&data->tab[i].back->clipable);
      else if (i == 3 || i == 5 || i == 6)
	{
	  bunny_delete_clipable(&data->tab[i].back->clipable);
	  bunny_delete_clipable(&data->tab[i].middle->clipable);
	}
    }
}
