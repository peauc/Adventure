/*
** draw_scene.c for draw_scene in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_tekadventure/GIMP
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Apr 15 15:07:59 2016 marel_m
** Last update Sat Apr 16 14:19:47 2016 marel_m
*/

#include "scene.h"

t_scene_nb	*init_tab()
{
  t_scene_nb	*tab;

  if ((tab = malloc(sizeof(t_scene_nb) * MAX_SCENE)) == NULL)
    return (NULL);
  tab[HARBOR].scene_nb = 0;
  tab[HARBOR].ft_scene_nb = &harbor;
  tab[BOAT].scene_nb = 1;
  tab[BOAT].ft_scene_nb = &boat;
  tab[SHOP_PLACE].scene_nb = 2;
  tab[SHOP_PLACE].ft_scene_nb = &shop_place;
  tab[SHOP].scene_nb = 3;
  tab[SHOP].ft_scene_nb = &shop;
  tab[BEACH].scene_nb = 4;
  tab[BEACH].ft_scene_nb = &beach;
  tab[HOUSE_OUT].scene_nb = 5;
  tab[HOUSE_OUT].ft_scene_nb = &house_out;
  tab[HOUSE_IN].scene_nb = 6;
  tab[HOUSE_IN].ft_scene_nb = &house_in;
  tab[BASEMENT].scene_nb = 7;
  tab[BASEMENT].ft_scene_nb = &basement;
  tab[MANOR].scene_nb = 8;
  tab[MANOR].ft_scene_nb = &manor;
  tab[MANOR_IN].scene_nb = 9;
  tab[MANOR_IN].ft_scene_nb = &manor_in;
  return (tab);
}

int		draw_scene(t_data *data)
{
  t_scene_nb	*fptrtab;
  int		i;

  if ((fptrtab = init_tab()) == NULL)
    return (-1);
  i = -1;
  while (++i < MAX_SCENE)
    if (i == data->mv_s->s_nb)
      fptrtab[i].ft_scene_nb(data);
  return (0);
}
