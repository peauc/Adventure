/*
** node_helper.c for  in /home/sauvau_m/rendu/gfx_tekadventure/movement
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Apr 17 14:41:20 2016 Mathieu Sauvau
** Last update Sun Apr 17 18:25:53 2016 Mathieu Sauvau
*/

#include "tekadv.h"

bool			node_in_list(t_points *list, t_points *node)
{
  t_points		*it;

  it = list->next;
  while (it != list)
    {
      if (cmp_node(it, node))
	return (true);
      it = it->next;
    }
  return (false);
}

t_points	*get_node_byclick(t_points *node,
				  const t_bunny_position *pos)
{
  while (node)
    {
      if (pos->x >= (node->el.center.x - node->el.zaxe_a)
	  && pos->x <= (node->el.center.x + node->el.zaxe_a)
	  && pos->y >= (node->el.center.y - node->el.zaxe_b)
	  && pos->y <= (node->el.center.y + node->el.zaxe_b))
	  return (node);
      node = node->next;
    }
  return (NULL);
}

bool			cmp_node(t_points *node1, t_points *node2)
{
  if (!node1 || !node2)
    return (true);
  return (cmp_position(node1->el.center, node2->el.center));
}

t_points		*get_node_bycoord(t_points *list, t_bunny_position coord)
{
  while (list)
    {
      if (cmp_position(list->el.center, coord))
	return (list);
      list = list->next;
    }
  return (NULL);
}
