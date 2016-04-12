/*
** save_ini.c for save_ini in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Apr 12 23:37:30 2016 Paul Wery
** Last update Wed Apr 13 00:13:01 2016 Paul Wery
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "road.h"

void	write_nb(int nb, int fd)
{
  int	neg;

  neg = '-';
  if (nb < 0)
    {
      write(fd, &neg, 1);
      nb = nb * -1;
    }
  if (nb > 9)
    write_nb(nb / 10, fd);
  nb = nb % 10 + 48;
  write(fd, &nb, 1);
}

void	write_str(char *str, int fd)
{
  int	n;

  n = 0;
  while (str[n] != '\0')
    n += 1;
  write(fd, str, n);
}

void	write_full_elem(t_points *it, int fd)
{
  write_str("pos=", fd);
  write_nb(it->el.center.x, fd);
  write_str(",", fd);
  write_nb(it->el.center.y, fd);
  write_str("\n", fd);
  write_str("ellipse=", fd);
  write_nb(it->el.axe_a, fd);
  write_str(",", fd);
  write_nb(it->el.axe_b, fd);
  write_str("\n", fd);
  write_str("zone_morte=", fd);
  write_nb(it->el.zaxe_a, fd);
  write_str(",", fd);
  write_nb(it->el.zaxe_b, fd);
  write_str("\n", fd);
  write_str("path_0=", fd);
  write_nb(it->path_0[1].x, fd);
  write_str(",", fd);
  write_nb(it->path_0[1].y, fd);
  write_str("\n", fd);
  write_next(it, fd);
}

void	write_in_ini(t_road *r, int nb, int fd,
		     t_points *it)
{
  write_str("[number]\n", fd);
  write_str("nb_node=", fd);
  write_nb(nb, fd);
  write_str("\n\n", fd);
  nb = 0;
  while (it != r->list)
    {
      write_str("[node_", fd);
      write_nb(nb, fd);
      write_str("]\n", fd);
      write_full_elem(it, fd);
      it = it->next;
      nb += 1;
    }
}

int		save_ini(t_road *r)
{
  t_points	*it;
  int		nb;
  int		fd;

  nb = 0;
  it = r->list->next;
  while (it != r->list)
    {
      it = it->next;
      nb += 1;
    }
  if ((fd = open("ini/paths.ini", O_CREAT | O_APPEND | O_WRONLY
		 | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
    return (-1);
  it = r->list->next;
  write_in_ini(r, nb, fd, it);
  close(fd);
  return (0);
}
