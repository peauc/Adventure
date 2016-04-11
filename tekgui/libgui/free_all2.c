/*
** free_all2.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/demo
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 24 13:51:48 2016 Mathieu Sauvau
** Last update Sun Feb 28 21:32:15 2016 Mathieu Sauvau
*/

#include "tekgui.h"

void			free_gui_texture(t_gui_texture *texture)
{
  bunny_free(texture->border);
  bunny_delete_clipable(&texture->texture->clipable);
}

void			free_texture_state(t_texture_state *texture_state)
{
  if (texture_state->normal)
    free_gui_texture(texture_state->normal);
  if (texture_state->on)
    free_gui_texture(texture_state->on);
  if (texture_state->over)
    free_gui_texture(texture_state->over);
  if (texture_state->over_on)
    free_gui_texture(texture_state->over_on);
  bunny_free(texture_state);
}

void			free_next(t_tekgui *gui)
{
  bunny_free(gui->img);
  bunny_free(gui->button);
  bunny_free(gui->checkbox);
  bunny_free(gui->text);
  bunny_free(gui);
  bunny_delete_clipable(&gui->pix_ar->clipable);
  bunny_delete_clipable(&gui->pix_ar_gui->clipable);
  bunny_delete_clipable(&gui->pix_ar_write->clipable);
  bunny_delete_clipable(&gui->font->clipable);
}
