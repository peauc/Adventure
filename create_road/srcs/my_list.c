/*
** my_list.c for my_list in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Feb 29 20:51:07 2016 Paul Wery
** Last update Sun Apr 10 15:35:57 2016 Paul Wery
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
  new_elem->el.center = src->el.center;
  new_elem->el.axe_a = src->el.axe_a;
  new_elem->el.axe_b = src->el.axe_b;
  new_elem->line.one = src->line.one;
  new_elem->line.two = src->line.two;
  new_elem->line.width = src->line.width;
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
