/*
** config_ram.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/libgui
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Feb 28 16:00:48 2016 Mathieu Sauvau
** Last update Sun Feb 28 20:45:49 2016 Mathieu Sauvau
*/

#include <tekgui.h>

t_border		*load_border(t_bunny_ini *ini, char *scope)
{
  t_border		*border;

  if ((border = bunny_malloc(sizeof(t_border))) == NULL)
      return (NULL);
  border->left = field_to_int(ini, scope, "texture_border", 0);
  border->top = field_to_int(ini, scope, "texture_border", 1);
  border->right = field_to_int(ini, scope, "texture_border", 2);
  border->bottom = field_to_int(ini, scope, "texture_border", 3);
  return (border);
}

void		load_config_ram()
{
  t_bunny_ini	*ini;
  int		ram;

  if ((ini = bunny_load_ini("configuration.ini")) == NULL
      || (ram = field_to_int(ini, "", "max_ram", 0)) != 0)
    bunny_set_maximum_ram(ram);
  else
    bunny_set_maximum_ram(1500000);
  bunny_delete_ini(ini);
}
