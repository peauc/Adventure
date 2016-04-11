/*
** free_all.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/demo
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 24 13:48:03 2016 Mathieu Sauvau
** Last update Sun Feb 28 21:33:05 2016 Mathieu Sauvau
*/

#include "tekgui.h"

void			free_button(t_button *button)
{
  bunny_free(button->rect);
  bunny_free(button->label);
  bunny_delete_clipable(&button->label_pix->clipable);
  free_texture_state(button->texture_state);
}

void			free_checkbox(t_checkbox *checkbox)
{
  bunny_free(checkbox->rect);
  bunny_free(checkbox->label);
  bunny_delete_clipable(&checkbox->label_pix->clipable);
  free_texture_state(checkbox->texture_state);
}

void			free_img(t_img *img)
{
  bunny_free(img->rect);
  bunny_free(img->label);
  bunny_delete_clipable(&img->label_pix->clipable);
  bunny_delete_clipable(img->img);
}

void		free_text(t_text *text)
{
  bunny_free(text->rect);
  bunny_free(text->txt);
  bunny_delete_clipable(&text->txt_pix->clipable);
}

void	free_all(t_tekgui *gui)
{
  int	i;

  i = -1;
  if (gui->button)
    while (++i < gui->nb_button)
      free_button(&gui->button[i]);
  i = -1;
  if (gui->checkbox)
    while (++i < gui->nb_checkbox)
      free_checkbox(&gui->checkbox[i]);
  i = -1;
  if (gui->img)
    while (++i < gui->nb_image)
      free_img(&gui->img[i]);
  i = -1;
  if (gui->text)
    while (++i < gui->nb_text)
      free_text(&gui->text[i]);
  free_next(gui);
  bunny_stop(gui->win);
}
