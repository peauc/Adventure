/*
** save_ini_next.c for save_ini_next in /home/wery_p/rendu/gfx_tekadventure/create_road
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Apr 13 00:02:03 2016 Paul Wery
** Last update Fri Apr 15 15:48:31 2016 Paul Wery
*/

#include <unistd.h>
#include "road.h"

void	write_w(t_points *it, int fd)
{
  write_str("nb_path=", fd);
  write_nb(it->path, fd);
  write_str("\n", fd);
  write_str("image=", fd);
  write_str(it->image, fd);
  write_str("\n", fd);
  write_str("\n", fd);
}

void	write_next(t_points *it, int fd)
{
  write_str("path_1=", fd);
  write_nb(it->path_1[1].x, fd);
  write_str(",", fd);
  write_nb(it->path_1[1].y, fd);
  write_str("\n", fd);
  write_str("path_2=", fd);
  write_nb(it->path_2[1].x, fd);
  write_str(",", fd);
  write_nb(it->path_2[1].y, fd);
  write_str("\n", fd);
  write_str("path_3=", fd);
  write_nb(it->path_3[1].x, fd);
  write_str(",", fd);
  write_nb(it->path_3[1].y, fd);
  write_str("\n", fd);
  write_w(it, fd);
}
