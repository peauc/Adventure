/*
** delete_links.c for delete_links in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Apr 11 21:47:28 2016 Paul Wery
** Last update Mon Apr 11 22:34:28 2016 Paul Wery
*/

#include "road.h"

int	comp_path(t_bunny_position *path, t_points *elem)
{
  if (path[1].x == elem->el.center.x
      && path[1].y == elem->el.center.y)
    return (1);
  return (0);
}

void	browse_paths_two(t_points *it, t_points *elem)
{
  if (comp_path(it->path_2, elem) == 1)
    {
      it->path_2[0].x = it->path_3[0].x;
      it->path_2[0].y = it->path_3[0].y;
      it->path_2[1].x = it->path_3[1].x;
      it->path_2[1].y = it->path_3[1].y;
      it->path_3[0].x = -1;
      it->path_3[0].y = -1;
      it->path_3[1].x = -1;
      it->path_3[1].y = -1;
      it->path -= 1;
    }
  else if (comp_path(it->path_3, elem) == 1)
    {
      it->path_3[0].x = -1;
      it->path_3[0].y = -1;
      it->path_3[1].x = -1;
      it->path_3[1].y = -1;
      it->path -= 1;
    }
}

void	browse_paths_one(t_points *it, t_points *elem)
{
  if (comp_path(it->path_1, elem) == 1)
    {
      it->path_1[0].x = it->path_2[0].x;
      it->path_1[0].y = it->path_2[0].y;
      it->path_1[1].x = it->path_2[1].x;
      it->path_1[1].y = it->path_2[1].y;
      it->path_2[0].x = it->path_3[0].x;
      it->path_2[0].y = it->path_3[0].y;
      it->path_2[1].x = it->path_3[1].x;
      it->path_2[1].y = it->path_3[1].y;
      it->path_3[0].x = -1;
      it->path_3[0].y = -1;
      it->path_3[1].x = -1;
      it->path_3[1].y = -1;
      it->path -= 1;
    }
  else
    browse_paths_two(it, elem);
}

void	browse_paths(t_points *it, t_points *elem)
{
  if (comp_path(it->path_0, elem) == 1)
    {
      it->path_0[0].x = it->path_1[0].x;
      it->path_0[0].y = it->path_1[0].y;
      it->path_0[1].x = it->path_1[1].x;
      it->path_0[1].y = it->path_1[1].y;
      it->path_1[0].x = it->path_2[0].x;
      it->path_1[0].y = it->path_2[0].y;
      it->path_1[1].x = it->path_2[1].x;
      it->path_1[1].y = it->path_2[1].y;
      it->path_2[0].x = it->path_3[0].x;
      it->path_2[0].y = it->path_3[0].y;
      it->path_2[1].x = it->path_3[1].x;
      it->path_2[1].y = it->path_3[1].y;
      it->path_3[0].x = -1;
      it->path_3[0].y = -1;
      it->path_3[1].x = -1;
      it->path_3[1].y = -1;
      it->path -= 1;
    }
  else
    browse_paths_one(it, elem);
}

void		delete_links(t_points *list, t_points *elem)
{
  t_points	*it;

  it = list->next;
  while (it != list)
    {
      if (it != elem)
	browse_paths(it, elem);
      it = it->next;
    }
}
