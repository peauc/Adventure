/*
** node_list.c for  in /home/sauvau_m/rendu/gfx_tekadventure
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sat Apr 16 09:59:29 2016 Mathieu Sauvau
** Last update Sun Apr 17 11:48:42 2016 marel_m
*/

#include "tekadv.h"

t_points	*cpy_node(t_points *point)
{
  t_points	*p;

  if (point == NULL ||
      (p = bunny_malloc(sizeof(t_points))) == NULL)
    return (NULL);
  p->index = point->index;
  p->el.center = point->el.center;
  p->el.axe_a = point->el.axe_a;
  p->el.axe_b = point->el.axe_b;
  p->el.zaxe_a = point->el.zaxe_a;
  p->el.zaxe_b = point->el.zaxe_b;
  p->path_0[0] = point->path_0[0];
  p->path_0[1] = point->path_0[1];
  p->path_1[0] = point->path_1[0];
  p->path_1[1] = point->path_1[1];
  p->path_2[0] = point->path_2[0];
  p->path_2[1] = point->path_2[1];
  p->path_3[0] = point->path_3[0];
  p->path_3[1] = point->path_3[1];
  p->next = NULL;
  p->prev = NULL;
  return (p);
}

void		add_cpy_node(t_points **list, t_points *node)
{
  t_points	*tmp;

  tmp = cpy_node(node);
  if (!*list)
    *list = tmp;
  else
    {
      tmp->next = *list;
      *list = tmp;
    }
}

void		add_node(t_points **list, t_points *node)
{
  if (!*list)
    {
      *list = node;
    }
  else
    {
      node->next = *list;
      *list = node;
    }
}

t_points	*change_list(t_points *list)
{
  t_points	*it;
  t_points	*new_list;
  int		i;

  i = 0;
  it = list->next;
  new_list = NULL;
  while (it != list)
    {
      add_cpy_node(&new_list, it);
      new_list->index = i;
      it = it->next;
      ++i;
    }
  return (new_list);
}

void		print_node(t_points *list)
{
  while (list)
    {
      printf("node %d - %d %d\n", list->index, list->el.center.x, list->el.center.y);
      list = list->next;
    }
}

void		del_node(t_points **list, t_points *node)
{
  t_points	*prev;
  t_points	*save;

  if (!*list || !node)
    return ;
  if (cmp_node(*list, node))
    {
      prev = *list;
      *list = (*list)->next;
      free(prev);
      return ;
    }
  /* save = *list; */
  /* prev = *list; */
  /* while (*list) */
  /*   { */
  /*     if (cmp_node(*list, node)) */
  /* 	{ */
  /* 	  prev->next = (*list)->next; */
  /* 	  free(*list); */
  /* 	  break; */
  /* 	} */
  /*     prev = *list; */
  /*     *list = (*list)->next; */
  /*   } */
  /* *list = save; */
}

void		free_node(t_points *list)
{
  t_points	*tmp;

  while (list)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
  free(list);
}
