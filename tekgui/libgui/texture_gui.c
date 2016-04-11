/*
** texture_gui.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/libgui
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 17 09:16:11 2016 Mathieu Sauvau
** Last update Wed Feb 24 16:08:27 2016 Mathieu Sauvau
*/

#include <stdlib.h>
#include <lapin.h>
#include "libgui.h"

t_texture_state	     *define_textures(t_gui_texture *normal,
				      t_gui_texture *over,
				      t_gui_texture *on,
				      t_gui_texture *over_on)
{
  t_texture_state *textures;

  if ((textures = bunny_malloc(sizeof(t_texture_state))) == NULL)
    return (NULL);
  textures->normal = normal;
  textures->over = over;
  textures->on = on;
  textures->over_on = over_on;
  return (textures);
}

t_gui_texture	*new_gui_texture(t_border *border,
				 char *file_texture)
{
  t_gui_texture *texture;

  if ((texture = bunny_malloc(sizeof(t_gui_texture))) == NULL ||
      (texture->texture = bunny_load_pixelarray(file_texture)) == NULL)
    return (NULL);
  texture->border = border;
  return (texture);
}

t_border	*new_border(int top, int left, int right, int bottom)
{
  t_border	*border;

  if ((border = bunny_malloc(sizeof(border))) == NULL)
    return (NULL);
  border->top = top;
  border->left = left;
  border->right = right;
  border->bottom = bottom;
  return (border);
}
