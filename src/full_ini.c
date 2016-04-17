/*
** full_ini.c for full_ini in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Apr 12 01:28:11 2016 Paul Wery
** Last update Sun Apr 17 22:05:13 2016 Paul Wery
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "road.h"

int		full_elem_c(t_bunny_ini *ini, const char *scope,
			    t_points *it, const char *elem)
{
  if ((elem = bunny_ini_get_field(ini, scope, "path_2", 0)) == NULL)
    return (-1);
  it->path_2[0].x = it->el.center.x;
  it->path_2[0].y = it->el.center.y;
  it->path_2[1].x = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "path_2", 1)) == NULL)
    return (-1);
  it->path_2[1].y = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "path_3", 0)) == NULL)
    return (-1);
  it->path_3[0].x = it->el.center.x;
  it->path_3[0].y = it->el.center.y;
  it->path_3[1].x = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "path_3", 1)) == NULL)
    return (-1);
  it->path_3[1].y = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "nb_path", 0)) == NULL)
    return (-1);
  it->path = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "image", 0)) == NULL)
    return (-1);
  it->image = (char*)elem;
  return (0);
}

int		full_elem_b(t_bunny_ini *ini, const char *scope,
			    t_points *it, const char *elem)
{
  if ((elem = bunny_ini_get_field(ini, scope, "path_0", 0)) == NULL)
    return (-1);
  it->path_0[0].x = it->el.center.x;
  it->path_0[0].y = it->el.center.y;
  it->path_0[1].x = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "path_0", 1)) == NULL)
    return (-1);
  it->path_0[1].y = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "path_1", 0)) == NULL)
    return (-1);
  it->path_1[0].x = it->el.center.x;
  it->path_1[0].y = it->el.center.y;
  it->path_1[1].x = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "path_1", 1)) == NULL)
    return (-1);
  it->path_1[1].y = get_nb(elem, 0, 0, 0);
  if (full_elem_c(ini, scope, it, elem) == -1)
    return (-1);
  return (0);
}

int		full_elem(t_bunny_ini *ini, const char *scope,
			  t_points *it)
{
  const char	*elem;

  if ((elem = bunny_ini_get_field(ini, scope, "pos", 0)) == NULL)
    return (-1);
  it->el.center.x = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "pos", 1)) == NULL)
    return (-1);
  it->el.center.y = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "ellipse", 0)) == NULL)
    return (-1);
  it->el.axe_a = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "ellipse", 1)) == NULL)
    return (-1);
  it->el.axe_b = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "zone_morte", 0)) == NULL)
    return (-1);
  it->el.zaxe_a = get_nb(elem, 0, 0, 0);
  if ((elem = bunny_ini_get_field(ini, scope, "zone_morte", 1)) == NULL)
    return (-1);
  it->el.zaxe_b = get_nb(elem, 0, 0, 0);
  if (full_elem_b(ini, scope, it, elem) == -1)
    return (-1);
  return (0);
}

int		ok(t_bunny_ini *ini,
		   const char *scope,
		   char *name)
{
  const char	*elem;

  if ((elem = bunny_ini_get_field(ini, scope, "image", 0)) == NULL)
    return (-1);
  if (same_name(name, (char*)elem) == 1)
    return (1);
  return (0);
}

int			full_ini(t_points *list, char *name)
{
  t_points		it;
  t_bunny_ini		*ini;
  t_bunny_ini_scope	*scope;
  const char		*scope_name;
  int			fd;

  if ((fd = open("paths.ini", O_CREAT | O_APPEND | O_WRONLY,
		 S_IRUSR | S_IWUSR)) == -1)
    return (-1);
  close(fd);
  if ((ini = bunny_load_ini("paths.ini")) == NULL)
    return (-1);
  scope = bunny_ini_first(ini);
  while ((scope = bunny_ini_next(ini, scope)) != NULL)
    {
      scope_name = bunny_ini_scope_name(ini, scope);
      if (comp_string("node_", (char*)scope_name) == 1
	  && ok(ini, scope_name, name) == 1)
	{
	  if (full_elem(ini, scope_name, &it) == -1)
	    return (-1);
	  add_elem_next(list, &it);
	}
    }
  return (0);
}
