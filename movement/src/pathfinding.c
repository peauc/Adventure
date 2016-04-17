/*
** pathfinding.c for  in /home/sauvau_m/rendu/gfx_tekadventure/movement
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Apr 17 14:49:20 2016 Mathieu Sauvau
** Last update Sun Apr 17 15:07:15 2016 Mathieu Sauvau
*/

#include "tekadv.h"

t_points		*construct_path(t_dict *came_from,
					t_points *start, t_points *dest)
{
  t_points		*path;
  t_points		*current;

  current = look_up(came_from, dest->index);
  path = NULL;
  add_cpy_node(&path, dest);
  add_cpy_node(&path, current);
  printf("CURRENT %d %d\n", current->el.center.x, current->el.center.y);
  printf("start %d %d\n", start->el.center.x, start->el.center.y);
  printf("path %d %d\n", path->el.center.x, path->el.center.y);
  while (!cmp_node(current, start))
    {
      current = look_up(came_from, current->index);
      printf("CURRENT %d %d\n", current->el.center.x, current->el.center.y);
      add_cpy_node(&path, current);
    }
  return (path);
}

void			check_last(t_points *list, t_dict **came_from,
				   t_points *frontier, t_points *current)
{
  t_points		*neighbor;

  if ((neighbor = get_node_bycoord(list, current->path_2[1])) != NULL
      && !is_in_dict(*came_from, neighbor->index))
    {
      printf("ADD TO FRONTIER PATH 2 %d %d\n", neighbor->el.center.x, neighbor->el.center.y);
      add_cpy_node(&frontier, neighbor);
      add_dict(came_from, new_entry(neighbor->index, current));
    }
  if ((neighbor = get_node_bycoord(list, current->path_3[1])) != NULL
      && !is_in_dict(*came_from, neighbor->index))
    {
      printf("ADD TO FRONTIER PATH 3 %d %d\n", neighbor->el.center.x, neighbor->el.center.y);
      add_cpy_node(&frontier, neighbor);
      add_dict(came_from, new_entry(neighbor->index, current));
    }
}

void			check_all_path(t_points *list, t_dict **came_from,
				       t_points *frontier, t_points *current)
{
  t_points		*neighbor;

  if ((neighbor = get_node_bycoord(list, current->path_0[1])) != NULL
      && !is_in_dict(*came_from, neighbor->index))
    {
      printf("ADD TO FRONTIER PATH 0 %d %d\n", neighbor->el.center.x, neighbor->el.center.y);
      add_cpy_node(&frontier, neighbor);
      add_dict(came_from, new_entry(neighbor->index, current));
    }
  if ((neighbor = get_node_bycoord(list, current->path_1[1])) != NULL
      && !is_in_dict(*came_from, neighbor->index))
    {
      printf("ADD TO FRONTIER PATH 1 %d %d\n", neighbor->el.center.x, neighbor->el.center.y);
      add_cpy_node(&frontier, neighbor);
      add_dict(came_from, new_entry(neighbor->index, current));
    }
  check_last(list, came_from, frontier, current);
}

t_dict			*find_way(t_points *list, t_points *start, t_points *dest)
{
  t_dict		*came_from;
  t_points		*current;
  t_points		*frontier;

  if (dest == NULL || cmp_node(start, dest))
    return (NULL);
  came_from = NULL;
  frontier = NULL;
  add_cpy_node(&frontier, start);
  add_dict(&came_from, new_entry(start->index, NULL));
  print_dict(came_from);
  printf("start center %d %d\n", start->el.center.x, start->el.center.y);
  printf("dest center %d %d\n", dest->el.center.x, dest->el.center.y);
  while (frontier)
    {
      current = cpy_node(frontier);
      del_node(&frontier, current);
      printf("current %d %d\n", current->el.center.x, current->el.center.y);
      if (cmp_node(current, dest))
      	{
      	  printf("BREAK\n");
      	  break;
      	}
      check_all_path(list, &came_from, frontier, current);
    }
  print_dict(came_from);
  return (came_from);
}
