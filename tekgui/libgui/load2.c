/*
** load2.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/demo
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 24 14:50:21 2016 Mathieu Sauvau
** Last update Sun Feb 28 14:52:49 2016 Mathieu Sauvau
*/

#include "tekgui.h"
#include "helper.h"

int			field_to_int(t_bunny_ini *ini, char *scope, char *field, int i)
{
  char			*tmp;
  int			r;

  if ((tmp = my_strdup((char *)BIGF(ini, scope, field, i))) == NULL)
    return (0);
  r = my_getnbr(tmp);
  bunny_free(tmp);
  return (r);
}

unsigned int	hex2int(char *hex, int len)
{
  int		i;
  unsigned long r = 0;

  i = -1;
  while (++i < len)
    {
      if (hex[i] <= 57)
	r += (hex[i] - 48) * (1 << (4 * ( len - 1 - i)));
      else
	r += (hex[i] - 55) * (1 << (4 * (len - 1 - i)));
    }
  return (r);
}

unsigned int	field_to_color(t_bunny_ini *ini,
			       char *scope, char *field, int i)
{
  char		*tmp;
  int		r;

  if ((tmp = my_strdup((char *)BIGF(ini, scope, field, i))) == NULL)
    return (0);
  r = hex2int(tmp, 8);
  bunny_free(tmp);
  return (r);
}

t_rect			*load_rect(t_bunny_ini *ini, char *scope)
{
  t_rect		*rect;

  if ((rect = bunny_malloc (sizeof(t_rect))) == NULL)
    return (NULL);
  rect->pos.x = field_to_int(ini, scope, "pos", 0);
  rect->pos.y = field_to_int(ini, scope, "pos", 1);
  rect->size.x = field_to_int(ini, scope, "size", 0);
  rect->size.y = field_to_int(ini, scope, "size", 1);
  rect->color = field_to_color(ini, scope, "color", 0);
  rect->mouse_over = false;
  return (rect);
}
