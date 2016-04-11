/*
** my_list.c for my_list in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Feb 29 20:51:07 2016 Paul Wery
** Last update Mon Apr 11 18:47:09 2016 Paul Wery
*/

#include <stdlib.h>
#include <unistd.h>
#include "road.h"

void		empty_list(t_points *root)
{
  t_points	*it;
  t_points	*save;

  it = root->next;
  while (it != root)
    {
      save = it->next;
      free(it);
      it = save;
    }
}

void	delete_list(t_points **root)
{
  empty_list(*root);
  free(*root);
  *root = NULL;
}

int		add_elem_next(t_points *elem, t_points *src)
{
  t_points	*new_elem;

  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    return (-1);
  new_elem->path = src->path;
  new_elem->path_0[0] = src->path_0[0];
  new_elem->path_0[1] = src->path_0[1];
  new_elem->path_1[0] = src->path_1[0];
  new_elem->path_1[1] = src->path_1[1];
  new_elem->path_2[0] = src->path_2[0];
  new_elem->path_2[1] = src->path_2[1];
  new_elem->path_3[0] = src->path_3[0];
  new_elem->path_3[1] = src->path_3[1];
  new_elem->el.center = src->el.center;
  new_elem->el.axe_a = src->el.axe_a;
  new_elem->el.axe_b = src->el.axe_b;
  new_elem->el.zaxe_a = src->el.zaxe_a;
  new_elem->el.zaxe_b = src->el.zaxe_b;
  new_elem->next = elem->next;
  new_elem->prev = elem;
  elem->next->prev = new_elem;
  elem->next = new_elem;
  return (0);
}

t_points	*create_list(void)
{
  t_points	*root;

  if ((root = malloc(sizeof(*root))) == NULL)
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}
