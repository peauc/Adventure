/*
** free_scene.c for free_scene in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sat Apr 16 15:10:11 2016 marel_m
** Last update Sun Apr 17 15:19:11 2016 Poc
*/

#include "scene.h"

void	delete_item(t_item *item)
{
  int	i;

  i = 0;
  if (!item)
    return ;
  while (item->sprite[i])
    {
      bunny_delete_clipable(&item->sprite[i]->clipable);
      bunny_free(item->pos);
      bunny_free(item->selected);
      i++;
    }
}

void	free_buttons(t_button *button)
{
  int	i;

  i = 0;
  while (i < 4)
    {
      printf("button[i] %s\n", button[i].name);
      bunny_free(button[i].name);
      bunny_delete_clipable(&button[i].sprite);
      bunny_delete_clipable(&button[i].active_sprite);
      i++;
    }
}

void	free_data(t_data *data)
{
  int	i;

  i = -1;
  free_buttons(data->menu->buttons);
  while (++i < 14)
    {
      printf("%s\n", data->tab[i].name);
      bunny_free(data->tab[i].name);
      bunny_delete_clipable(&data->tab[i].front->clipable);
      delete_item(data->tab[i].item);
      if (i == 0 || i == 1 || i == 4 || i == 9)
	bunny_delete_clipable(&data->tab[i].back->clipable);
      else if (i == 3 || i == 5 || i == 6)
	{
	  bunny_delete_clipable(&data->tab[i].back->clipable);
	  bunny_delete_clipable(&data->tab[i].middle->clipable);
	}
    }
}
