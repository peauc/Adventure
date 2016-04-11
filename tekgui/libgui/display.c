/*
** display.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/demo
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 24 14:12:25 2016 Mathieu Sauvau
** Last update Sun Feb 28 21:28:43 2016 Mathieu Sauvau
*/

#include "tekgui.h"

void	display_button(t_bunny_pixelarray *pix_ar, t_button *button,
		       int nb_button)
{
  int	i;

  i = -1;
  if (button)
    while (++i < nb_button)
      gui_button(pix_ar, &button[i], button[i].texture_state);
}

void	display_img(t_bunny_pixelarray *pix_ar, t_img *img, int nb_img)
{
  int	i;

  i = -1;
  if (img)
    while (++i < nb_img)
      draw_img(pix_ar, &img[i], img[i].mode, pos_(0, 0));
}

void	display_checkbox(t_bunny_pixelarray *pix_ar, t_checkbox *checkbox,
			 int nb_checkbox)
{
  int	i;

  i = -1;
  if (checkbox)
    while (++i < nb_checkbox)
      gui_checkbox(pix_ar, &checkbox[i], checkbox[i].texture_state);
}

void	display_text(t_bunny_pixelarray *pix_ar, t_text *text,
		     int nb_text)
{
  int	i;

  i = -1;
  while (++i < nb_text)
    gui_text(pix_ar, &text[i]);
}

void	tekgui_display(t_bunny_pixelarray *pix_ar,
		       t_tekgui *gui)
{
  my_fill(gui->pix_ar, gui->bg_color);
  display_img(gui->pix_ar, gui->img, gui->nb_image);
  display_button(gui->pix_ar_gui, gui->button, gui->nb_button);
  display_checkbox(gui->pix_ar_gui, gui->checkbox, gui->nb_checkbox);
  display_text(gui->pix_ar_write, gui->text, gui->nb_text);
  my_blit(gui->pix_ar_gui, gui->pix_ar_write, pos_(0, 0));
  my_blit(pix_ar, gui->pix_ar_gui, pos_(0, 0));
}
