/*
** load_ini.c for takadv in /home/sauvau_m/rendu/gfx_tekadventure
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue Apr 12 15:49:54 2016 Mathieu Sauvau
** Last update Tue Apr 12 16:19:14 2016 Mathieu Sauvau
*/

#include "tekadv.h"
#include "road.h"

bool		load_ini(char *ini)
{
  t_bunny_ini	*ini;
  int		nb_node;

  if ((ini = bunny_load_ini(ini)) == NULL)
    return (NULL);

}
